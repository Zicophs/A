#include <iostream>
#include <string>

// clase stack
//#include "include/stack.h"
#include <stack>

using namespace std;

// Ejercicio 4

/*
    El constructor de copia que se creo en la clase stack es necesario para cuando
    se pasa por valor la pila y se crea un nuevo objeto, asi se puede asegurar que
    la copia tendra los mismos elementos que la pila original.
*/

template<class T>
void printStack(stack<T> p) {
    // se crea una pila auxiliar
    stack<T> aux;

    // se carga en la pila auxiliar los elementos de p
    while(p.size() > 0) {
        aux.push(p.top());
        p.pop();
    }

    // se muestran los elementos de la pila auxiliar y se la va vaciando
    while(aux.size() > 0) {
        cout << aux.top() << endl;
        aux.pop();
    }
}

// Ejercicio 5
// funcion que determina si un caracter es una operacion (solo +, -, *, /)
bool isOperation(char c) {
    char operations[4] = {'+', '-', '/', '*'};

    for(size_t i = 0; i < 4; i++) {
        if(c == operations[i]) {
            return true;
        }
    }

    return false;
}

string preToInfix(string pre_exp) {
    stack<string> p;

    if(!pre_exp.empty() && !isOperation(pre_exp.at(pre_exp.back()))){
        // se itera sobre el string
        for(int i = pre_exp.size()-1; i >= 0; i--) {
            // si el caracter actual es una operacion
            if(isOperation(pre_exp.at(i))) {
                // se crea un string auxiliar con el formato "([tope][operacion]"
                string aux = "(" + p.top() + pre_exp.at(i);
                // se elimina el elemento del tope
                p.pop();
                // y se añade al auxiliar "[tope])"
                aux += p.top() + ")";
                // se elimina nuevamente el tope
                p.pop();

                // finalmente se añade a la pila el auxiliar con la expresion
                p.push(aux);
            }
            // sino se añade el operando a la pila
            else {
                p.push(string(1, pre_exp.at(i)));
            }
        }
    }
    else {
        p.push(pre_exp);
    }
    return p.top();
}

int main() {
    // ejercicio 1, 2, 3
//    cout << "Ejercicio 1: " << endl << endl;
//    test_stack();
//
//    // ejercicio 4
//    cout << endl << "Ejercicio 4: " << endl << endl;
//    stack<int> p;
//
//    p.push(1);
//    p.push(2);
//    p.push(3);
//
//    cout << "Pila a utilizar (p): " << endl;
//    p.show();
//    cout << "Primer llamado a printStack()" << endl;
//    printStack(p);
//    cout << endl << "Segundo llamado a printStack()" << endl;
//    printStack(p);
//    cout << endl;
//    cout << "Llamado a p.show()" << endl;
//    p.show();
//
//    // ejercicio 5
//    cout << "Ejercicio 5: " << endl << endl;
//    string s = "*-A/BC-/AKL";
    string s = "\0";
//    cout << "En notacion prefija: " << endl;
//    cout << "\t" << s << endl;
//    cout << "En notacion infija: " << endl;
    cout << "\t" << preToInfix(s) << endl;

    return 0;
}
