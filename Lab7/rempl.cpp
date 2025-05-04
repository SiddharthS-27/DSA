// program to remove '+' symbol and immediate left non '+' symbol from a string
# include <iostream>
# include <string>
# include "slls.h"
using namespace std;

int main()
{
    sll s1;
    string ip, op;
    cout << "Enter input string: ";
    getline(cin, ip);
    for (int i=0;i<ip.length();i++)
    {
        if (ip[i] == '+')
        {
            s1.pop();
        }
        else {
            s1.push(ip[i]);
        }
    }
    while (s1.peek() != '\0')
    {
        op += s1.pop();
    }
    string rev(op.rbegin(), op.rend());
    cout << rev << endl;
    return 0;
}