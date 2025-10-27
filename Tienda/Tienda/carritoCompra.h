#pragma once
#include <vector>
#include "ItemCarrito.h"

class CarritoCompra {
private:
    vector<ItemCarrito> items;
    double total;

public:
    void agregarItem(const Producto& producto, int cantidad);
    void eliminarItem(int idProducto);
    void calcularTotal();
    double getTotal() const;
    void mostrarCarrito() const;
};