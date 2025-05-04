// program to implement a stack using singly linked list

#include <cstdlib>
#include <iostream>
using namespace std;

class sll
{
    struct node
    {
        char data;
        struct node *next;
    } *head;

public:
    sll()
    {
        head = nullptr;
    };
    char insert_beg(char value) // time complexity is O(1)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == nullptr)
        {
            new_node->data = value;
            new_node->next = head;
            head = new_node;
        }
        else
        {
            new_node->data = value;
            new_node->next = head;
            head = new_node;
        }
        return '1';
    }
    char delete_beg() // time complexity is O(1)
    {
        if (head == NULL)
        {
            return '#';
        }
        struct node *temp = head;
        char temp1;
        temp1 = head->data;
        head = head->next;
        free(temp);
        return temp1;
    }
    char push(int value) // time complexity is O(n)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;

        if (head == nullptr)
        {
            return insert_beg(value);
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            new_node->next = nullptr;
            new_node->data = value;
            temp->next = new_node;
        }
        return '1';
    }
    int pop() // time complexity is O(n)
    {
        if (head == nullptr)
        {
            return '#';
        }
        if (head->next == nullptr)
        {
            return delete_beg();
        }
        struct node *temp = head;
        struct node *temp1;
        char temp2;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp2 = temp->next->data;
        temp->next = nullptr;
        free(temp1);
        return temp2;
    }
    char peek() // time complexity is O(n)
    {
        if (head == nullptr)
        {
            return '#';
        }
        struct node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }
};

int main()
{
    sll s1;
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
            if (result == '1')
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