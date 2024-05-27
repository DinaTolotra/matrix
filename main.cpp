#include <iostream>
#include <vector>

#include "include/matrice.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Matrice a(3), b(3);
    char oper;

    cout << "Input a:" << endl;
    for (int i=0; i<a.getHeight(); i++) {
        for (int j=0; j<a.getWidth(); j++) {
            int input;
            cin >> input;
            a.at(j, i) = input;
        }
    }

    cout << "Input b:" << endl;
    for (int i=0; i<a.getHeight(); i++) {
        for (int j=0; j<a.getWidth(); j++) {
            int input;
            cin >> input;
            b.at(j, i) = input;
        }
    }

    cout << "Operateur: " << endl;
    cin >> oper;

    switch (oper) {
    case '+':
        cout << "Addition: " << endl;
        (a+b).print();
        break;
    case '-':
        cout << "Soustraction: " << endl;
        (a-b).print();
        break;
    case '*':
        cout << "Multiplication: " << endl;
        (a*b).print();
        break;
    }

    return 0;
}