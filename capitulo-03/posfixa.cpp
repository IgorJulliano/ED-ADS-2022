#include "pilha.cpp"
#include <iostream>

bool isOperator(char c)
{
    return string("+-*/").find(c) != string::npos;
}

int operatorPriority(char operat)
{
    if (operat == '(')
        return 0;
    if (operat == '+' || operat == '-')
        return 1;
    if (operat == '*' || operat == '/')
        return 2;
    return -1;
}

string fromInfixStringToPosfix(string oneDigitInfix)
{
    Stack<char> operators = Stack<char>(oneDigitInfix.length());

    string posfixString = "";

    for (int i = 0; i < oneDigitInfix.length(); i++)
    {
        if (oneDigitInfix[i] == '(') {
            operators.push(oneDigitInfix[i]);
        } else if (isdigit(oneDigitInfix[i]))
        {
            posfixString += oneDigitInfix[i];
        } else if (isOperator(oneDigitInfix[i]))
        {
            while (!operators.isEmpty() && operatorPriority(operators.top()) >= operatorPriority(oneDigitInfix[i]))
            {
                posfixString += operators.pop();
            }
            operators.push(oneDigitInfix[i]);
        } else if (oneDigitInfix[i] == ')')
        {
            while (operators.top() != '(')
            {
                posfixString += operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.isEmpty())
    {
        posfixString += operators.pop();
    }

    return posfixString;
}

// Stack<int> toPosfix(string spaceSepInfix)
// {
//     Stack<char> operators = Stack<char>(spaceSepInfix.length());

//     Stack<int> posfix = Stack<int>(spaceSepInfix.length()); // when/how to use this
//     string posfixString = "";

//     for (int i = 0; i < spaceSepInfix.length(); i++)
//     {
//         if (spaceSepInfix[i] == '(')
//             operators.push(spaceSepInfix[i]);
//         else if (isdigit(spaceSepInfix[i]))
//             posfix += spaceSepInfix[i] - '0');

//         else if (isOperator(spaceSepInfix[i]))
//         {
//             while (!operators.isEmpty() && operatorPriority(operators.top()) >= operatorPriority(spaceSepInfix[i]))
//             {
//                 posfix += operators.pop());
//             }
//             operators.push(spaceSepInfix[i]);
//         }
//         else if (spaceSepInfix[i] == ')')
//         {
//             while (operators.top() != '(')
//             {
//                 posfix += operators.pop());
//             }
//             operators.pop();
//         }
//     }

//     while (!operators.isEmpty())
//     {
//         posfix += operators.pop());
//     }

//     return posfix;
// }

float evaluatePosfix(string posfix)
{
    Stack<int> numbers = Stack<int>(posfix.length());

    for (int i = 0; i < posfix.length(); i++)
    {
        if (isdigit(posfix[i]))
            numbers.push(posfix[i] - '0');
        else
        {
            int num1 = numbers.pop();
            int num2 = numbers.pop();

            if (posfix[i] == '+')
            {
                numbers.push(num2 + num1);
            }
            if (posfix[i] == '-')
            {
                numbers.push(num2 - num1);
            }
            if (posfix[i] == '*')
            {
                numbers.push(num2 * num1);
            }
            if (posfix[i] == '/')
            {
                numbers.push(num2 / num1);
            }
        }
    }

    return numbers.pop();
}
