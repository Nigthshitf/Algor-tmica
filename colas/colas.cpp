#include <iostream>
#include <queue>

int main() {
    std::queue<int> Queue; // Creamos una cola llamada queue 
    Queue.push(10); // metemos valores a la cola
    Queue.push(20);
    Queue.push(30);

    while (!Queue.empty()) { // mientras no este vacio la cola, entramos al whyle
        std::cout << Queue.front() << " "; // Checkeamos si hay algo en el frente de la cola
        Queue.pop(); // Sacamos el primer valor de la cola
    }

    return 0;
}