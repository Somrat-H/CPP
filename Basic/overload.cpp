#include <iostream>

using namespace std;

int add(int a, int b) {
    return a+b;
}

float add(float a, float b) {
    return a+b;
}

double add(double a, double b) {
    return a+b;
}

long add(long a, long b) {
    return a+b;
}

// overload in function depend on datatype and call it own datatype add function.

int main() {
    cout << "Addation : " << add(4, 4) << endl;    
}