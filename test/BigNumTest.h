#include "src/bigNum.h"
#include "cppunit/TestFixture.h"

class BigNumTest : public CppUnit::TestFixture {
protected:
    int num1, num2;

public:
    BigNumTest() {}

    // 初始化函数
    void setUp();
    // 清理函数
    void tearDown() {}

    // 测试加法的测试函数
    void testAdd();
};
