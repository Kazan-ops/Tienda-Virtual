#include "Inventario.h"
#include <iostream>
using namespace std;

void Inventario::agregarProducto(const Producto& producto) {
    productos.push_back(producto);
}

Producto* Inventario::buscarProducto(int idProducto) {
    for (auto& p : productos) {
        if (p.getIdProducto() == idProducto) {
            return &p;
        }
    }
    return nullptr;
}

void Inventario::actualizarStock(int idProducto, int cantidad) {
    Producto* producto = buscarProducto(idProducto);
    if (producto != nullptr) {
        int stockActual = producto->getStock();

        if (cantidad < 0) {
            int cantidadAbs = -cantidad;
            if (cantidadAbs <= stockActual) {
                producto->actualizarStock(cantidadAbs);
                cout << " Venta realizada de " << cantidadAbs
                    << " unidad/s de " << producto->getNombre() << endl;
            }
            else {
                cout << " No hay suficiente stock de "
                    << producto->getNombre() << " (Stock actual: "
                    << stockActual << ")\n";
            }
        }
        else {
            producto->actualizarStock(-cantidad); 
            cout << " Stock aumentado de " << producto->getNombre()
                << ". Nuevo stock: " << producto->getStock() << endl;
        }
    }
    else {
        cout << " Producto no encontrado.\n";
    }
}

void Inventario::mostrarInventario() const {
    cout << "\n--- Inventario de la Tienda ---\n";
    for (const auto& p : productos) {
        p.mostrarInfo();
        cout << "-----------------------------\n";
    }
}
