#include <iostream>
#include <vector>
#include <string>
#include "login.h"
#include "Inventario.h"
#include "Producto.h"
#include "carritoCompra.h"
#include "pago.h"
#include "checkout.h"
#include <cstdlib>

void limpiarPantalla() {
    system("cls"); 
}

void pausar() {
    system("pause");
}

using namespace std;

int main() {
    vector<Usuario> usuarios = cargarUsuarios();
    string usuarioLogueado;
    Inventario inventario;
    CarritoCompra carrito; 
   
    inventario.agregarProducto(Producto(1, "Camisa blanca", "Camisa de algodón talla M", 18000, 10));
    inventario.agregarProducto(Producto(2, "Pantalón jeans", "Pantalón azul clásico", 25000, 8));
    inventario.agregarProducto(Producto(3, "Gorra negra", "Gorra ajustable con logo", 8000, 20));
	inventario.agregarProducto(Producto(4, "Zapatos deportivos", "Zapatos cómodos para correr", 45000, 5));
	inventario.agregarProducto(Producto(5, "Chaqueta de cuero", "Chaqueta elegante de cuero sintético", 60000, 3));
	inventario.agregarProducto(Producto(6, "Vestido veraniego", "Vestido ligero para el verano", 30000, 7));
	inventario.agregarProducto(Producto(7, "medias Jordan", "medias para deportes Jordan", 55000, 4));
	inventario.agregarProducto(Producto(8, "sueter Addidas", "Sueter de cuero resistente al agua", 75000, 6));
	inventario.agregarProducto(Producto(9, "boxer Tommy", "Boxer estirante Tommy", 120000, 2));
	inventario.agregarProducto(Producto(10, "pantalon de cuero", "pantalon de cuero ancho", 90000, 9));
	inventario.agregarProducto(Producto(11, "camiseta nike", "camiseta deportiva nike", 40000, 15));
	inventario.agregarProducto(Producto(12, "camisa sin mangas ", "camisa sin mangas floja", 110000, 5));
	inventario.agregarProducto(Producto(13, "falda corta", "falda corta de mezclilla", 35000, 12)); 
	inventario.agregarProducto(Producto(14, "blusa elegante", "blusa elegante de seda", 95000, 4));
	inventario.agregarProducto(Producto(15, "shorts deportivos", "shorts cómodos para hacer ejercicio", 28000, 10));
	inventario.agregarProducto(Producto(16, "bufanda de lana", "bufanda cálida de lana", 22000, 14));
	inventario.agregarProducto(Producto(17, "guantes táctiles", "guantes que permiten usar pantallas táctiles", 15000, 18));
	inventario.agregarProducto(Producto(18, "licra de mujer", "licra larga para mujer", 120000, 7));
	inventario.agregarProducto(Producto(19, "polo deportivo", "polo transpirable para deportes", 50000, 11));
	inventario.agregarProducto(Producto(20, "chaleco reflectante", "chaleco para correr de noche", 30000, 9));
   

    int opcion = 0;
    bool logueado = false;

    do {
        cout << "\n=== TIENDA VIRTUAL ===\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Registrar usuario\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            logueado = loginUsuario(usuarios, usuarioLogueado);
            break;
        case 2:
            registrarUsuario(usuarios);
            break;
        case 3:
            cout << "Saliendo del sistema...\n";
            return 0;
        default:
            cout << "Opción inválida.\n";
        }

        
        while (logueado) {
            pausar();
            limpiarPantalla();
            int subopcion;
            cout << "\n=== MENÚ PRINCIPAL ===\n";
            cout << "Usuario: " << usuarioLogueado << endl;
            cout << "1. Ver catálogo de productos\n";
            cout << "2. Agregar producto al carrito\n";
            cout << "3. Ver carrito\n";
            cout << "4. Realizar pago\n";
            cout << "5. Cerrar sesión\n";
            cout << "Seleccione una opción: ";
            cin >> subopcion;

            if (subopcion == 1) {
                inventario.mostrarInventario();
              
            }
            else if (subopcion == 2) {
                int id, cantidad;
                inventario.mostrarInventario();
                cout << "\nIngrese el ID del producto a agregar: ";
                cin >> id;
                cout << "Cantidad: ";
                cin >> cantidad;
              

                Producto* producto = inventario.buscarProducto(id);
                if (producto != nullptr && producto->getStock() >= cantidad) {
                    carrito.agregarItem(*producto, cantidad);
                    inventario.actualizarStock(id, -cantidad);
                    cout << "\nProducto agregado al carrito.\n";
                }
                else {
                    cout << "\nNo hay suficiente stock o producto no encontrado.\n";
                }
            }
            else if (subopcion == 3) {
                carrito.mostrarCarrito();
              
            }
            else if (subopcion == 4) {
                if (carrito.estaVacio()) {
                    cout << "\nEl carrito está vacío.\n";
                } else {
                    double total = carrito.getTotal();
                    cout << "\nTotal a pagar: ₡" << total << endl;
                    
                    string metodo;
                    cout << "Ingrese método de pago (tarjeta / efectivo): ";
                    cin >> metodo;

                    Pago pago(metodo, total);
                    pago.procesarPago();

                    cout << "\nCompra completada con éxito. ¡Gracias por su compra!\n";
                    carrito.vaciarCarrito();
                }
            }
            else if (subopcion == 5) {
                cout << "Cerrando sesión...\n";
                logueado = false;
            }
            else {
                cout << "Opción inválida.\n";
            }
        }

    } while (opcion != 3);

    return 0;
}