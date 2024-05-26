class NodoProducto {
public:
    Producto* producto;
    NodoProducto* siguiente;

    NodoProducto(Producto* producto) : producto(producto), siguiente(nullptr) {}
};

class ListaProductos {
private:
    NodoProducto* cabeza;

public:
    ListaProductos() : cabeza(nullptr) {}

    void agregarProducto(Producto* producto) {
        NodoProducto* nuevoNodo = new NodoProducto(producto);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    Producto* buscarProductoPorID(std::string id) {
        NodoProducto* actual = cabeza;
        while (actual != nullptr) {
            if (actual->producto->getId() == id) {
                return actual->producto;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

    ~ListaProductos() {
        while (cabeza != nullptr) {
            NodoProducto* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp->producto;
            delete temp;
        }
    }
};
