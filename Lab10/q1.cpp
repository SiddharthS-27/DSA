// program to solve Polycarp's problem
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int testnum, length;
    cout << "Enter number of test cases:\n";
    cin >> testnum;
    cin.ignore();
    vector<vector<int>> data(testnum);
    string line;
    int num;

    // Getting the input
    for (int i = 0; i < testnum; i++)
    {
        cout << "For test case " << i + 1 << ":\n";
        cout << "Enter the length of the sequence a:\n";
        cin >> length;
        cin.ignore();
        data[i].push_back(length);
        cout << "Enter the sequence a:\n";
        getline(cin, line);
        stringstream ss(line);

        while (ss >> num)
        {
            data[i].push_back(num);
        }
        ss.clear();
        ss.str("");
        cout << "\n";
    }
    vector<int> store;
    int flag;
    // Calculating and printing the output
    for (int i = 0; i < testnum; i++)
    {
        if ((data[i].size()) == 2)
        {
            cout << "0\n";
            continue;
        }
        flag = 0;
        store.clear();
        store.push_back(data[i].back());
        for (int j = ((data[i].size()) - 2); j > 0; j--)
        {
            for (int k = 0; k < store.size(); k++)
            {
                if (data[i][j] == store[k])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
            store.push_back(data[i][j]);
        }
        cout << ((data[i].size() - 1) - (store.size())) << "\n";
    }
    return 0;
}