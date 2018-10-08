#include <iostream>
#include <cstring>
#include "bigNum.h"

using namespace std;

BigNum::BigNum() {
    memset(num, 0, MAX_LEN);
    len = 0;
}

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

BigNum BigNum::operator+(const BigNum& n){
    int carry = 0;
    int i = 0;
    BigNum res = BigNum();
    for (; i < len && i < n.len; ++i) {
        int sum = num[i] + n.num[i] + carry;
        int carry = sum / 10;
        res.num[i] = sum % 10;
    }
    for (; i < len; ++i) {
        int sum = num[i] + carry;
        int carry = sum / 10;
        res.num[i] = sum % 10;
    }
    for (; i < n.len; ++i) {
        int sum = n.num[i] + carry;
        int carry = sum / 10;
        res.num[i] = sum % 10;
    }
    res.len = i;
    return res;
}

int main() {
    BigNum num1(1111335);
    // num1.print();

    // BigNum num2(-13555555);
    // num2.print();

    BigNum num3("32948094535447054");
    // num3.print();

    // BigNum num4("11r11111111555555");
    // num4.print();

    BigNum num5 = BigNum(num1 + num3);
    num5.print();
}
