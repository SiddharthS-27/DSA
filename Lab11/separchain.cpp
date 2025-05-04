#include <iostream>
#include "sll.h"
using namespace std;

class hash_table
{
    sll table[10];
    int capacity;

public:
    hash_table()
    {
        capacity = 10;
    }
    int insert(int value) // let l=length of linked list at each index, time complexity is O(l)
    {
        int hash = value % capacity;
        if (table[hash].search(value) >= 0)
        {
            return 0;
        }
        return table[hash].insert_end(value);
    }
    int search(int value) // O(l)
    {
        int hash = value % capacity;
        int res = table[hash].search(value);
        if (res >= 0)
        {
            return hash;
        }
        return -1;
    }
    int del(int value) // O(l)
    {
        int hash = value % capacity;
        int pos = table[hash].search(value);
        if (pos < 0)
        {
            return -1;
        }
        table[hash].delete_pos(pos);
        return 1;
    }
};

int main()
{
    hash_table h1;
    int choice, value, res;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Exit\n";
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
                cout << "Element already exists.\n";
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            res = h1.del(value);
            if (res == -1)
                cout << "Element " << value << " not found.\n";
            else
                cout << "Element " << value << " successfully deleted.\n";
            break;
        case 3:
            cout << "Enter value to search for: ";
            cin >> value;
            res = h1.search(value);
            if (res == -1)
                cout << "Element " << value << " not found.\n";
            else
                cout << "Element " << value << " found in chain " << res << ".\n";
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid menu number.\n";
        }
    }
    return 0;
}
