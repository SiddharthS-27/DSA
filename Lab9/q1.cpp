// program to implement Nene's game
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int testnum;
    cout << "Enter number of test cases:\n";
    cin >> testnum;
    cin.ignore(); // ignoring the \n (enter key pressed after inputting testnum) so that the next getline() call doesn't take \n as input
    vector<vector<int>> data(testnum); // vector of vectors: a vector 'data' of size testnum contains multiple vectors, each one for storing data about each testcase
    string line;
    int num;

    // Getting the input
    for (int i = 0; i < testnum; i++)
    {
        cout << "For test case " << i+1 << ":\n";
        cout << "Enter k (the length of the sequence a) and q (the number of values you should solve this problem for):\n";
        getline(cin, line);
        stringstream ss(line);

        while (ss >> num)
        {
            data[i].push_back(num);
        }
        ss.clear(); // clearing flags associated with the ss buffer and resetting it to "" (empty buffer string)
        ss.str("");
        cout << "Enter k integers (the sequence a):\n";
        getline(cin, line);
        ss.str(line);

        while (ss >> num)
        {
            data[i].push_back(num);
        }
        ss.clear();
        ss.str("");
        cout << "Enter q integers (the numbers of players in the game initially):\n";
        getline(cin, line);
        ss.str(line);

        while (ss >> num)
        {
            data[i].push_back(num);
        }
        ss.clear();
        ss.str("");
    }

    // Calculating and printing the output
    cout << "Output:\n";
    for (int i = 0; i < testnum; i++) // for each testcase
    {
        for (int j = (2 + data[i][0]); j < data[i].size(); j++) // for each q (number of players in game initially)
        {
            while (data[i][j] >= data[i][2]) // while the value of q is >= smallest number in sequence a (which is the first element of the sequence, and hence data[i][2] (data[i][0] contains sequence length, data[i][1] contains q length))
            {
                for (int k = 2; k < (2 + data[i][1]); k++)
                {
                    if (data[i][k] <= data[i][j])
                    {
                        data[i][j]--; // if person removed decrement q count 
                    }
                }
            }
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}