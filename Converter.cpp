#include "Converter.h"
#include "Stack.h"
#include <cctype>

int   precedence(char op) {
    if (op == '^') return 5;
    if (op == '*' || op == '/') return 4;
    if (op == '+' || op == '-') return 3;
    if (op == '(') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    LinkedListStack st; 
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix += c;
        } 
        else if (c == '(') {
            st.push('(');
        } 
        else if (c == ')') {
            while (!st.isEmpty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.isEmpty() && st.top() == '(') {
                st.pop(); 
            }
        } 
        else {
            while (!st.isEmpty() && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while (!st.isEmpty()) {
        if (st.top() != '(') postfix += st.top();
        st.pop();
    }
    
    return postfix;
}