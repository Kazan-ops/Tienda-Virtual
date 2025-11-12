#include "checkout.h"
#include <iostream>
#include <iomanip>

using namespace std;

Checkout::Checkout(const CarritoCompra& carrito, const Pago& metodoPago)
	: carrito(carrito), metodoPago(metodoPago) {
}
void Checkout::confirmarPedido() {
	cout << "Pedido confirmado. Gracias por su compra!" << endl;
}
void Checkout::generarFactura() {
	cout << fixed << setprecision(2);
	cout << "----- FACTURA -----" << endl;
	carrito.mostrarCarrito();
	cout << "Total a pagar: ₡" << carrito.getTotal() << endl;
	cout << "-------------------" << endl;
}
