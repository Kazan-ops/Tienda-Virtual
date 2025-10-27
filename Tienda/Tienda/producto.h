#pragma once
#include <string>
using namespace std;

class Producto {
private:
    int idProducto;
    string nombre;
    string descripcion;
    double precio;
    int stock;

public:
    Producto(int idProducto, string nombre, string descripcion, double precio, int stock);

    int getIdProducto() const;
    string getNombre() const;
    string getDescripcion() const;
    double getPrecio() const;
    int getStock() const;

    void actualizarStock(int cantidad); 
    void mostrarInfo() const;          
};
