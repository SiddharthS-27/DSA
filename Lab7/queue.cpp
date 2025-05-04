// program to implement a queue ADT using int array

#include <iostream>
#define size 5
using namespace std;

class queue
{
    int arr[size];
    int front, rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    };
    int enqueue(int val)
    {
        if (rear + 1 == size)
        {
            return -1;
        }
        if (front == -1)
        {
            front++;
        }
        arr[rear + 1] = val;
        rear++;
        return 1;
    }
    int dequeue()
    {
        if (front == -1)
        {
            return -1;
        }
        if (front == rear)
        {
            int temp = arr[front];
            front = -1;
            rear = -1;
            return temp;
        }
        front++;
        return arr[front - 1];
    }
    int peek()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    queue q1;
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
            res = q1.enqueue(value);
            if (res == -1)
            {
                cout << "Queue is full.\n";
            }
            else
            {
                cout << value << " enqueued.\n";
            }
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
