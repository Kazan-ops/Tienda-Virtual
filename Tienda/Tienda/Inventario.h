#pragma once
#include <vector>
#include "Producto.h"
using namespace std;

class Inventario {
private:
    vector<Producto> productos;

public:

    void agregarProducto(const Producto& producto);

    Producto* buscarProducto(int idProducto);

    void actualizarStock(int idProducto, int cantidad);

    void mostrarInventario() const;
};
