#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
using namespace std;

// Khai báo hàm kiểm tra độ ưu tiên
int precedence(char op);

// Khai báo hàm chuyển đổi biểu thức trung tố sang hậu tố
string infixToPostfix(string infix);

#endif