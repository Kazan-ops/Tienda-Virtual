#pragma once
#include "producto.h"

class ItemCarrito {
private:
	Producto producto;
	int cantidad;

public:
	ItemCarrito(const Producto& prod, int cant);
	double calcularSubtotal() const;
	Producto getProducto() const;
	int getCantidad() const;
};
