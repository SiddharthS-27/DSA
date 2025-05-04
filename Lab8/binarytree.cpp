// program to implement tree ADT using character binary tree 
#include <iostream>
using namespace std;

class binarytree {
private:
    struct node {
        char data;
        struct node *left, *right;
    };

    node *root;


public:
    binarytree() { root = NULL; }
    struct node* Node(char val)
    {
        struct node* temp = new node;
        temp->data =  val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    node* getRoot() { 
        return root; 
    }
    void insert();
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);
    bool search(node* root, char key);
};

void binarytree::insert() {
    char ch;
    cout << "Enter the character to be inserted (N for exit): ";
    cin >> ch;
    
    if (ch == 'N') return;

    node* newnode = new node();
    newnode->data = ch;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        root = newnode;
        return;
    }

    node* temp = root;
    while (true) {
        cout << "Insert left (L) or right (R) of " << temp->data << "? ";
        char dir;
        cin >> dir;

        if (dir == 'L') {
            if (temp->left == NULL) {
                temp->left = newnode;
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = newnode;
                break;
            } else {
                temp = temp->right;
            }
        }
    }
}

 

void binarytree::preorder(node *root) {
    if (root) { 
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void binarytree::inorder(node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void binarytree::postorder(node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    binarytree b1;
    char ch;

    while (true) {
        int choice;
        cout << "\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            b1.insert();
            break;
        case 2:
            cout << "\nPreorder: ";
            b1.preorder(b1.getRoot());
            cout << "\n";
            break;
        case 3:
            cout << "\nInorder: ";
            b1.inorder(b1.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "\nPostorder: ";
            b1.postorder(b1.getRoot());
            cout << "\n";
            break;
        case 5:
            cout << "Enter the character to be searched: ";
            cin >> ch;
            if (!b1.search(b1.getRoot(), ch)) {
                cout << "\nElement Not Found\n";
            }
            break;
        case 6:
            exit(0);
        default:
            cout << "\nInvalid menu number.\n";
        }
    }
}
