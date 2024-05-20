#include "matrice.hpp"

Matrice::Matrice() {
    w = h = 0;
}


Matrice::Matrice(int side) {
    matrice.resize(side, v<int>(side, 0));
    this->w = this->h = side;
}


Matrice::Matrice(int w, int h) {
    matrice.resize(h, v<int>(w, 0));
    this->w = w;
    this->h = h;
}


Matrice::Matrice(const Matrice &other) {
    *this = other;
}


Matrice::~Matrice() {}


Matrice &Matrice::operator=(const Matrice &other) {
    if (this == &other)
        return *this;

    if (w < other.w) {
        this->insertCol(other.w - w);
    } else if (w > other.w) {
        this->removeCol(w - other.w);
    }

    if (h < other.h) {
        this->insertRow(other.h - h);
    } else if (h > other.h) {
        this->removeRow(h - other.h);
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            matrice[i][j] = other.at(j, i);
        }
    }

    return *this;
}


Matrice Matrice::operator+(const Matrice &other) {
    if (w != other.w || h != other.h)
        throw std::invalid_argument("Size different matrix");
    
    Matrice result(w, h);

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            result.at(j, i) = this->at(j, i) + other.at(j, i);
        }
    }

    return result;
}


Matrice Matrice::operator-(const Matrice &other) {
    if (w != other.w || h != other.h)
        throw std::invalid_argument("Size different matrix");
    
    Matrice result(w, h);

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            result.at(j, i) = this->at(j, i) - other.at(j, i);
        }
    }

    return result;
}


Matrice Matrice::operator*(const Matrice &other) {
    if (w != other.h || h != other.w)
        throw std::invalid_argument("Invalid matrix'size");
    
    Matrice result(w, other.h);

    for (int i=0; i<w; i++) {
        for (int j=0; j<other.h; j++) {
            result.at(i, j) = sumOfProduct(
                this->getRow(i),
                other.getCol(j)
            );
        }
    }

    return result;
}


//  external function
int sumOfProduct(const vector<int> &v1, const vector<int> &v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("Size different vector");

    int sum = 0;

    for (size_t i=0; i<v1.size(); i++) 
        sum += v1[i]*v2[i];

    return sum;
}


vector<int> Matrice::getCol(int x) const {
    if (x < 0 || x >= h)
        throw std::out_of_range("Invalide position");

    vector<int> result(h);

    for (int i=0; i<h; i++) 
        result[i] = at(x, i);

    return result;
}


vector<int> Matrice::getRow(int y) const {
    if (y < 0 || y >= w)
        throw std::out_of_range("Invalide position");

    vector<int> result(w);

    for (int i=0; i<w; i++) 
        result[i] = at(i, y);

    return result;
}


void Matrice::insertCol(int count) {
    if (count<=0)
        return;

    w += count;
    for (v<int> row: matrice)
        row.resize(w, 0);
}


void Matrice::insertRow(int count) {
    if (count<=0)
        return;
    
    h += count;
    matrice.resize(h, v<int>(w, 0));
}


void Matrice::removeCol(int count) {
    if (count<=0)
        return;

    w -= count;
    for (v<int> row: matrice)
        row.resize(w);
}


void Matrice::removeRow(int count) {
    if (count<=0)
        return;

    h -= count;
    matrice.resize(h);
}


void Matrice::fill(int value) {
    for (auto &row: matrice) {
        for (auto &elem: row) {
            elem = value;
        }
    }
}


int Matrice::at(int x, int y) const {
    return matrice.at(y).at(x);
}


int &Matrice::at(int x, int y) {
    return matrice[y][x];
}


void Matrice::print() {
    for (v<int> &row: matrice) {
        for (int elem: row)
            std::cout << elem << ' ';
        std::cout << '\n';
    }
}


int Matrice::getWidth() const {
    return w;
}


int Matrice::getHeight() const {
    return h;
}
