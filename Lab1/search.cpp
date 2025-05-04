// Program to search an array
# include <cstdio>
# include <cstdlib>
# include "sort.h"

// Function prototypes
int linear_search (int*, int, int);
int binary_search (int*, int, int, int);

// Main block
int main()
{
    int choice, size, ele, result;

    printf("Enter size of input array: ");
    scanf("%d", &size);
    while (size <= 0)
    {
        printf("Error. Enter a positive integer value for size: ");
        scanf("%d", &size);
    }

    int* arr = (int*)malloc(size*sizeof(int));

    printf("Enter array elements: ");
    for (int i=0;i<size;i++)
    {
        scanf("%d", arr+i);
    }

    while (1)
    {
        printf("\n1. Linear Search\n2. Binary Search\n3. Exit\n");
        printf("\nEnter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        switch (choice)
        while (choice < 1 || choice >3)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }
        {
            case 1:
                printf("Enter element to be searched for: ");
                scanf("%d", &ele);
                result = linear_search(arr, size, ele);
                if(result != -1)
                {
                    printf("Element found at index %d.\n", result);
                }
                else {
                    printf("Element not found.\n");
                }
                break;
            case 2:
                printf("Enter element to be searched for: ");
                scanf("%d", &ele);
                bubble_sort(arr, size);
                result = binary_search(arr, ele, 0, size-1);
                if(result != -1)
                {
                    printf("Element found at index %d.\n", result);
                }
                else {
                    printf("Element not found.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Error.\n");
                break;
        }
    }
}

// Function declarations
int linear_search (int* ptr, int size, int ele)
{
    for (int i=0;i<size;i++)
    {
        if (ptr[i] == ele)
        {
            return i;
        }
    }
    return -1;  
}

int binary_search (int* ptr, int ele, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + (high-low)/2);

        if(ptr[mid]==ele)
        {
            return mid;
        }
        if(ptr[mid] < ele)
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}