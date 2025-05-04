// program to implement a singly linked list
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
    };
    int insert_beg(int value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
            new_node->data = value;
            new_node->next = head;
            head = new_node;
        }
        else
        {
            new_node->data = value;
            new_node->next = head;
            head = new_node;
        }
        return 1;
    }
    int insert_end(int value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        if (head == NULL)
        {
            return insert_beg(value);
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            new_node->next = NULL;
            new_node->data = value;
            temp->next = new_node;
        }
        return 1;
    }
    int insert_pos(int value, int pos)
    {
        if (pos == 0)
        {
            return insert_beg(value);
        }
        else
        {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            new_node->data = value;
        }

        return 1;
    }
    int delete_beg()
    {
        if (head == NULL)
        {
            return -1;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        int temp1;
        temp = head;
        temp1 = head->data;
        head = head->next;
        free(temp);
        return temp1;
    }
    int delete_end()
    {
        if (head == NULL)
        {
            return -1;
        }
        if (head->next == NULL)
        {
            return delete_beg();
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        int temp2;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp2 = temp->next->data;
        temp->next = NULL;
        free(temp1);
        return temp2;
    }
    int delete_pos(int pos)
    {
        if (head == NULL)
        {
            return -1;
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
        {
            return -2;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return i;
            }
            temp = temp->next;
            i++;
        }
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
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
    int getlen()
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
    void display_rev()
    {
        if (head == NULL)
        {
            printf("The list is empty.\n");
        }
        int arr[getlen()];
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            arr[i] = temp->data;
            temp = temp->next;
            i++;
        }
        printf("NULL");
        for (int i = ((getlen())-1); i >= 0; i--)
        {
            printf(" -> %d", arr[i]);
        }
    }
    void reverse_link()
    {

        struct node *curr;
        struct node *prev;
        struct node *next;
        curr = head;
        prev = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    sll l1;
    int choice, value, result, pos;
    while (1)
    {
        printf("\n1. Insert beginning\n2. Insert end\n3. Insert position\n4. Delete beginning\n5. Delete end\n6. Delete position\n7. Search\n8. Display\n9. Display reverse\n10. Reverse link\n11. Exit\n");
        printf("Enter menu number of operation you want to perform: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            result = l1.insert_beg(value);
            if (result == 1)
            {
                printf("%d has been inserted\n", value);
            }
            break;
        }
        case 2:
        {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            result = l1.insert_end(value);
            if (result == 1)
            {
                printf("%d has been inserted\n", value);
            }
            break;
        }
        case 3:
        {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            result = l1.insert_pos(value, pos);
            if (result == 1)
            {
                printf("%d has been inserted.\n", value);
            }
            break;
        }
        case 4:
        {
            result = l1.delete_beg();
            if (result == -1)
            {
                printf("List is empty.\n");
            }
            else
            {
                printf("Element %d has been deleted.\n", result);
            }
            break;
        }
        case 5:
        {
            result = l1.delete_end();
            if (result == -1)
            {
                printf("List is empty.\n");
            }
            else
            {
                printf("Element %d has been deleted.\n", result);
            }
            break;
        }
        case 6:
        {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            result = l1.delete_pos(pos);
            if (result == -1)
            {
                printf("List is empty.\n");
            }
            else
            {
                printf("%d has been deleted.\n", result);
            }
            break;
        }
        case 7:
        {
            printf("Enter element to search for: ");
            scanf("%d", &value);
            result = l1.search(value);
            if (result == -1)
            {
                printf("Element %d not found.\n", value);
            }
            if (result == -2)
            {
                printf("List empty.\n");
            }
            else
            {
                printf("Element %d found at index %d.\n", value, result);
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
            l1.display_rev();
            break;
        }
        case 10:
        {
            l1.reverse_link();
            break;
        }
        case 11:
        {
            exit(0);
        }
        default:
        {
            printf("Error.\n");
            break;
        }
        }
    }
    return 0;
}