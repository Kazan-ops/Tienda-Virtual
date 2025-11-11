#include "pago.h"
#include <iostream>
using namespace std;

Pago::Pago() : metodo("Desconocido"), monto(0.0), estado("Pendiente") {
} 
Pago::Pago(const string& metodo, double monto)
	: metodo(metodo), monto(monto), estado("Pendiente") {
}
bool Pago::procesarPago() {

	cout << "Procesando pago de $" << monto << " mediante " << metodo << "..." << endl;
	if (monto > 0) {
		estado = "Aprobado";
		return true;
	}
	else {
		estado = "Rechazado";
		return false;
	}
}
	void Pago::mostrarPago() const {
		cout << "Metodo de Pago: " << metodo << endl;
		cout << "Monto: $" << monto << endl;
		cout << "Estado: " << estado << endl;
	}
	double Pago::getMonto() const {
		return monto;
	}
	string Pago::getMetodo() const {
		return metodo;
	}	
	string Pago::getEstado() const {
		return estado;
	}
	void Pago::setMonto(double monto) {
		this->monto = monto;
	}
	void Pago::setMetodo(const string& metodo) {
		this->metodo = metodo;
	}