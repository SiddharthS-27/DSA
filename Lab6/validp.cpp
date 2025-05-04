#include <iostream>
#include "slls.h"
using namespace std;

int main()
{
    sll s1;
    int choice;
    char exp[10];
    while (1)
    {
        cout << "\n1. Check Balance\n2. Exit\n";
        cout << "Enter menu number of operation you want to perform: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // time complexity is O(n)
        {
            int i = 0;
            cout << "Enter the expression: ";
            cin >> exp;

            while (exp[i] != '\0')
            {
                if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                {
                    s1.push(exp[i]);
                }
                else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
                {
                    if (s1.isEmpty() == 1)
                    {
                        cout << "The expression is not balanced.\n";
                        return 0;
                    }
                    char top = s1.pop();

                    if ((exp[i] == ')' && top != '(') ||
                        (exp[i] == '}' && top != '{') ||
                        (exp[i] == ']' && top != '['))
                    {
                        cout << "The expression is not balanced.\n";
                        return 0;
                    }
                }
                i++;
            }

            if (s1.isEmpty() == 1)
            {
                cout << "The expression is balanced.\n";
            }
            else
            {
                cout << "The expression is not balanced.\n";
            }
        }
        case 2:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid choice.\n";
        }
        }
    }
    return 0;
}

// the optimal ADT is a stack implemented using a linked list to save memory space
