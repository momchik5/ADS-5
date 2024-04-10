// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char);

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
            d.pop();
        } else if (prioritet(infix[i]) > prioritet(d.check())) {
            d.push(infix[i]);
        } else {
       while (true) {
            if (d.isempty()) {
                break;
            } else if (!(prioritet(infix[i]) <= prioritet(d.check()))) {
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
  std::string str = "";
  TStack<int, 100> operands;

  for (int i = 0; i < post.length(); i++) {
    if (isdigit(post[i])) {
      str += post[i];
    } else if (str.length() && post[i] == ' ') {
      operands.push(atoi(time.c_str()));
      str = "";
    } else {
      switch (post[i]) {
        case '+': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one + two);
          break;
        }
        case '-': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one - two);
          break;
        }
        case '*': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one * two);
          break;
        }
        case '/': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one / two);
          break;
        }
      }
    }
  }
  return operands.pop();
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
