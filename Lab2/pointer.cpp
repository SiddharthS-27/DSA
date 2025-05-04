// program to check if a number is Armstrong, Perfect or a palindrome
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <string.h>

// Function prototypes
int countdigits(int *);
int *getdigits(int *, int *);
int is_palindrome(int *, int *, int *);
int is_armstrong(int *, int *, int *);
int is_perfect(int *);

int main()
{
    int *choice = (int *)malloc(sizeof(int));
    int *num = (int *)malloc(sizeof(int));
    int *result = (int *)malloc(sizeof(int));

    while (1)
    {
        printf("\n1. Palindrome\n2. Armstrong Number\n3. Perfect Number\n4. Exit\n");
        printf("\nEnter menu number of operation you want to perform: ");
        scanf("%d", choice);
        while (*choice < 1 || *choice >4)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", choice);
        }
        switch (*choice)
        {
        case 1:
        {
            printf("\nEnter number: ");
            scanf("%d", num);
            while (*num<0)
            {
                printf("Error. Enter a number greater than 0: ");
                scanf("%d", num);
            }
            int *size = (int *)malloc(sizeof(int));
            *size = countdigits(num);

            int *digits = (int *)calloc(*size, sizeof(int));
            digits = getdigits(num, size);

            *result = is_palindrome(num, digits, size);

            if (*result == 1)
            {
                printf("%d is a palindrome.\n", *num);
            }
            else
            {
                printf("%d is not a palindrome.\n", *num);
            }
            break;
        }

        case 2:
        {
            printf("\nEnter number: ");
            scanf("%d", num);
            while (*num<0)
            {
                printf("Error. Enter a number greater than 0: ");
                scanf("%d", num);
            }
            if (*num == 0)
            {
                printf("%d is an Armstrong number.\n", *num);
                break;
            }
            int *size = (int *)malloc(sizeof(int));
            *size = countdigits(num);

            int *digits = (int *)calloc(*size, sizeof(int));
            digits = getdigits(num, size);
            *result = is_armstrong(num, digits, size);

            if (*result == 1)
            {
                printf("%d is an Armstrong number.\n", *num);
            }

            else
            {
                printf("%d is not an Armstrong number.\n", *num);
            }

            break;
        }
        case 3:
        {
            printf("\nEnter number: ");
            scanf("%d", num);
            while (*num<0)
            {
                printf("Error. Enter a number greater than 0: ");
                scanf("%d", num);
            }
            *result = is_perfect(num);

            if (*result == 1)
            {
                printf("%d is a perfect number.\n", *num);
            }
            else
            {
                printf("%d is not a perfect number.\n", *num);
            }

            break;
        }

        case 4:
        {
            exit(0);
        }
        default:
        {
            printf("Error.\n");
        }
        }
    }
}

// Function declarations
int countdigits(int *num)
{
    int *count = (int *)malloc(sizeof(int));
    *count = 0;
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    if (*temp == 0)
    {
        return 1;
    }
    while (*temp > 0)
    {
        (*count)++;
        *temp /= 10;
    }

    return *count;
}
int *getdigits(int *num, int *size)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 1;
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    int *digits = (int *)calloc(*size, sizeof(int));

    while (*temp > 0)
    {
        digits[*size - *i] = *temp % 10;
        *temp /= 10;
        (*i)++;
    }
    return digits;
}

int is_armstrong(int *num, int *digits, int *size)
{
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    int *i = (int *)malloc(sizeof(int));
    *i = 0;
    for (*i = 0; *i < *size; (*i)++)
    {
        *sum += pow(digits[*i], *size);
    }
    if (*sum == *num)
    {
        return 1;
    }
    return 0;
}

int is_palindrome(int *num, int *digits, int *size)
{
    int *i = (int *)malloc(sizeof(int));
    for (*i = 0; *i < ((*size) / 2); (*i)++)
    {
        if (digits[*i] != digits[*i + ((*size) - 1)])
        {
            return 0;
        }
    }
    return 1;
}

int is_perfect(int *num)
{
    int *i = (int *)malloc(sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    for (*i = 1; *i < *num; (*i)++)
    {
        if ((*num % *i) == 0)
        {
            *sum += *i;
        }
    }
    if (*sum == *num)
    {
        return 1;
    }
    return 0;
}