#include <iostream>
#include <vector>

class Graph {
public:
    Graph(int numVertices) : vertices(numVertices), adjList(numVertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Para grafos no dirigidos
    }

    void dfs(int currentVertex, std::vector<bool>& visited) { // realiza el recorrido en profundidad en el grafo, comenzando desde el currentVertex
        visited[currentVertex] = true; // hace seguimiento de los vertices que ya han sido visitados
        std::cout << currentVertex << " "; // imprime su valor y luego hace un dfs en todos sus vecinos no visitados

        for (int neighbour : adjList[currentVertex]) { 
            if (!visited[neighbour]) { // si no esta visitado disparamos un dfs
                dfs(neighbour, visited);
            }
        }
    }

    void dfsTraversal() {
        std::vector<bool> visited(vertices, false); // creamos un vector visited inicializado con false para cada vertice y llama a Dfs
        for (int i = 0; i < vertices; ++i) { 
            if (!visited[i]) { // si no esta visitado en la pisicion i, disparamos un dfs y lo ponemos como visitado
                dfs(i, visited);
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

    std::cout << "DFS traversal: ";
    myGraph.dfsTraversal();

    return 0;
}