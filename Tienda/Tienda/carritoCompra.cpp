#include "CarritoCompra.h"
#include <iostream>  

CarritoCompra::CarritoCompra() : total(0.0) {}

void CarritoCompra::agregarItem(Producto p, int cantidad) {
    ItemCarrito item(p, cantidad);
    items.push_back(item);
    calcularTotal();
}

void CarritoCompra::eliminarItem(int indice) {
    if (indice >= 0 && indice < static_cast<int>(items.size())) {
        items.erase(items.begin() + indice);
        calcularTotal();
    }
}

void CarritoCompra::calcularTotal() {
    total = 0.0;
    for (const auto& item : items) {
        total += item.getPrecioTotal(); 
    }
}

double CarritoCompra::getTotal() {
    return total;
}

void CarritoCompra::mostrarCarrito() {
    std::cout << "Contenido del carrito:" << std::endl;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << "Ítem " << i << ": ";
        
        items[i].mostrar();  
        std::cout << std::endl;
    }
    std::cout << "Total: " << total << std::endl;
}