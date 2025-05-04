// program to implement priority queue ADT using a max heap
#include <iostream>
using namespace std;
class priorityQueue
{
    int max_heap[10];
    int cur;

public:
    priorityQueue()
    {
        cur = 0;
    }
    void swap(int x, int y) 
    {
        int temp = max_heap[x];
        max_heap[x] = max_heap[y];
        max_heap[y] = temp;
    }
    void heapifyUp()
    {
        int i = cur;
        while (i > 1 && (max_heap[i] > max_heap[i / 2]))
        {
            swap(i, i / 2);
            i /= 2;
        }
    }
    void heapifyDown()
    {

        int i = 1;
        while (2 * i <= cur)
        {
            int largest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= cur && max_heap[left] > max_heap[largest])
                largest = left;

            if (right <= cur && max_heap[right] > max_heap[largest])
                largest = right;

            if (largest != i)
            {
                swap(i, largest);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }

    void insert(int value) // O(log(n))
    {
        cur++;
        max_heap[cur] = value;
        heapifyUp();
    }
    int del() // O(log(n))
    {
        if (cur == 0)
        {
            return -1;
        }
        int temp = max_heap[1];
        max_heap[1] = max_heap[cur];
        cur--;
        heapifyDown();
        return temp;
    }
    void display() // O(n)
    {
        for (int i = 1; i <= cur; i++)
        {
            cout << max_heap[i] << " ";
        }
        cout << "\n";
    }
    int search(int value) // O(n)
    {
        if (cur == 0)
        {
            return -1;
        }
        for (int i = 1; i <= cur; i++)
        {
            if (value == max_heap[i])
            {
                return 1;
            }
        }
        return 0;
    }
    int sort() // O(nlog(n)) (because del() is log(n) and del() is called n times)
    {
        if (cur == 0)
        {
            return -1;
        }
        int final_cur = cur, i = 0;
        int arr[10];
        while (cur > 0)
        {
            arr[i++] = del();
        }
        cout << "Sorted heap is: ";
        for (int j = 0; j < final_cur; j++)
        {
            cout << arr[j] << " ";
            insert(arr[j]); // restore heap (new display order may be different, but heap property is maintained)
        }
        cout << "\n";
        return 1;
    }
};

int main()
{
    priorityQueue q1;
    int choice, value, res;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort\n6. Exit\n";
        cout << "Enter menu number of operation to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to insert: ";
            cin >> value;
            q1.insert(value);
            break;
        }
        case 2:
        {
            res = q1.del();
            if (res == -1)
            {
                cout << "Queue empty.\n";
            }
            else
            {
                cout << res << " deleted.\n";
            }
            break;
        }
        case 3:
        {
            q1.display();
            break;
        }
        case 4:
        {
            cout << "Enter value to search for: ";
            cin >> value;
            res = q1.search(value);
            if (res == 1)
            {
                cout << "Value found.\n";
            }
            else if (res == -1)
            {
                cout << "Queue empty.\n";
            }
            else
            {
                cout << "Value not found.\n";
            }
            break;
        }
        case 5:
        {
            res = q1.sort();
            if (res == 1)
            {
                cout << "Sorted.\n";
            }
            if (res == -1)
            {
                cout << "Queue empty.\n";
            }
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid menu number.\n";
        }
        }
    }
}