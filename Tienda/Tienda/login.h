#pragma once

#include <vector>
#include <string>

class Usuario {
public:
    std::string nombreUsuario;
    std::string contrasena;

    Usuario(std::string u, std::string c) : nombreUsuario(u), contrasena(c) {}
};

std::vector<Usuario> cargarUsuarios();
void guardarUsuarios(const std::vector<Usuario>& usuarios);
bool registrarUsuario(std::vector<Usuario>& usuarios);
bool loginUsuario(const std::vector<Usuario>& usuarios, std::string& usuarioLogueado);

