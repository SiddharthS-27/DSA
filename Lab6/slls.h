// program to implement a singly linked list

#include <cstdlib>
#include <iostream>
using namespace std;

class sll
{
    struct node
    {
        char data;
        struct node *next;
    } *head;

public:
    sll()
    {
        head = nullptr;
    };
    int isEmpty()
    {
        if (head == nullptr)
        {
            return 1;
        }
        return 0;
    }
    char insert_beg(char value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == nullptr)
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
        return '1';
    }
    char delete_beg()
    {
        if (head == NULL)
        {
            return '#';
        }
        struct node *temp = head;
        char temp1;
        temp1 = head->data;
        head = head->next;
        free(temp);
        return temp1;
    }
    char push(char value)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;

        if (head == nullptr)
        {
            return insert_beg(value);
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            new_node->next = nullptr;
            new_node->data = value;
            temp->next = new_node;
        }
        return '1';
    }
    char pop()
    {
        if (head == nullptr)
        {
            return '#';
        }
        if (head->next == nullptr)
        {
            return delete_beg();
        }
        struct node *temp = head;
        struct node *temp1;
        char temp2;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp2 = temp->next->data;
        temp->next = nullptr;
        free(temp1);
        return temp2;
    }
    char peek()
    {
        if (head == nullptr)
        {
            return '#';
        }
        struct node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }
};
