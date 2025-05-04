// program to implement tree ADT using a binary search tree
#include <iostream>
using namespace std;

class bst
{
private:
    struct node
    {
        int data;
        struct node *left;
        struct node *right;
    } *root;

public:
    bst()
    {
        root = nullptr;
    };
    struct node *getRoot()
    {
        return root;
    }
    void setRoot(struct node *new_root)
    {
        root = new_root;
    }
    struct node *insert(int val, struct node *root) // time complexity is O(h), where h is height of bst (worst case is O(n))
    {
        if (root == nullptr)
        {
            root = new node;
            root->left = nullptr;
            root->right = nullptr;
            root->data = val;
            return root;
        }
        else
        {
            if (val < root->data)
            {
                root->left = insert(val, root->left);
            }
            else
            {
                root->right = insert(val, root->right);
            }
        }
        return root;
    }
    void preorder(struct node *root) // time complexity is O(n)
    {
        if (root)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(struct node *root) // time complexity is O(n)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void postorder(struct node *root) // time complexity is O(n)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
    int search(int val, struct node *root) // // time complexity is O(log(n)) (worst case is O(n))
    {
        if (root == nullptr)
        {
            return 0;
        }
        else if (val == root->data)
        {
            return 1;
        }
        else if (val < root->data)
        {
            return search(val, root->left);
        }
        else 
        {
            return search(val, root->right);
        }
    }
};

int main()
{
    bst b1;
    while (1)
    {
        int choice;
        cout << "\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            b1.setRoot(b1.insert(val, b1.getRoot()));
            break;
        }

        case 2:
        {
            cout << "\nPreorder: ";
            b1.preorder(b1.getRoot());
            cout << "\n";
            break;
        }

        case 3:
        {
            cout << "\nInorder: ";
            b1.inorder(b1.getRoot());
            cout << "\n";
            break;
        }

        case 4:
        {
            cout << "\nPostorder: ";
            b1.postorder(b1.getRoot());
            cout << "\n";
            break;
        }

        case 5:
        {
            int num;
            cout << "Enter the number to be searched: ";
            cin >> num;
            if (b1.search(num, b1.getRoot()) == 1)
            {
                cout << "Element found.\n";
            }
            else
            {
                cout << "Element not found.\n";
            }
            break;
        }
        case 6:
            exit(0);
        default:
            cout << "\nInvalid menu number.\n";
        }
    }
}