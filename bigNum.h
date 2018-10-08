#include <iostream>
#define MAX_LEN 100
using namespace std;

class BigNum {
public:
    BigNum(int n);
    BigNum(const string n);
    void print();

private:
    int num[MAX_LEN];    // 不需要结束符, 用 len 控制长度, 倒序存数位数对齐便于计算
    int len;
};
