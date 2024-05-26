class Bodega {
private:
    ListaProductos listaProductos;

public:
    void cargarProductosDesdeArchivo(const std::string& nombreArchivo) {
        // Implementar la lectura del archivo y cargar los productos
    }

    void guardarProductosEnArchivo(const std::string& nombreArchivo) {
        // Implementar la escritura de los productos en el archivo
    }

    void agregarProducto(Producto* producto) {
        listaProductos.agregarProducto(producto);
    }

    Producto* buscarProductoPorID(std::string id) {
        return listaProductos.buscarProductoPorID(id);
    }
};
