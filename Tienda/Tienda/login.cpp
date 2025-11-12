#include "login.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<Usuario> cargarUsuarios() {
    vector<Usuario> usuarios;
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir 'usuarios.txt'. Creando archivo vacio." << endl;
        return usuarios;
    }

    string u, c;
    while (std::getline(archivo, u)) {
        if (std::getline(archivo, c)) {
            usuarios.push_back(Usuario(u, c));
        }
        else {
            cout << "Advertencia: Usuario '" << u << "' sin contraseña en el archivo. Ignorado." << endl;
        }
    }
    archivo.close();
    return usuarios;
}

void guardarUsuarios(const vector<Usuario>& usuarios) {
    ofstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir 'usuarios.txt' para guardar." << endl;
        return;
    }
    for (const auto& user : usuarios) {
        archivo << user.nombreUsuario << endl;
        archivo << user.contrasena << endl;
    }
    archivo.close();
}

bool registrarUsuario(vector<Usuario>& usuarios) {
    string usuario, contrasena;
    cout << "Registro de usuario:" << endl;
    cout << "Elige un nombre de usuario: ";
    cin >> usuario;
    cout << "Elige una contrasenna: ";
    cin >> contrasena;

    for (const auto& u : usuarios) {
        if (u.nombreUsuario == usuario) {
            cout << "El nombre de usuario ya existe. Intenta con otro." << endl;
            return false;
        }
    }

    usuarios.push_back(Usuario(usuario, contrasena));
    guardarUsuarios(usuarios);
    cout << "Usuario registrado exitosamente." << endl;
    return true;
}

bool loginUsuario(const vector<Usuario>& usuarios, string& usuarioLogueado) {
    string usuario, contrasena;
    cout << "Login:" << endl;
    cout << "Nombre de usuario: ";
    cin >> usuario;
    cout << "Contrasenna: ";
    cin >> contrasena;

    for (const auto& u : usuarios) {
        if (u.nombreUsuario == usuario && u.contrasena == contrasena) {
            usuarioLogueado = usuario;
            cout << "Login exitoso. Bienvenido, " << usuario << "!" << endl;
            return true;
        }
    }
    cout << "Credenciales incorrectas." << endl;
    return false;
}