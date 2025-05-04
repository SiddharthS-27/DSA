// program to implement participant-participant strength difference calculation question 
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int testnum, participants;
    cout << "Enter number of test cases:\n";
    cin >> testnum;
    cin.ignore(); 
    vector<vector<int>> data(testnum);
    string line;
    int num;

    // Getting the input
    for (int i = 0; i < testnum; i++)
    {
        cout << "For test case " << i+1 << ":\n";
        cout << "Enter the number of participants:\n";
        cin >> participants;
        cin.ignore();
        data[i].push_back(participants);
        cout << "Enter the strengths of the participants:\n";
        getline(cin, line);
        stringstream ss(line);

        while (ss >> num)
        {
            data[i].push_back(num);
        }
        ss.clear();
        ss.str("");
    }

    // Calculating and printing the output
    cout << "Output:\n";
    for (int i = 0; i < testnum; i++)
    {
        int max =data[i][1], prev_max=-1; // assuming max is the first strength value. prev_max tracks the second-highest strength (to subtract from max) 
        for (int j=2;j<(data[i][0]+1);j++)
        {
            if (data[i][j]>max)
            {
                prev_max = max;
                max = data[i][j];
            }
            else {
                if (data[i][j] != max && data[i][j] > prev_max) // if the first strength value is actually the highest strength, then prev_max will never be updated. To solve that problem, we update prev_max from time to time
                {
                    prev_max = data[i][j];
                }
            }
        }
        if (prev_max == -1) // if prev_max wasn't updated, then it means all elements are = max, so set prev_max to max
        {
            prev_max = max;
        }
        for (int j = 1;j<(data[i][0]+1);j++)
        {
            if (data[i][j] == max)
            {
                data[i][j] = max-prev_max;
            }
            else {
                data[i][j] = data[i][j] - max;
            }
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
    return 0; 
}