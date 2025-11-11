#pragma once
#include "carritoCompra.h"
#include "pago.h"
#include <iostream>

class Checkout {
	private:
	CarritoCompra carrito;
	Pago metodoPago;

public:	
	Checkout(const CarritoCompra& carrito, const Pago& metodoPago);

	void confirmarPedido();
	void generarFactura(); 
};