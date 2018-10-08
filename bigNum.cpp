#include <iostream>
#include "bigNum.h"

using namespace std;

BigNum::BigNum(int n) {
    if (n < 0) {
        cout << "Invalid number: BigNum can only be used to store non-negative integers!" << endl;
        len = -1;
        return ;
    }
    int base = 10;
    int i = 0;
    while (n % base) {
        num[i++] = n % base;
        n = n / base;
    }
    len = i;
}

BigNum::BigNum(const string n) {
    int i = 0;
    for (int index = n.length() - 1; index >= 0; --index) {
        if (n[index] >= '0' && n[index] <= '9') {
            num[i++] = n[index] - '0';
        }
        else {
            cout << "Invalid string: cannot convert it into BigNum!" << endl;
            len = -1;
            return ;
        }
    }
    len = i;
}

void BigNum::print() {
    if (len > MAX_LEN) {
        cout << "Length error: len exceeds limited length!" << endl;
        return ;
    }
    if (len < 0) {
        cout << "Length error: len cannot be negative!" << endl;
        return ;
    }
    for (int i = len - 1; i >= 0; --i) {
        cout << num[i];
    }
}


int main() {
    BigNum num1(1111335);
    num1.print();

    BigNum num2(-13555555);
    num2.print();

    BigNum num3("32948094535447054");
    num3.print();

    BigNum num4("11r11111111555555");
    num4.print();
}
