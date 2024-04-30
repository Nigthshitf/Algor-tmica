#include <iostream>
#include <stack>

int main() {
    std::stack<int> Pilita; // creamos una pila llamada miPila
    Pilita.push(10); // Agregamos valores a la pila
    Pilita.push(20);
    Pilita.push(30);

    while (!Pilita.empty()) { // Mientras la pila no este vacia
        std::cout << Pilita.top() << " "; // Checkeamos si hay algo en el tope de la  pila 
        Pilita.pop(); // Sacamos el primer valor de la pila
    }

    return 0;
}