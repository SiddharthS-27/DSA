// program to implement the word game
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
    vector<vector<string>> data(testnum);
    string line;
    string word;

    // Getting the input
    for (int i = 0; i < testnum; i++)
    {
        cout << "For test case " << i + 1 << ":\n";
        cout << "Enter the number of words written by each person:\n";
        cin >> length;
        cin.ignore();
        cout << "Enter words:\n";
        for (int j = 0; j < 3; j++)
        {
            getline(cin, line);
            stringstream ss(line);
            while (ss >> word)
            {
                data[i].push_back(word);
            }
            ss.clear();
            ss.str("");
        }
        cout << "\n";
    }

    // Calculating and printing the output
    int p1, p2, p3, match2, match3;
    int wordnum, flag;
    vector<int> allmatch;
    for (int i = 0; i < testnum; i++)
    {
        match2 = 0, match3 = 0;
        p1 = 0, p2 = 0, p3 = 0;
        wordnum = ((data[i].size()) / 3);
        for (int j = 0; j < wordnum; j++)
        {
            flag = 0;
            for (int k = wordnum; k < (2 * wordnum); k++)
            {
                if (data[i][j] == data[i][k])
                {
                    flag = 1;
                    p1++, p2++;
                    match2++;
                    break;
                }
            }
            for (int k = (2 * wordnum); k < (data[i].size()); k++)
            {
                if (data[i][j] == data[i][k])
                {
                    if (flag == 1)
                    {
                        p1--, p2--;
                        allmatch.push_back(k);
                    }
                    else
                    {
                        flag = 1;
                        p1++, p3++;
                    }
                    match3++;

                    break;
                }
            }
            if (flag == 0)
            {
                p1 += 3;
            }
        }
        int allflag;
        for (int j = wordnum; j < (2 * wordnum); j++)
        {
            for (int k = (2 * wordnum); k < (data[i].size()); k++)
            {
                allflag = 0;
                if (data[i][j] == data[i][k])
                {
                    for (int i = 0; i < (allmatch.size()); i++)
                    {
                        if (k == allmatch[i])
                        {
                            allflag = 1;
                            break;
                        }
                    }

                    if (allflag != 1)
                    {
                        match2++;
                        match3++;
                        p2++;
                        p3++;
                    }
                }
            }
        }
        p2 += ((wordnum - match2) * 3);
        p3 += ((wordnum - match3) * 3);
        cout << p1 << " " << p2 << " " << p3 << "\n";
    }
}