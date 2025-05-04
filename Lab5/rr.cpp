// program to perform round-robin scheduling
# include <cstdio>
# include <cstdlib>
# include "circ.h"


int main()
{
    sll l1;
    int choice, time, res;
    while (1)
    {
        printf("\n1. Insert process\n2. Execute\n3. Exit\n");
        printf("Enter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 3)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }
        switch (choice)
        {
        case 1:
        {
            printf("Enter integer time: ");
            scanf("%d", &time);
            while (time <= 0)
            {
                printf("Error. Enter a valid process time: ");
                scanf("%d", &time);
            }
            res = l1.insert_end(time);
            if (res == 1)
            {
                printf("%d has been inserted.\n", time);
            }
            break;
        }
        case 2:
        {
            int temp;
            printf("Enter fixed processing time: ");
            scanf("%d", &time);
            while (time <= 0)
            {
                printf("Error. Enter a valid process time: ");
                scanf("%d", &time);
            }
            res = l1.execute(time);
            if (res == -1)
            {
                printf("List is empty.\n");
            }
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Error.\n");
            break;
        }
        }
    }

}

