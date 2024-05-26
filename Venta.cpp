class Venta {
private:
    Bodega& bodega;
    double total;

public:
    Venta(Bodega& bodega) : bodega(bodega), total(0) {}

    void agregarProducto(std::string id, int cantidad) {
        Producto* producto = bodega.buscarProductoPorID(id);
        if (producto != nullptr && producto->getCantidad() >= cantidad) {
            producto->setCantidad(producto->getCantidad() - cantidad);
            total += producto->getPrecio() * cantidad;
        } else {
            std::cerr << "producto no disponible o insuficiente\n";
        }
    }

    double generarBoleta() {
        double totalAPagar = total;
        total = 0;
        return totalAPagar;
    }
};
