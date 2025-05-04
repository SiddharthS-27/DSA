// program to implement list ADT using an array of size 5
#include <cstdio>
#include <cstdlib>
#define size 5
class list
{
private:
    int arr[size];
    int cur;

public:
    list()
    {
        cur = 0;
    };
    int insert_beg(int value)
    {
        if (cur == size)
        {
            return 0;
        }
        else if (cur == 0)
        {
            arr[0] = value;
            cur++;
            return 1;
        }
        else
        {
            for (int i = cur; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
        }

        cur++;
        return 1;
    }
    int insert_end(int value)
    {
        if (cur == size)
        {
            return 0;
        }
        else if (cur == 0)
        {
            insert_beg(value);
        }
        else
        {
            arr[cur] = value;
            cur++;
        }
        return 1;
    }
    int insert_pos(int value, int pos)
    {
        if (pos == 0)
        {
            insert_beg(value);
        }
        else if (pos == cur)
        {
            insert_end(value);
        }
        else
        {
            for (int i = cur; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            cur++;
        }
        return 1;
    }
    int delete_beg()
    {
        int temp;
        if (cur == 0)
        {
            return -1;
        }
        temp = arr[0];
        for (int i = 0; i < cur; i++)
        {
            arr[i] = arr[i + 1];
        }
        cur--;
        return temp;
    }
    int delete_end()
    {
        int temp;
        if (cur == 0)
        {
            return -1;
        }
        temp = arr[cur - 1];
        cur--;
        return temp;
    }
    int delete_pos(int pos)
    {
        int temp;
        if (cur == 0)
        {
            return -1;
        }
        temp = arr[pos];
        for (int i = pos; i < cur; i++)
        {
            arr[i] = arr[i + 1];
        }
        cur--;
        return temp;
    }
    int search(int value)
    {
        if (cur == 0)
        {
            return -1;
        }
        for (int i = 0; i < cur; i++)
        {
            if (arr[i] == value)
            {
                return i;
            }
        }
        return -2;
    }
    void display()
    {
        for (int i = 0; i < cur; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    int rotate(int pos)
    {
        int temp[size];
        if (cur == 0)
        {
            return -1;
        }
        else if (cur != size)
        {
            return -2;
        }
        else
        {
            for (int i = 0; i < cur; i++) // creating copy of list
            {
                temp[i] = arr[i];
            }
            for (int i = 0; i < size; i++)
            {
                if (i + pos <= (size - 1))
                {
                    arr[i + pos] = temp[i];
                }
                else
                {
                    arr[(i + pos) - size] = temp[i];
                }
            }
        }
        return 1;
    }
};

int main()
{
    list l1;
    int choice, value, result, pos;
    while (1)
    {
        printf("\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\n");
        printf("Enter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 10)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }

        switch (choice)
        {
        case 1:
        {
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            result = l1.insert_beg(value);
            if (result == 1)
            {
                printf("Value %d has been inserted.\n", value);
            }
            else
            {
                printf("List is full.\n");
            }
            break;
        }
        case 2:
        {
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            result = l1.insert_end(value);
            if (result == 1)
            {
                printf("Value %d has been inserted.\n", value);
            }
            else
            {
                printf("List is full.\n");
            }
            break;
        }
        case 3:
        {
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            printf("Enter position to be inserted: ");
            scanf("%d", &pos);
            while (pos < 0 || pos > size - 1)
            {
                printf("Error. Enter a valid position.\n");
            }
            result = l1.insert_pos(value, pos);
            if (result == 1)
            {
                printf("Value %d has been inserted.\n", value);
            }
            else
            {
                printf("List is full.\n");
            }
            break;
        }
        case 4:
            result = l1.delete_beg();
            if (result == -1)
            {
                printf("List empty.\n");
            }
            else
            {
                printf("%d has been deleted.\n", result);
            }

            break;
        case 5:
            result = l1.delete_end();
            if (result == -1)
            {
                printf("List empty.\n");
            }
            else
            {
                printf("%d has been deleted.\n", result);
            }

            break;
        case 6:
            printf("Enter position to be deleted: ");
            scanf("%d", &pos);
            while (pos < 0 || pos > size - 1)
            {
                printf("Error. Enter a valid position.\n");
            }
            result = l1.delete_pos(pos);
            if (result == -1)
            {
                printf("List empty.\n");
            }
            else
            {
                printf("%d has been deleted.\n", result);
            }

            break;
        case 7:
        {
            printf("Enter value to search for: ");
            scanf("%d", &value);
            result = l1.search(value);
            if (result == -1)
            {
                printf("List empty.\n");
            }
            else if (result == -2)
            {
                printf("Element not found.\n");
            }
            else
            {
                printf("Element found at index %d.\n", result);
            }
            break;
        }
        case 8:
        {
            l1.display();
            break;
        }
        case 9:
        {
            printf("Enter how many spaces to shift right: ");
            scanf("%d", &pos);
            result = l1.rotate(pos);
            if (result == -1)
            {
                printf("List empty.\n");
            }
            else if (result == -2)
            {
                printf("List not full.\n");
            }
            else
            {
                printf("List rotated by %d spaces.\n", pos);
            }
            break;
        }
        case 10:
        {
            exit(0);
        }
        default:
            printf("Error.");
            break;
        }
    }
    return 0;
}
