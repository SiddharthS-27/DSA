// program to solve the Tower of Hanoi problem
#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter number of towers: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number of blocks in each tower " << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 1; i < size; i++) {
      
        int min_idx = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
              
                
                min_idx = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    for (int i = 1; i < size; i++)
    {
        while (arr[0] < arr[i])
        {
            arr[0]++;
            arr[i]--;
        }
    }
    cout << "The maximum number of blocks Tower 1 can have is " << arr[0] << "\n";

    return 0;
}
