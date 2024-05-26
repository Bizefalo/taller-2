#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <list>
class Bodega {
private:
    ListaProductos listaProductos;

public:
    void cargarProductosDesdeArchivo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "error al abri el archivo: " << nombreArchivo << std::endl;
            return;
        }

        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string id, categoria, subCategoria, precioStr, cantidadStr;

            std::getline(ss, id, ',');
            std::getline(ss, categoria, ',');
            std::getline(ss, subCategoria, ',');
            std::getline(ss, precioStr, ',');
            std::getline(ss, cantidadStr, ',');

            double precio = std::stod(precioStr);
            int cantidad = std::stoi(cantidadStr);

            Producto* producto = new Producto(id, categoria, subCategoria, precio, cantidad);
            listaProductos.agregarProducto(producto);
        }

        archivo.close();
    }

    //-------------------------------------------------------------------------------------------------------------

    void guardarProductosEnArchivo(const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "error al abrir el archivo: " << nombreArchivo << std::endl;
            return;
        }

        NodoProducto* actual = listaProductos.cabeza;
        while (actual != nullptr) {
            Producto* producto = actual->producto;
            archivo << producto->getId() << ","
                    << producto->getCategoria() << ","
                    << producto->getSubCategoria() << ","
                    << producto->getPrecio() << ","
                    << producto->getCantidad() << "\n";
            actual = actual->siguiente;
        }

        archivo.close();
    }

    void agregarProducto(Producto* producto) {
        listaProductos.agregarProducto(producto);
    }

    Producto* buscarProductoPorID(std::string id) {
        return listaProductos.buscarProductoPorID(id);
    }
};
