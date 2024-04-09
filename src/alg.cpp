// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char);
int schet(int, int, char);

std::string infx2pstfx(std::string inf) {
    std::string postfix = "";
    TStack<char, 100> d;
    for (int i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) {
            postfix += infix[i];
            if (i != infix.length() - 1) {
                postfix += " ";
            }
        } else if (infix[i] == '(') {
            d.push(infix[i]);
        } else if (d.isempty()) {
            d.push(infix[i]);
        } else if (infix[i] == ')') {
            while (true) {
                if (d.isempty()) {
                    break;
                } else if (d.check() == '(') {
                    break;
                }
                postfix += d.pop();
                if (i != infix.length() - 1) {
                    postfix += " ";
                }
            }
        }
        d.pop();
    else if (prioritet(infix[i]) > prioritet(d.check())) {
        d.push(infix[i]);
    }
    else {
        while (true) {
            if (d.isempty()) {
                break;
            }
            else if (!(prioritet(infix[i]) <= prioritet(d.check()))) {
                break;
            }
            postfix += d.pop();
            if (i != infix.length() - 1) {
                postfix += " ";
            }
        }
        d.push(infix[i]);
    }
}
while (!d.isempty()) {
    postfix += " ";
    postfix += d.pop();
}
return postfix;
}

int eval(std::string post) {
    std::string stroka = "";
    TStack<int, 100> operand;

    for (int i = 0; i < post.length(); i++) {
        if (isdigit(post[i])) {
            stroka += post[i];
        }
        else if (stroka.length() && post[i] == ' ') {
            operand.push(atoi(stroka.c_str()));
            stroka = "";
        }
        else {
            int two = operand.pop();
            int one = operand.pop();
            operand.push(schet(one, two, post[i]));
        }
    }
    return operand.pop();
}
 int prioritet(char c) {
    if (c == '(') {
        return 0;
    }
    else if (c == ')') {
        return 1;
    }
    else if ((c == '+') || (c == '-')) {
        return 2;
    }
    else if ((c == '*') || (c == '/')) {
        return 3;
    }
    else {
        throw "Error!";
    }
}
 int schet(int x, int y, char znak) {
     switch (znak) {
     case '+':
         return x + y;
     case '-':
         return x - y;
     case '*':
         return x * y;
     case '/':
         return x / y;
     default:
         return 0;
     }
 }
