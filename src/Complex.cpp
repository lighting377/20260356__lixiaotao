// ============================================================
// Complex.cpp - Complex 类成员函数实现（
//
// 实现完成后运行 ./build/complex_demo，应该输出：
// 应该输出：
//   a = 3 + 4i
//   a + b = 4 + 6i
//   a - b = 2 + 2i
// 全部做完后再跑 ctest，应该显示 100% tests passed。
// ============================================================

#include "Complex.h"

#include <iostream>

using namespace std;

// 构造函数：两个数据成员都在初始化列表中完成初始化。
// 默认参数写在头文件里，所以 Complex z、Complex z(3)、Complex z(3, 4) 三种写法都能用。
Complex::Complex(double r, double i) : real(r), imag(i) {}

// 析构函数：本类没有动态申请的资源，函数体留空即可。
Complex::~Complex() {}

// 复数相加：返回一个新对象，两个操作数都保持只读（const 成员函数 + const 参数）。
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// 复数相减：实部、虚部分别相减，同样不修改操作数。
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// 按约定格式打印：虚部 >= 0 输出 "a + bi"，虚部 < 0 输出 "a - bi"（虚部取绝对值）
void Complex::print() const {
    if (imag >= 0) {
        cout << real << " + " << imag << "i" << endl;
    } else {
        cout << real << " - " << -imag << "i" << endl;
    }
}

// 读取实部：const 成员函数，不会修改对象。
double Complex::getReal() const {
    return real;
}

// 读取虚部。
double Complex::getImag() const {
    return imag;
}
