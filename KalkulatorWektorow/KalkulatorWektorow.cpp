
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class vect {
private:
    T x, y, z;

public:
    vect(T x = 0, T y = 0, T z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() const {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }

    vect<T> add(const vect<T>& other) const {
        return vect<T>(x + other.x, y + other.y, z + other.z);
    }

    vect<T> subtract(const vect<T>& other) const {
        return vect<T>(x - other.x, y - other.y, z - other.z);
    }

    vect<T> multiply(T scalar) const {
        return vect<T>(x * scalar, y * scalar, z * scalar);
    }

    T dot(const vect<T>& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    T length() const {
        return sqrt(x * x + y * y + z * z);
    }

    string cauchySchwarz(const vect<T>& other) const {
        if (abs(dot(other)) <= length() * other.length() + 1e-9) {
            return "Nierownosc jest spelniona";
        }
        return "Nierownosc nie jest spelniona";
    }

    vect<T> unit() const {
        T len = length();

        if (len == 0) {
            return vect<T>(0, 0, 0);
        }

        return vect<T>(x / len, y / len, z / len);
    }
};

int main() {
    vect<double> VA(4, 2, 0);
    vect<double> VB(7, 2, 4);
    vect<double> VC(3, 6, 9);

    cout << "--- WEKTORY ---" << endl;
    cout << "VA = "; VA.print();
    cout << "VB = "; VB.print();
    cout << "VC = "; VC.print();
    cout << endl;

    cout << "--- DLUGOSCI ---" << endl;
    cout << "VA = " << VA.length() << endl;
    cout << "VB = " << VB.length() << endl;
    cout << "VC = " << VC.length() << endl;

    cout << "\n--- SUMA ---" << endl;
    cout << "VA + VB + VC = ";
    VA.add(VB).add(VC).print();

    cout << "\n--- ROZNICA ---" << endl;
    cout << "VA - VB - VC = ";
    VA.subtract(VB).subtract(VC).print();

    cout << "\n--- MNOZENIE PRZEZ SKALAR ---" << endl;
    cout << "VA * 2 = ";
    VA.multiply(2).print();

    cout << "\n--- ILOCZYN SKALARNY ---" << endl;
    cout << "VA * VB = " << VA.dot(VB) << endl;
    cout << "VA * VC = " << VA.dot(VC) << endl;
    cout << "VB * VC = " << VB.dot(VC) << endl;

    cout << "\n--- CAUCHY-SCHWARZ-BUNIAKOWSKI ---" << endl;

    cout << "VA, VB: " << VA.cauchySchwarz(VB) << endl;
    cout << "VA, VC: " << VA.cauchySchwarz(VC) << endl;
    cout << "VB, VC: " << VB.cauchySchwarz(VC) << endl;


    cout << "\n--- WEKTORY JEDNOSTKOWE ---" << endl;

    vect<double> VA_unit = VA.unit();
    vect<double> VB_unit = VB.unit();
    vect<double> VC_unit = VC.unit();

    cout << "VA jednostkowy = ";
    VA_unit.print();
    cout << "Dlugosc = " << VA_unit.length() << endl;

    cout << "VB jednostkowy = ";
    VB_unit.print();
    cout << "Dlugosc = " << VB_unit.length() << endl;

    cout << "VC jednostkowy = ";
    VC_unit.print();
    cout << "Dlugosc = " << VC_unit.length() << endl;


    return 0;
}
