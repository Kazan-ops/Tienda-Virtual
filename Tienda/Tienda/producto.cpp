#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto(int idProducto, string nombre, string descripcion, double precio, int stock)
    : idProducto(idProducto), nombre(nombre), descripcion(descripcion), precio(precio), stock(stock) {
}

int Producto::getIdProducto() const { return idProducto; }
string Producto::getNombre() const { return nombre; }
string Producto::getDescripcion() const { return descripcion; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

void Producto::actualizarStock(int cantidad) {
    if (cantidad <= stock) {
        stock -= cantidad;
    }
    else {
        cout << "No hay suficiente stock de " << nombre << "." << endl;
    }
}

void Producto::mostrarInfo() const {
    cout << "ID: " << idProducto
        << " | Nombre: " << nombre
        << " | Descripcion: " << descripcion
        << " | Precio: colones " << precio
        << " | Stock: " << stock << endl;
}
