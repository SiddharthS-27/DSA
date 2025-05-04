// program to implement Prim's algorithm
#include <iostream>
using namespace std;
#include "adjm.h"
#include "minheap.h"
#include <climits>

int main()
{
    int vertices;
    cout << "Enter vertices: ";
    cin >> vertices;
    adjmat a1(vertices);
    int choice, res;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Prim's algorithm\n6. Kruskal's algorithm\n7. Dijkstra's algorithm\n8. Exit\n";
        cout << "Enter menu number of operation to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int u, v, weight;
            cout << "Enter nodes u, v, weight between which to create edge (from u -> v): ";
            scanf("%d %d %d", &u, &v, &weight);
            while ((u < 0 || u >=vertices) || (v < 0 || v >=vertices) && weight <= 0)
            {
                cout << "Error. Enter valid nodes within matrix size and valid weight: ";
                scanf("%d %d %d", &u, &v, &weight);
            }
            res = a1.insert(u, v, weight);
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
            int u, v;
            cout << "Enter nodes u, v between which to delete edge (from u -> v): ";
            scanf("%d %d", &u, &v);
            while ((u < 0 || u >=vertices) || (v < 0 || v >=vertices))
            {
                cout << "Error. Enter valid nodes within matrix size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.del(u, v);
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
            int u, v;
            cout << "Enter nodes u, v, between which to search if edge is present (from u -> v): ";
            scanf("%d %d", &u, &v);
            while ((u < 0 || u >=vertices) || (v < 0 || v >=vertices))
            {
                cout << "Error. Enter valid nodes within matrix size: ";
                scanf("%d %d", &u, &v);
            }
            res = a1.search(u, v);
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
            // Prim's algorithm
            int sum=0;
            heap h1(vertices*vertices);
            vector<int> visited(vertices, 0);
            node newnode;
            newnode.weight = 0;
            newnode.vertex = 0;
            newnode.parent = -1;
            h1.insert(newnode);
            vector<vector<int>> matrix = a1.getMatrix();
            while (h1.getCur() != 0)
            {
                newnode = h1.del();
                if (visited[newnode.vertex]==0)
                {
                    sum+=newnode.weight;
                    visited[newnode.vertex]=1;
                    if (newnode.parent != -1)
                    {
                        cout << newnode.parent << " - " << newnode.vertex << ": " << newnode.weight << endl;
                    }
                    for (int i=0;i<vertices;++i)
                    {
                        if((matrix[newnode.vertex][i] != 0) && visited[i] == 0)
                        {
                            node neighbour;
                            neighbour.weight = matrix[newnode.vertex][i];
                            neighbour.vertex = i;
                            neighbour.parent = newnode.vertex;
                            h1.insert(neighbour);
                        }
                    }
                }
                
            }
            cout << "Total cost is: " << sum << endl;
            break;
        }
        case 6:
        {
            int sum=0;
            heap h1(vertices);
            vector<int> visited(vertices, 0);
            // adjmat matrix2(vertices);
            vector<vector<int>> matrix = a1.getMatrix();
            //vector<int> edgeCount(vertices, 0);
            node newnode;
            for (int i=0;i<vertices;++i)
            {
                for (int j=0;j<vertices;++j)
                {
                    if(matrix[i][j] != 0)
                    {
                        newnode.weight = matrix[i][j];
                        newnode.vertex = j;
                        newnode.parent = i;
                        matrix[j][i] = 0;
                        h1.insert(newnode);
                    }
                    
                }
            }
            while (h1.getCur() != 0)
            // int i = 0;
            // while (i<vertices)
            {
                newnode = h1.del();
                if (visited[newnode.vertex]==0)
                {
                    if(!(visited[newnode.vertex]==1 && visited[newnode.parent]==1))
                    {   
                        sum+=newnode.weight;
                        visited[newnode.vertex]=1;
                        visited[newnode.parent]=1;
                        cout << newnode.parent << " - " << newnode.vertex << ": " << newnode.weight << endl;
                    }
                    // else if((edgeCount[newnode.vertex] <2) && (edgeCount[newnode.parent] <2))
                    // {
                    //     sum+=newnode.weight;
                    //     edgeCount[newnode.vertex]+=1;
                    //     edgeCount[newnode.parent]+=1;
                    //     cout << newnode.parent << " - " << newnode.vertex << ": " << newnode.weight << endl;
                    // }
                }
            }
            cout << "Total cost is: " << sum << endl;
            break;

        }
        case 7:
        {
            // Dijkstra's algorithm
            int src, dest;
            cout << "Enter source vertex: ";
            cin >> src;
            while (src < 0 || src >= vertices)
            {
                cout << "Error. Enter a valid vertex: ";
                cin >> src;
            }
            cout << "Enter destination vertex: ";
            cin >> dest;
            while (dest < 0 || dest >= vertices)
            {
                cout << "Error. Enter a valid vertex: ";
                cin >> dest;
            }
            vector <int> dist(vertices,INT_MAX);
            heap h2(vertices*vertices);
            vector<vector<int>> matrix = a1.getMatrix();
            node newnode;
            newnode.vertex=src;
            newnode.weight=0;
            dist[0]=0;

            h2.insert(newnode);

            while(h2.getCur()!=0){
                node rootNode=h2.del();
                int rNvert=rootNode.vertex;

                for (int i=0;i<vertices;i++){
                    if (matrix[rNvert][i]!=0 && dist[rNvert]+matrix[rNvert][i]<dist[i]){
                        node newnode;
                        newnode.vertex=i;
                        newnode.weight=matrix[rNvert][i]+dist[rNvert];
                        h2.insert(newnode);
                        dist[i]=dist[rNvert]+matrix[rNvert][i];
                    }
                }
            }
            cout<<"\nDistance between all nodes from "<<src<<":"<<endl;
            cout<<"src - dest"<<endl;
            for (int i=0;i<vertices;i++){
                if (i==src){
                    continue;
                }
                cout<<"\n"<<src<<" - "<<dist[i]<<endl;
            }
            cout<<"\nDistance between "<<src<<" and "<<dest<<" is "<<dist[dest]<<endl;
            
        }
        case 8:
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