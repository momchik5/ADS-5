// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char);
int schet(int, int, char);

std::string infx2pstfx(std::string inf) {
    std::string postfix = "";
    TStack<char, 100> d;
    for (int i = 0; i < inf.length(); i++) {
        if (isdigit(inf[i])) {
            postfix += inf[i];
            if (i != inf.length() - 1) {
                postfix += " ";
            }
        } else if (inf[i] == '(') {
            d.push(inf[i]);
        } else if (d.isempty()) {
            d.push(inf[i]);
        } else if (inf[i] == ')') {
            while (true) {
                if (d.isempty()) {
                    break;
                } else if (d.check() == '(') {
                    break;
                }
                postfix += d.pop();
                if (i != inf.length() - 1) {
                    postfix += " ";
                }
            }
            d.pop();
        } else if (prioritet(inf[i]) > prioritet(d.check())) {
            d.push(inf[i]);
        } else {
       while (true) {
            if (d.isempty()) {
                break;
            } else if (!(prioritet(inf[i]) <= prioritet(d.check()))) {
                break;
       }
        postfix += d.pop();
        if (i != inf.length() - 1) {
            postfix += " ";
        }
    }
    d.push(inf[i]);
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
        } else if (stroka.length() && post[i] == ' ') {
            operand.push(atoi(stroka.c_str()));
            stroka = "";
        } else {
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
    } else if (c == ')') {
        return 1;
    } else if ((c == '+') || (c == '-')) {
        return 2;
    } else if ((c == '*') || (c == '/')) {
        return 3;
    } else {
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
