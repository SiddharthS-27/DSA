// list header file
#include <cstdio>
#include <cstdlib>

// class definition
class sll
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    struct node *gethead()
    {
        return head;
    }
    sll()
    {
        head = NULL;
    }

    int insert_ascending(int num)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (head == NULL) // empty list
        {
            newnode->next = NULL;
            head = newnode;
        }
        else if (head->data > num) // if first element greater than num, then num can be inserted at beginning
        {
            newnode->next = head;
            head = newnode;
        }
        else // if first element lesser than num, then have to traverse list
        {
            struct node *temp = head; 
            while (temp->next != NULL && temp->next->data < num)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        return 1;
    }
    sll merge(sll l1, sll l2)
    {
        sll l3;
        struct node *temp1 = l1.gethead();
        struct node *temp2 = l2.gethead();
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                l3.insert_ascending(temp1->data);
                temp1 = temp1->next;
            }
            else
            {
                l3.insert_ascending(temp2->data);
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            l3.insert_ascending(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            l3.insert_ascending(temp2->data);
            temp2 = temp2->next;
        }
        return l3;
    }
    void display()
    {
        struct node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};