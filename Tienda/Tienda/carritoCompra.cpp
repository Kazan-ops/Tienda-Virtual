#include "CarritoCompra.h"
#include <iostream>
using namespace std;

void CarritoCompra::agregarItem(const Producto& producto, int cantidad) {
    items.emplace_back(producto, cantidad);
    calcularTotal();
}

void CarritoCompra::eliminarItem(int idProducto) {
    items.erase(remove_if(items.begin(), items.end(),
        [idProducto](const ItemCarrito& item) {
            return item.getProducto().getIdProducto() == idProducto;
        }), items.end());
    calcularTotal();
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
    cout << "=== Carrito de compra ===" << endl;
    for (const auto& item : items) {
        cout << item.getProducto().getNombre() << " x" << item.getCantidad()
            << " = " << item.calcularSubtotal() << endl;
    }
    cout << "Total: " << total << endl;
}