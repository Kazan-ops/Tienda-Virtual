#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pago {
	private:
	string metodo; 
	double monto;
	string estado;

public:
	Pago();
	Pago(const string& metodo, double monto);

	bool procesarPago();
	void mostrarPago() const;

	double getMonto() const;
	string getMetodo() const;
	string getEstado() const;
	void setMonto(double monto);
	void setMetodo(const string& metodo);
};