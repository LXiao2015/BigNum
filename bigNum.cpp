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
    while (n) {
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

BigNum BigNum::operator+(const int &n) {
    BigNum t(n);
    return *this + t;
}

bool BigNum::operator==(const BigNum& n) {
    if (len != n.len) {
	return false;
    }
    for (int i = 0; i < len; ++i) {
        if (num[i] != n.num[i]) {
            return false;
        }
    }
    return true;
}

bool BigNum::operator==(const int& n) {
    BigNum t(n);
    return (*this == t);
}

bool BigNum::operator<(const BigNum& n) {
    bool equal = true;
    if (len < n.len) {
	return true;
    }
    if (len > n.len) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (num[i] > n.num[i]) {
            return false;
        }
        if (equal && num[i] < n.num[i]) {
	    equal = false;
        }
    }
    return !equal;
}

bool BigNum::operator<(const int &n) {
    BigNum t(n);
    return (*this < t);
}

bool BigNum::operator>(const BigNum& n) {
    bool equal = true;
    if (len > n.len) {
        return true;
    }
    if (len < n.len) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (num[i] < n.num[i]) {
            return false;
        }
        if (equal && num[i] > n.num[i]) {
            equal = false;
        }
    }
    return !equal;
}

bool BigNum::operator>(const int &n) {
    BigNum t(n);
    return (*this > t);
}

BigNum BigNum::operator-(const BigNum& n) {
    BigNum res = BigNum();
    if (*this < n) {
        cout << "Error: left operand is smaller than right operand!" << endl;
        res.len = -1;
        return res;
    }
    int sub = 0;
    int i = 0;
    for (; i < n.len; ++i) {
	if (num[i] + sub < n.num[i]) {
            res.num[i] = 10 + num[i] - n.num[i] + sub;
            sub = -1;
        }
	else {
	    res.num[i] = num[i] - n.num[i] + sub;
            sub = 0;
        }
    }
    for (; i < len; ++i) {
        if (num[i] + sub < 0) {
            res.num[i] = 10 + num[i] + sub;
            sub = -1;
        }
        else {
            res.num[i] = num[i] + sub;
            sub = 0;
        }
    }
    res.len = i;
    while (res.len > 1 && res.num[res.len - 1] == 0) {    // 结果为零时, 需保留一个零
        res.len--;
    }
    return res;
}

BigNum BigNum::operator*(const BigNum& n) {

}

BigNum BigNum::operator/(const BigNum& n) {

}


int main() {
    BigNum num1(1111335);
    num1.print();

    // BigNum num2(1111335);
    // num2.print();

    BigNum num3(1111000);
    num3.print();

    // BigNum num4("11r11111111555555");
    // num4.print();
    cout << endl;
    // cout << (num1 < 11111111) << endl;
    // cout << (num3 < 11111111) << endl;
    BigNum num5 = BigNum(num1 - num3);
    BigNum num6 = BigNum(num3 - num1);
    num5.print();
    cout << endl;
    num6.print();
}
