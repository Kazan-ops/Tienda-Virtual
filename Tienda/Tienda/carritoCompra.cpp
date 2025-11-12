
#include "CarritoCompra.h"
#include <iostream>
using namespace std;

bool CarritoCompra::agregarItem(const Producto& producto, int cantidad) {
    int totalUnidades = 0;

    for (const auto& item : items) {
        totalUnidades += item.getCantidad();
    }

    
    if (totalUnidades + cantidad > MAX_UNIDADES) {
        std::cout << "\n  No puedes agregar más de " << MAX_UNIDADES
            << " unidades en total al carrito.\n";
        return false; 
    }

    
    for (auto& item : items) {
        if (item.getProducto().getIdProducto() == producto.getIdProducto()) {
            item.setCantidad(item.getCantidad() + cantidad);
            calcularTotal();
            std::cout << "\nSe agregaron " << cantidad
                << " unidades más de '" << producto.getNombre() << "'.\n";
            return true;
        }
    }

    
    items.push_back(ItemCarrito(producto, cantidad));
    calcularTotal();
    std::cout << "\nProducto '" << producto.getNombre() << "' agregado al carrito.\n";

    return true;
}



bool CarritoCompra::eliminarItem(int idProducto, int cantidadEliminar) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getProducto().getIdProducto() == idProducto) {
            if (cantidadEliminar >= it->getCantidad()) {
                cout << "Se eliminaron todas las unidades de '"
                    << it->getProducto().getNombre() << "' del carrito.\n";
                items.erase(it);
            }
            else {
                it->setCantidad(it->getCantidad() - cantidadEliminar);
                cout << "Se eliminaron " << cantidadEliminar
                    << " unidades de '" << it->getProducto().getNombre() << "'.\n";
            }
            calcularTotal();
            return true;
        }
    }
    cout << "No se encontró el producto en el carrito.\n";
    return false;
}

void CarritoCompra::calcularTotal() {
    total = 0;
    for (const auto& item : items)
        total += item.calcularSubtotal();
}

double CarritoCompra::getTotal() const {
    return total;
}

void CarritoCompra::mostrarCarrito() const {
    if (items.empty()) {
        cout << "\nEl carrito está vacío.\n";
        return;
    }

    cout << "\n=== Carrito de Compras ===\n";
    for (const auto& item : items) {
        cout << "ID: " << item.getProducto().getIdProducto() << " | "
            << "Producto: " << item.getProducto().getNombre() << " | "
            << "Cantidad: " << item.getCantidad() << " | "
            << "Precio unitario: ?" << item.getProducto().getPrecio() << " | "
            << "Subtotal: ?" << item.calcularSubtotal() << "\n";
    }
    cout << "-----------------------------\n";
    cout << "Total: ?" << getTotal() << "\n";
}

void CarritoCompra::vaciarCarrito() {
    items.clear();
    cout << "\nEl carrito ha sido vaciado.\n";
}

bool CarritoCompra::estaVacio() const {
    return items.empty();
}