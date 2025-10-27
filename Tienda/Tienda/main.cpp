#include <iostream>
#include "Producto.h"
using namespace std;

int main() {

	//Esto es solo un ejemplo, pueden borrarlo y crear sus propias pruebas para continuar con el desarrollo 
    Producto camisa(1, "Camisa Casual", "Camisa de algodon, talla M", 18000.0, 15);
    camisa.mostrarInfo();

    cout << "\nVendiendo 3 unidades..." << endl;
    camisa.actualizarStock(3);
    camisa.mostrarInfo();

    cout << "\nIntentando vender 20 unidades..." << endl;
    camisa.actualizarStock(20);
    camisa.mostrarInfo();

    return 0;
}
