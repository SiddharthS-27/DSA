// program to implement adjacency matrix
#include <iostream>
using namespace std;
#include <vector>
#define order 4
class adjmat
{
    vector<vector<int>> matrix;

public:
    adjmat()
    {
        matrix.resize(order);
        for (int i = 0; i < order; ++i)
        {
            matrix[i].resize(4, 0);
        }
    };
    int insert(int u, int v)
    {
        if (matrix[u][v] == 1)
        {
            return -1;
        }
        else
        {
            matrix[u][v] = 1;
            return 1;
        }
    }
    int del(int u, int v)
    {
        if (matrix[u][v] == 0)
        {
            return -1;
        }
        else
        {
            matrix[u][v] = 0;
            return 1;
        }
    }
    int search(int u, int v)
    {
        if (matrix[u][v] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        cout << "\n";
        for (int i=0;i<order;++i)
        {
            cout << "\t(" << i+1 << ")";
        }
        cout << "\n";
        for (int i = 0; i < order; ++i)
        {
            cout << "(" << i+1 << ")\t";
            for (int j = 0; j < order; ++j)
            {
                cout << matrix[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main()
{
    adjmat a1;
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
            while ((u <= 0 || u > order) || (v <= 0 || v > order))
            {
                cout << "Error. Enter valid nodes within matrix size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.insert(u-1, v-1);
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
            while ((u <= 0 || u > order) || (v <= 0 || v > order))
            {
                cout << "Error. Enter valid nodes within matrix size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.del(u-1, v-1);
            if (res == 1)
            {
                cout << "Edge successfully deleted.\n";
            }
            else
            {
                cout << "Edge not present.\n";
            }
            break;
        }
        case 3:
        {
            int u = 0, v = 0;
            cout << "Enter nodes u, v between which to search if a directed edge is present (from u -> v): ";
            scanf("%d %d", &u, &v);
            while ((u <= 0 || u > order) || (v <= 0 || v > order))
            {
                cout << "Error. Enter valid nodes within matrix size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.search(u-1, v-1);
            if (res == 1)
            {
                cout << "Edge found.\n";
            }
            else
            {
                cout << "Edge not found.\n";
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