#pragma once
#include <vector>
#include "ItemCarrito.h"
constexpr auto MAX_UNIDADES = 15;

class CarritoCompra {
private:
    vector<ItemCarrito> items;
    double total;

public:
    bool agregarItem(const Producto& producto, int cantidad);
    bool eliminarItem(int idProducto, int cantidadEliminar);
    void calcularTotal();
    double getTotal() const;
    void mostrarCarrito() const;
    void vaciarCarrito();
    void mostrarFactura(const string& metodoPago) const;
    bool estaVacio() const;
};