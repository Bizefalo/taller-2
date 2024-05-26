#include <iostream>
#include <string>

class Producto {
private:
    std::string id;
    std::string categoria;
    std::string subCategoria;
    double precio;
    int cantidad;

public:
    Producto(std::string id, std::string categoria, std::string subCategoria, double precio, int cantidad)
        : id(id), categoria(categoria), subCategoria(subCategoria), precio(precio), cantidad(cantidad) {}

    std::string getId() { return id; }
    std::string getCategoria() { return categoria; }
    std::string getSubCategoria() { return subCategoria; }
    double getPrecio() { return precio; }
    int getCantidad() { return cantidad; }

    void setCantidad(int cantidad) { this->cantidad = cantidad; }
};
