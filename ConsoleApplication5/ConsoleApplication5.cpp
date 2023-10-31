#include <iostream>
#include <string>
using namespace std;

class Calculator
{
private:
    string expression;
    int index;

public:
    Calculator(string ex) {
        expression = ex;
        index = 0;
    }

    double evaluateTerm()
    {
        double term = getOperand();
        while (index < expression.size() && (expression[index] == '*' || expression[index] == '/'))
        {
            char op = expression[index++];
            double nextOperand = getOperand();
            if (op == '*')
                term *= nextOperand;
            else if (op == '/')
                term /= nextOperand;
        }
        return term;
    }

    double getOperand()
    {
        int start = index;
        if (expression[index] == '-' || expression[index] == '+')
            index++;
        while (index < expression.size() && (isdigit(expression[index]) || expression[index] == '.'))
            index++;
        return stod(expression.substr(start, index - start));
    }

    double evaluateExpression()
    {
        double result = evaluateTerm();
        while (index < expression.size() && (expression[index] == '+' || expression[index] == '-'))
        {
            char op = expression[index++];
            double term = evaluateTerm();
            if (op == '+')
                result += term;
            else if (op == '-')
                result -= term;
        }
        return result;
    }

    void evaluate()
    {
        double result = evaluateExpression();
        cout << "Result: " << result << endl;
    }
};

int main()
{
    char choice;

    do
    {
        string inputExpression;

        cout << "Write the expression (or press 'q' to quit): ";
        cin >> inputExpression;

        if (inputExpression == "q")
        {
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        Calculator obj(inputExpression);
        obj.evaluate();

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice != 'n');

    return 0;
}
