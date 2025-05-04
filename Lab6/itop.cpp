// program to implement infix to postfix and postfix evaluation
#include <iostream>
#include "slls.h"
using namespace std;

int main()
{
    sll op;
    int choice;
    char infix[10];
    char postfix[10];
    sll postack;
    char temp;
    while (1)
    {
        cout << "\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\n";
        cout << "Enter menu number of operation you want to perform: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
        {
            cout << "Enter infix expression: ";
            cin >> infix;
            break;
        }
        case 2: // time complexity is O(n)
        {
            int i = 0, j = 0;
            while (infix[i] != '\0')
            {

                if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == '+' || infix[i] == '-')
                {
                    if (op.isEmpty() == 1)
                    {
                        op.push(infix[i]);
                    }
                    else
                    {
                        if ((op.peek() == '+' || op.peek() == '-') && (infix[i] == '*' || infix[i] == '/' || infix[i] == '%'))
                        {
                            op.push(infix[i]);
                        }
                        else
                        {
                            postfix[j] = op.pop();
                            op.push(infix[i]);
                            j++;
                        }
                    }
                }
                else
                {
                    postfix[j] = infix[i];
                    j++;
                }
                i++;
            }
            temp = op.pop();
            while (temp != '#')
            {
                postfix[j] = temp;
                j++;
                temp = op.pop();
            }
            postfix[j] = '\0';
            cout << postfix << "\n";
            break;
        }
        case 3: // time complexity is O(n)
        {
            int i = 0;
            char temp;
            while (postfix[i] != '\0')
            {
                switch (postfix[i])
                {
                case '+':
                {
                    int a = postack.pop() - '0';
                    int b = postack.pop() - '0';
                    postack.push((b + a) + '0');
                    break;
                }
                case '-':
                {
                    int a = postack.pop() - '0';
                    int b = postack.pop() - '0';
                    postack.push((b - a) + '0');
                    break;
                }
                case '*':
                {
                    int a = postack.pop() - '0';
                    int b = postack.pop() - '0';
                    postack.push((b * a) + '0');
                    break;
                }
                case '/':
                {
                    int a = postack.pop() - '0';
                    int b = postack.pop() - '0';

                    postack.push((b / a) + '0');
                    break;
                }
                case '%':
                {
                    int a = postack.pop() - '0';
                    int b = postack.pop() - '0';
                    postack.push((b % a) + '0');
                    break;
                }

                default:
                {
                    postack.push(postfix[i]);
                }
                }
                i++;
            }
            temp = postack.pop();
            cout << "Result is " << temp;
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid choice.";
        }
        }
    }
    return 0;
}
