#include <queue>
#include <list>

class ColaClientes {
private:
    std::queue<Cliente*> clientesNormales;
    std::list<Cliente*> clientesPreferenciales;

public:
    void agregarCliente(Cliente* cliente) {
        if (cliente->getTipo() == "Normal") {
            clientesNormales.push(cliente);
        } else {
            auto it = clientesPreferenciales.begin();
            while (it != clientesPreferenciales.end() && (*it)->getTipo() <= cliente->getTipo()) {
                ++it;
            }
            clientesPreferenciales.insert(it, cliente);
        }
    }

    Cliente* siguienteCliente() {
        if (!clientesPreferenciales.empty()) {
            Cliente* cliente = clientesPreferenciales.front();
            clientesPreferenciales.pop_front();
            return cliente;
        }
        if (!clientesNormales.empty()) {
            Cliente* cliente = clientesNormales.front();
            clientesNormales.pop();
            return cliente;
        }
        return nullptr;
    }

    ~ColaClientes() {
        while (!clientesNormales.empty()) {
            delete clientesNormales.front();
            clientesNormales.pop();
        }
        for (Cliente* cliente : clientesPreferenciales) {
            delete cliente;
        }
        clientesPreferenciales.clear();
    }
};
