#include <iostream>
#include <string>

class Cliente {
private:
    std::string tipo;
    std::string nombre;
    int numero;

public:
    Cliente(std::string tipo, std::string nombre, int numero)
        : tipo(tipo), nombre(nombre), numero(numero) {}

    std::string getTipo() { return tipo; }
    std::string getNombre() { return nombre; }
    int getNumero() { return numero; }
};
