// Program to sort a given array in ascending order
# include <cstdio>
# include <cstdlib>

// Function prototypes
void bubble_sort(int*, int);
void selection_sort(int*, int);
void insertion_sort(int*, int);

// Main block
int main()
{
    int choice, size;

    printf("Enter size of array to be sorted: ");
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
        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n");
        printf("\nEnter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        while (choice < 1 || choice >4)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }
        switch (choice)
        {
            case 1:
                bubble_sort(arr, size);
                printf("Sorted array is:\n");
                for (int i=0;i<size;i++)
                {
                    printf("%d\n", *(arr+i));
                }   
                break;
            case 2:
                selection_sort(arr, size);
                printf("Sorted array is:\n");
                for (int i=0;i<size;i++)
                {
                    printf("%d\n", *(arr+i));
                } 
                break;
            case 3:
                insertion_sort(arr, size);
                printf("Sorted array is:\n");
                for (int i=0;i<size;i++)
                {
                    printf("%d\n", *(arr+i));
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Error.\n");
                break;
        }
    }

}

// Function declarations
void bubble_sort(int* ptr, int size)
{
    int temp=0;
    for (int i=0;i<size-1;i++)
    {
        for (int j=0;j<size-1-i;j++)
        {
            if (*(ptr+j) > *(ptr+j+1))
            {
                temp = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = temp;
            }
        }
    }

}

void selection_sort(int* ptr, int size)
{
    int temp;
    for (int i=0;i<size-1;i++)
    {
        int min_index = i;
        for (int j=i+1;j<size;j++)
        {
            if (ptr[j] < ptr[min_index])
            {

                min_index = j;

            }
        }
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+min_index);
        *(ptr+min_index) = temp;
    }
}

void insertion_sort(int* ptr, int size)
{
    for (int i =1;i<size;i++)
    {
        int key = ptr[i];
        int j = i-1;

        while (j >= 0 && ptr[j] > key)
        {
            ptr[j+1] = ptr[j];
            j--;
        }
        ptr[j+1] = key;
    }
}