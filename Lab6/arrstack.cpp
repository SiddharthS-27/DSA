// program to implement stack ADT using character array of size 5
#include <iostream>
#define size 5
using namespace std;

class stack
{
    char arr[size];
    int tos;

public:
    stack()
    {
        tos = -1;
    };
    bool isFull() // time complexity is O(1)
    {
        if (tos == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty() // time complexity is O(1)
    {
        if (tos == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    char push(char val) // time complexity is O(1)
    {
        if (!isFull())
        {
            if (isEmpty())
            {
                arr[0] = val;
                tos = 0;
            }
            else
            {
                arr[tos + 1] = val;
                tos++;
            }
            return '1';
        }
        return '#'; // to signify list is full
    }
    char pop() // time complexity is O(1)
    {
        if (!isEmpty())
        {
            tos--;
            return arr[tos + 1];
        }
        return '#'; // to signify list is full
    }
    char peek() // time complexity is O(1)
    {
        if (!isEmpty())
        {
            return arr[tos];
        }
        return '#'; // to signify list is full
    }
};

int main()
{
    stack s1;
    int choice;
    char value, result;
    while (1)
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cout << "Enter menu number of operation you want to perform: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to push: ";
            cin >> value;
            result = s1.push(value);
            if (result == '#')
            {
                cout << "List full.\n";
            }
            else
            {
                cout << "Value " << value << " has been pushed.\n";
            }
            break;
        }
        case 2:
        {
            result = s1.pop();
            if (result == '#')
            {
                cout << "List empty.\n";
            }
            else
            {
                cout << result << " has been popped.\n";
            }
            break;
        }
        case 3:
        {
            result = s1.peek();
            if (result == '#')
            {
                cout << "List empty.\n";
            }
            else
            {
                cout << result << " is at the top of the stack.\n";
            }
            break;
        }
        case 4:
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