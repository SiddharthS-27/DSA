// program to implement tree ADT using character binary tree
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class binarytree
{
private:
    struct node
    {
        char data;
        struct node *left, *right;
    };

    node *root;

public:
    binarytree() { root = NULL; }
    struct node *Node(char val)
    {
        struct node *temp = new node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    node *getRoot()
    {
        return root;
    }
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
    void construct_exp(string postfix);
};

void binarytree::preorder(node *root) // time complexity is O(n)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void binarytree::inorder(node *root) // time complexity is O(n)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void binarytree::postorder(node *root) // time complexity is O(n)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void binarytree::construct_exp(string postfix) // time complexity is O(n), where n is length of postfix string
{
    stack<struct node *> s;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '+' || postfix[i] == '-')
        {
            if (s.size() < 2)
            {
                cout << "Error. Invalid postfix expression\n";
                return;
            }
            struct node *term = Node(postfix[i]);
            term->right = s.top();
            s.pop();
            term->left = s.top();
            s.pop();
            s.push(term);
        }
        else
        {
            s.push(Node(postfix[i]));
        }
    }
    if (s.size() != 1)
    {
        cout << "Error. Invalid postfix expression\n";
        return;
    }
    root = s.top();
}

int main()
{
    binarytree b1;
    string postfix;
    while (1)
    {
        int choice;
        cout << "\n1.Postfix Expression\n2.Construct Expression Tree\n3.Preorder\n4.Inorder\n5.Postorder\n6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter valid postfix expression: ";
            cin >> postfix;
            break;

        case 2:
            b1.construct_exp(postfix);
            break;

        case 3:
            cout << "\nPreorder: ";
            b1.preorder(b1.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "\nInorder: ";
            b1.inorder(b1.getRoot());
            cout << "\n";
            break;
        case 5:
            cout << "\nPostorder: ";
            b1.postorder(b1.getRoot());
            cout << "\n";
            break;
        case 6:
            exit(0);
        default:
            cout << "\nInvalid menu number.\n";
        }
    }
}
