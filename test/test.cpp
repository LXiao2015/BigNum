#include "BigNumTest.h"
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestSuite.h"

int main() {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestSuite *suite = new CppUnit::TestSuite();

    // 添加一个测试用例
    suite->addTest(new CppUnit::TestCaller<BigNumTest> (
		   "testAdd", &BigNumTest::testAdd) );

    // 指定运行 TestSuite
    runner.addTest(suite);
    // 开始运行, 自动显示测试进度和测试结果
    runner.run("", true);
}
