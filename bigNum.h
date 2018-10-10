#include <iostream>
#define MAX_LEN 1000
using namespace std;

class BigNum {
public:
    BigNum();
    BigNum(int n);
    BigNum(const string n);

    virtual ~BigNum() {};

    bool operator==(const BigNum& n);
    bool operator==(const int &n);
    bool operator>(const BigNum& n);
    bool operator>(const int &n);
    bool operator<(const BigNum& n);
    bool operator<(const int &n);

    BigNum operator+(const BigNum& n);
    BigNum operator+(const int &n);
    BigNum operator-(const BigNum& n);
    BigNum operator-(const int &n);
    BigNum operator*(const BigNum& n);
    BigNum operator/(const BigNum& n);

    // 声明为类的友元函数, 这样就能不用创建对象而直接调用函数
    friend ostream& operator<<(ostream& output, const BigNum &n);
    friend istream& operator>>(istream& input, BigNum &n);

    void print();

private:
    int num[MAX_LEN];    // 不需要结束符, 用 len 控制长度, 倒序存数位数对齐便于计算
    int len;
};
