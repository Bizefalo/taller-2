#include <iostream>

void mostrarMenu() {
    std::cout << "1. Agregar cliente\n";
    std::cout << "2. Atender cliente\n";
    std::cout << "3. Agregar producto a bodega\n";
    std::cout << "4. Generar venta\n";
    std::cout << "5. Guardar y salir\n";
}

int main() {
    Bodega bodega;
    ColaClientes colaClientes;

    bodega.cargarProductosDesdeArchivo("bodega.txt");

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string tipo, nombre;
                int numero;
                std::cout << "Ingrese tipo de cliente: ";
                std::cin >> tipo;
                std::cout << "Ingrese nombre de cliente: ";
                std::cin >> nombre;
                std::cout << "Ingrese numero de cliente: ";
                std::cin >> numero;
                Cliente* cliente = new Cliente(tipo, nombre, numero);
                colaClientes.agregarCliente(cliente);
                break;
            }
            case 2: {
                Cliente* cliente = colaClientes.siguienteCliente();
                if (cliente != nullptr) {
                    std::cout << "Atendiendo a " << cliente->getNombre() << std::endl;
                    delete cliente;
                } else {
                    std::cout << "No hay clientes en la cola\n";
                }
                break;
            }
            case 3: {
                std::string id, categoria, subCategoria;
                double precio;
                int cantidad;
                std::cout << "Ingrese ID del producto: ";
                std::cin >> id;
                std::cout << "Ingrese categoria del producto: ";
                std::cin >> categoria;
                std::cout << "Ingrese sub-categoria del producto: ";
                std::cin >> subCategoria;
                std::cout << "Ingrese precio del producto: ";
                std::cin >> precio;
                std::cout << "Ingrese cantidad del producto: ";
                std::cin >> cantidad;
                Producto* producto = new Producto(id, categoria, subCategoria, precio, cantidad);
                bodega.agregarProducto(producto);
                break;
            }
            case 4: {
                Venta venta(bodega);
                std::string id;
                int cantidad;
                char continuar;
                do {
                    std::cout << "Ingrese ID del producto: ";
                    std::cin >> id;
                    std::cout << "Ingrese cantidad del producto: ";
                    std::cin >> cantidad;
                    venta.agregarProducto(id, cantidad);
                    std::cout << "Desea agregar otro producto? (s/n): ";
                    std::cin >> continuar;
                } while (continuar == 's');
                double total = venta.generarBoleta();
                std::cout << "Total a pagar: " << total << std::endl;
                break;
            }
            case 5: {
                bodega.guardarProductosEnArchivo("bodega.txt");
                break;
            }
        }
    } while (opcion != 5);

    return 0;


    


}
