#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
    Graph(int numVertices) : vertices(numVertices), adjList(numVertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Para grafos no dirigidos
    }

    void bfs(int startVertex) { //Realiza un  recorrido en el grafo empezando desde el vertice StartVertex, utilizando el vector visited
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;// almacenamos los vertices que se deben visitar 

        visited[startVertex] = true; //Comenzamos marcando true y lo agregamos a la cola
        q.push(startVertex); 

        while (!q.empty()) { // Mientras la cola no este vacia
            int currentVertex = q.front(); // sacamos al primer valor de la cola
            std::cout << currentVertex << " "; // Imprimimos el currentVertex
            q.pop(); // sacamos con el pop

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) { // Si el vecino no esta visitado
                    visited[neighbor] = true; // Lo ponemos en verdadero
                    q.push(neighbor); // metemos al vecino 
                }
            }
        }
    }

private:
    int vertices;
    std::vector<std::vector<int>> adjList;
};

int main() {
    Graph myGraph(6);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(3, 5);

    std::cout << "BFS starting from vertex 0: ";
    myGraph.bfs(0);

    return 0;
}