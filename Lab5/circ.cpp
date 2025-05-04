#include <cstdio>
#include <cstdlib>

class sll
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    sll()
    {
        head = NULL;
    }

    int insert_beg(int value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        new_node->data = value;

        if (head == NULL)
        {
            new_node->next = new_node;
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            new_node->next = head;
            temp->next = new_node;
            head = new_node;
        }
        return 1;
    }

    int insert_end(int value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        if (head == NULL)
        {
            return insert_beg(value);
        }

        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        new_node->data = value;
        new_node->next = head;
        temp->next = new_node;

        return 1;
    }

    int insert_pos(int value, int pos)
    {
        if (pos == 0)
        {
            return insert_beg(value);
        }
        if (pos > getlen() || pos < 0) // checking if input position is > than list size
        {
            return -1;
        }
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->data = value;
        new_node->next = temp->next;
        temp->next = new_node;

        return 1;
    }

    int delete_beg()
    {
        if (head == NULL)
            return -1;

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        int temp1;

        temp1 = head->data;

        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }
        return temp1;
    }

    int delete_end()
    {
        if (head == NULL)
            return -1;

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        int temp2;

        temp = head;

        if (head->next == head)
        {
            temp2 = head->data;
            free(head);
            head = NULL;
        }
        else
        {
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            temp1 = temp->next;
            temp2 = temp1->data;
            temp->next = head;
            free(temp1);
        }
        return temp2;
    }

    int delete_pos(int pos)
    {
        if (head == NULL)
            return -1;
        if (pos > getlen() || pos < 0)
        {
            return -2;
        }
        if (pos == 0)
        {
            return delete_beg();
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        int temp2;

        temp = head;

        

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;

        }

        temp1 = temp->next;
        temp->next = temp->next->next;
        temp2 = temp1->data;
        free(temp1);

        return temp2;
    }

    int search(int value)
    {
        if (head == NULL)
            return -2;

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        int i = 0;

        while (temp->next != head);
        {
            if (temp->data == value)
                return i;
            temp = temp->next;
            i++;
        } 
        if (temp->data == value)
            return i;

        return -1;
    }

    void display()
    {
        if (head == NULL)
        {
            printf("The list is empty.\n");
            return;
        }

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;

        printf("%d", temp->data);
        temp = temp->next;

        while (temp != head)
        {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
    }
    int getlen() // to get size of list
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        int count = 1;
        while (temp -> next != head)
        {
            count++;
            temp = temp -> next;
        }
        return count;
    }
};

int main()
{
    sll l1;
    int choice, value, result, pos;

    while (1)
    {
        
        printf("\n1. Insert beginning\n2. Insert end\n3. Insert position\n4. Delete beginning\n5. Delete end\n6. Delete position\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 9) // verifying menu number is in menu
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            result = l1.insert_beg(value);
            if (result == 1)
                printf("%d has been inserted\n", value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            result = l1.insert_end(value);
            if (result == 1)
                printf("%d has been inserted\n", value);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            result = l1.insert_pos(value, pos);
            if (result == 1)
                printf("%d has been inserted.\n", value);
            else
                printf("Position out of bounds.\n");
            break;
        case 4:
            result = l1.delete_beg();
            if (result == -1)
                printf("List is empty.\n");
            else
                printf("Element %d has been deleted.\n", result);
            break;
        case 5:
            result = l1.delete_end();
            if (result == -1)
                printf("List is empty.\n");
            else
                printf("Element %d has been deleted.\n", result);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            result = l1.delete_pos(pos);
            if (result == -1)
                printf("List empty.\n");
            if (result == -2)
                printf("Position out of bounds.\n");
            else
                printf("%d has been deleted.\n", result);
            break;
        case 7:
            printf("Enter element to search for: ");
            scanf("%d", &value);
            result = l1.search(value);
            if (result == -1)
                printf("Element %d not found.\n", value);
            else if (result == -2)
                printf("List empty.\n");
            else
                printf("Element %d found at index %d.\n", value, result);
            break;
        case 8:
            l1.display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    return 0;
}
