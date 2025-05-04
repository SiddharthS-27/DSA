// program to implement queue using an int singly linked list
#include <iostream>
using namespace std;

class sll
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    sll()
    {
        head = NULL;
    };
    int insert_beg(int value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
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
        return 1;
    }
    int enqueue(int value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        if (head == NULL)
        {
            return insert_beg(value);
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            new_node->next = NULL;
            new_node->data = value;
            temp->next = new_node;
        }
        return 1;
    }

    int dequeue()
    {
        if (head == NULL)
        {
            return -1;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        int temp1;
        temp = head;
        temp1 = head->data;
        head = head->next;
        free(temp);
        return temp1;
    }
    int peek()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    sll q1;
    int choice, value, res;
    while (1)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter menu number of operation to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to enqueue: ";
            cin >> value;
            q1.enqueue(value);
            cout << value << " enqueued.\n";
            break;
        }
        case 2:
        {
            res = q1.dequeue();
            if (res == -1)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << res << " dequeued.\n";
            }
            break;
        }
        case 3:
        {
            res = q1.peek();
            if (res == -1)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Value at the front of the queue is " << res << "\n";
            }
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
        {
            cout << "Error. Enter valid menu number.\n";
        }
        }
    }
}
