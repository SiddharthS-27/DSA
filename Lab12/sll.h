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
    int delete_beg()
    {
        if (head == NULL)
        {
            return 0;
        }
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            int temp1;
            temp = head;
            temp1 = head->data;
            head = head -> next;
            free(temp);
            return temp1;
        
    }
    int delete_pos(int pos)
    {
        if (pos == 0)
        {
            return delete_beg(); // if no return, then segfault
        }
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        struct node* temp1 = (struct node*)malloc(sizeof(struct node));
        int temp2;
        temp = head;
        for (int i=0;i<pos-1;i++)
        {
            temp = temp-> next;
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
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        int i =0;
        while(temp != NULL)
        {
            if(temp->data  == value)
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
        }
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp -> next;
        }
        printf("NULL");
        printf("\n");
    }
};