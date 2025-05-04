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

    void display()
    {
        if (head == NULL)
        {
            printf("All processes have been completed.\n");
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

    int execute(int time)
    {
        if (head == NULL)
        {
            return -1;
        }
        int temp;
        while (head != NULL)
        {
            temp = delete_beg();
            if (temp - time > 0)
            {
                insert_end(temp - time);
            }
            display();
            printf("\n");
        }

        return 1;
    }
};
