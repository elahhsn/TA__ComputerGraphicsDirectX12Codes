#include <iostream>
#include <stack>
#include <string>
//zahraamiri   4011406106
using namespace std;

class ExpressionConverter {
public:
    string infixToPostfix(string infix) {
        // infix --> postfix
    }

    string postfixToInfix(string postfix) {
        // ? postfix --> infix
    }

    int evaluatePostfix(string postfix) {
        // mohasebe ebarat postfix
    }

    int evaluateInfix(string infix) {
        string postfix = infixToPostfix(infix);
        return evaluatePostfix(postfix);
    }
};

int main() {
    ExpressionConverter converter;
    string infixExpression = "3+4*2/(1-5)^2";
    string postfixExpression = converter.infixToPostfix(infixExpression);
    cout << "Infix to Postfix: " << postfixExpression << endl;

    string infixFromPostfix = converter.postfixToInfix(postfixExpression);
    cout << "Postfix to Infix: " << infixFromPostfix << endl;

    int result = converter.evaluateInfix(infixExpression);
    cout << "Result of Infix expression: " << result << endl;

    return 0;
}
