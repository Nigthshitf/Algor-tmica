#include <iostream>
#include <vector>

class Graph {
public:
    Graph(int numVertices) : vertices(numVertices) { // la funcion toma un parametro que especifica el numero de vertices en el grafo
        adjList.resize(numVertices); // esto redimensiona adjlost para que tenga numVertices, inicializado con un vector vacio 
    }

    void agregarArista(int origen, int destino) { //Esta funcion toma dos parametros que son origen y destino que representa los vertices de la arista que se va a agregar
        adjList[origen].push_back(destino);
        adjList[destino].push_back(origen);
    }

private:
    int vertices; // creamos una variable int
    std::vector<std::vector<int>> adjList; // almacenamos la lista de adyaciencia del grafo
};

int main() {
    Graph miGrafo(5); // Aqui creamos para ver si el codigo es correcto
    miGrafo.agregarArista(0, 1);
    miGrafo.agregarArista(1, 2); 
    return 0;
}