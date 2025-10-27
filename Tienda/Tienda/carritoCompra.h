#pragma# once
#include <vector>
#include "Producto.h"  
#include "ItemCarrito.h"  

class CarritoCompra {
private:
    std::vector<ItemCarrito> items;
    double total;

public:
    CarritoCompra();
    void agregarItem(Producto p, int cantidad);
    void eliminarItem(int indice);
    void calcularTotal();
    double getTotal();
    void mostrarCarrito();
};


