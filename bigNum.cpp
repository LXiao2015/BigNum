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
    memset(num, 0, MAX_LEN);
    int base = 10;
    int i = 0;
    while (n) {
        num[i++] = n % base;
        n = n / base;
    }
    len = i;
}

BigNum::BigNum(const string n) {
    memset(num, 0, MAX_LEN);
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
        carry = sum / 10;
        res.num[i] = sum % 10;
    }
    for (; i < len; ++i) {
        int sum = num[i] + carry;
        carry = sum / 10;
        res.num[i] = sum % 10;
    }
    for (; i < n.len; ++i) {
        int sum = n.num[i] + carry;
        carry = sum / 10;
        res.num[i] = sum % 10;
    }
    if (carry) {
        res.num[i] = 1;
        i++;
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

BigNum BigNum::operator-(const int &n) {
    BigNum t(n);
    return *this - t;
}

BigNum BigNum::operator*(const BigNum& n) {
    BigNum t(n);
    BigNum res = BigNum(*this);
    while (t > 1) {
        cout << t << endl;
        res = res + *this;
        t = t - 1;
    }
    return res;
}

BigNum BigNum::operator*(const int &n) {
    int t = n;
    BigNum res = BigNum(*this);
    while (t > 1) {
        res = res + *this;
        t = t - 1;
    }
    return res;
}

BigNum BigNum::operator/(const BigNum& n) {

}

// 友元函数不是 BigNum 类的成员函数, 不要加类作用域限定符
ostream& operator<<(ostream& output, const BigNum &n) {
    for (int i = n.len - 1; i >= 0; --i) {
        output << n.num[i];
    }
    return output;
}

istream& operator>>(istream& input, BigNum &n) {
    string s;
    input >> s;
    int i = 0;
    for (int index = s.length() - 1; index >= 0; --index) {
        if (s[index] >= '0' && s[index] <= '9') {
            n.num[i++] = s[index] - '0';
        }
        else {
            cout << "Invalid string: cannot convert it into BigNum!" << endl;
            n.len = -1;
            return input;
        }
    }
    n.len = i;
    return input;
}

int main() {
    BigNum num1;
    cin >> num1;
    // num1.print();
    auto num3 = num1 * 3;
    cout << num3 << endl;
    return 0;
}
