#include <iostream>
using namespace std;
class Number {
private:
    int value;
public:
    Number(int val) : value(val) {}
    friend Number operator+(const Number& n1, const Number& n2);
};

Number operator+(const Number& n1, const Number& n2) {
    return Number(n1.value + n2.value);
}

int main() {
    int A, B;
    cout << "Nhap vao so nguyen A:";
    cin >> A;
    cout << "Nhap vao so nguyen B:";
    cin >> B;
    Number numA(A), numB(B);
    Number sum = numA + numB;
    cout << "Tong cua A và B la : " << sum <<endl;
    return 0;
}



