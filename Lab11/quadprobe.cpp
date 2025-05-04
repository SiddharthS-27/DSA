#include <iostream>
#include <vector>
using namespace std;

class hash_table
{
    vector<int> table;
    int capacity;
    int size;

public:
    hash_table()
    {
        capacity = 10;
        size = 0;
        table.resize(capacity, -1);
    }
    int insert(int value) // best case: O(1), worst case: O(n)
    {
        if (size == capacity)
        {
            return -1;
        }
        int hash = value % capacity;
        int i = 0;
        while (i < capacity)
        {
            int index = (hash + i * i) % capacity;
            if (table[index] == -1)
            {
                table[index] = value;
                size++;
                return 1;
            }
            i++;
        }
        return -1;
    }
    int search(int value) // best case: O(1), worst case: O(n)
    {
        if (size == 0)
        {
            return -1;
        }
        int hash = value % capacity;
        int i = 0;
        while (i < capacity)
        {
            int index = (hash + i * i) % capacity;
            if (table[index] == -1)
            {
                return -2;
            }
            if (table[index] == value)
            {
                return index;
            }
            i++;
        }
        return -2;
    }
    int del(int value) // best case: O(1), worst case: O(n)
    {
        if (size == 0)
        {
            return -1;
        }
        int res = search(value);
        if (res < 0)
        {
            return -2;
        }
        table[res] = -1;
        size--;
        return 1;
    }
    void display() // O(n)
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << i << "  ";
        }
        cout << "\n";
        for (int i = 0; i < capacity; ++i)
        {
            cout << table[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    hash_table h1;
    int choice, value, res;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter menu number of operation to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            res = h1.insert(value);
            if (res == 1)
                cout << "Element " << value << " successfully inserted.\n";
            else
                cout << "Table full.\n";
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            res = h1.del(value);
            if (res == -2)
                cout << "Element " << value << " not found.\n";
            else if (res == -1)
                cout << "Table empty.\n";
            else
                cout << "Element " << value << " successfully deleted.\n";
            break;
        case 3:
            cout << "Enter value to search for: ";
            cin >> value;
            res = h1.search(value);
            if (res == -2)
                cout << "Element " << value << " not found.\n";
            else if (res == -1)
                cout << "Table empty.\n";
            else
                cout << "Element " << value << " found.\n";
            break;
        case 4:
            h1.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid menu number.\n";
        }
    }
    return 0;
}
