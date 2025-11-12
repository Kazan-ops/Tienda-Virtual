#pragma once
#include <vector>
#include "ItemCarrito.h"
#define MAX_UNIDADES 15

class CarritoCompra {
private:
    vector<ItemCarrito> items;
    double total;

public:
    void agregarItem(const Producto& producto, int cantidad);
    bool eliminarItem(int idProducto, int cantidadEliminar);
    void calcularTotal();
    double getTotal() const;
    void mostrarCarrito() const;
    void vaciarCarrito(); 
    bool estaVacio() const; 
};