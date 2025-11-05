#include "Inventario.h"
#include <iostream>
using namespace std;

void Inventario::agregarProducto(const Producto& producto) {
    productos.push_back(producto);
}

void Inventario::mostrarInventario() const {
    if (productos.empty()) {
        cout << "El inventario está vacío.\n";
        return;
    }

    cout << "---- Inventario de la Tienda ----" << endl;
    for (const auto& p : productos) {
        p.mostrarInfo();
    }
    cout << "---------------------------------\n";
}

Producto* Inventario::buscarProducto(int idProducto) {
    for (auto& p : productos) {
        if (p.getIdProducto() == idProducto)
            return &p;
    }
    return nullptr;
}

void Inventario::actualizarStock(int idProducto, int cantidadVendida) {
    Producto* p = buscarProducto(idProducto);
    if (p != nullptr) {
        p->actualizarStock(cantidadVendida);
    }
    else {
        cout << "Producto con ID " << idProducto << " no encontrado.\n";
    }
}
