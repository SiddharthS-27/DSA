// program to implement an adjacency list
#include <iostream>
using namespace std;
#include "sll.h"
#include <vector>
#define size 4

class adjlist {
    vector<sll> list;
    public:
    adjlist()
    {
        list.resize(size);
    };
    int insert(int u, int v)
    {
        if (list[u-1].search(v) == -1 || list[u-1].search(v) == -2)
        {
            list[u-1].insert_beg(v);
            return 1;    
        }
        return -1;
    }
    int del(int u, int v)
    {
        int res = list[u-1].search(v);
        if (res == -1 || res == -2)
        {
            return -1;    
        }
        int temp = list[u-1].delete_pos(res);
        return temp;
    }
    void display()
    {
        for (int i=0;i<size;++i)
        {
            list[i].display();
        }
    }
    int search(int u, int v)
    {
        
        if (list[u-1].search(v) == -1 || list[u-1].search(v) == -2)
        {
            return -1;
        }
        return 1;
    }
};

int main()
{
    adjlist a1;
    int choice, res;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter menu number of operation to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int u = 0, v = 0;
            cout << "Enter nodes u, v between which to create a directed edge (from u -> v): ";
            scanf("%d %d", &u, &v);
            while ((u <= 0 || u > size) || (v <= 0 || v > size))
            {
                cout << "Error. Enter valid nodes within graph size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.insert(u, v);
            if (res == 1)
            {
                cout << "Edge successfully created.\n";
            }
            else
            {
                cout << "Edge already present.\n";
            }
            break;
        }
        case 2:
        {
            int u = 0, v = 0;
            cout << "Enter nodes u, v between which to delete a directed edge (from u -> v): ";
            scanf("%d %d", &u, &v);
            while ((u <= 0 || u > size) || (v <= 0 || v > size))
            {
                cout << "Error. Enter valid nodes within graph size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.del(u, v);
            if (res == -1)
            {
                cout << "Edge not found.\n";
            }
            else
            {
                cout << "Edge deleted.\n";
            }
            break;
        }
        case 3:
        {
            int u = 0, v = 0;
            cout << "Enter nodes u, v between which to search if a directed edge is present (from u -> v): ";
            scanf("%d %d", &u, &v);
            while ((u <= 0 || u > size) || (v <= 0 || v > size))
            {
                cout << "Error. Enter valid nodes within matrix size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.search(u, v);
            if (res == -1)
            {
                cout << "Edge not found.\n";
            }
            else
            {
                cout << "Edge found.\n";
            }
            break;
        }
        case 4:
        {
            a1.display();
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid menu number.\n";
        }
        }
    }
    return 0;
}