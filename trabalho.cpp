#include <iostream>
#include <string>
#include <vector>

class Stack {
private:
    std::vector<char> elements;

public:
    void push(char c) {
        elements.push_back(c);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    char top() {
        if (!elements.empty()) {
            return elements.back();
        }
        return '\0'; 
    }

    bool isEmpty() {
        return elements.empty();
    }
};

bool isBalanced(const std::string &expression) {
    Stack stack;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) {
                return false; 
            }
            char topChar = stack.top();
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return false; 
            }
            stack.pop();
        }
    }

    return stack.isEmpty();
}

int main() {
    std::string expression;

    std::cout << "Digite a expressão para verificar: ";
    std::getline(std::cin, expression);

    if (isBalanced(expression)) {
        std::cout << "A expressão está balanceada" << std::endl;
    } else {
        std::cout << "A expressão não está balanceada" << std::endl;
    }

    return 0;
}
