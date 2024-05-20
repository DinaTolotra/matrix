#include <iostream>
#include <vector>

#include "include/matrice.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Matrice a(4), b(4);
    a.fill(2); b.fill(0);

    for (int i = 0; i < b.getWidth(); ++i) {
        b.at(i, i) = 2;
    }

    (a * b).print();

    return 0;
}