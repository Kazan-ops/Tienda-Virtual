#include "ItemCarrito.h"

ItemCarrito::ItemCarrito(const Producto& prod, int cant)
	: producto(prod), cantidad(cant) {
}

double ItemCarrito::calcularSubtotal() const {
	return producto.getPrecio() * cantidad;
}

Producto ItemCarrito::getProducto() const {
	return producto;
}

int ItemCarrito::getCantidad() const {
	return cantidad;
}

