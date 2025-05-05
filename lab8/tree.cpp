// Program to perform operations on binary tree
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int d) {
        data = d;
        left = right = nullptr;
    }
};

node* insert(node* root, int d);
void inorder(node* root);
void postorder(node* root);
void preorder(node* root);
int search(node* root, int n);

int main(void) {   
    // menu iteration
    bool loop_condition = true;
    int value;
    node* root = nullptr; 
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 12);
    root = insert(root, 11);
    root = insert(root, 13);

    while (loop_condition) {
        cout << "1.Insert\n";
        cout << "2.Inorder\n";
        cout << "3.Preorder\n";
        cout << "4.Postorder\n";
        cout << "5.Search\n";
        cout << "6.Exit\n";
        cout << "Enter choice:";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter character:";
            cin >> value;
            cout << '\n';
            root = insert(root, value);
        }
        if (choice == 2) {
            cout << "Inorder:";
            inorder(root);
        }     
        if (choice == 3) {
            cout << "preorder:";
            preorder(root);
        }
        if (choice == 4) {
            cout << "postorder:";
            postorder(root);
        }
        if (choice == 5) {
            int d;
            cout << "Enter number to search:";
            cin >> d;
            search(root, d);
        }
        if (choice == 6) {
            loop_condition = false;
        }    
        cout << '\n';
        cout << "=========================================\n\n";
    }
}

// Function to insert a value in the binary search tree
node* insert(node* root, int d) {
    if (root == nullptr) {
        return new node(d);
    } else {
        if (root->data > d) {
            root->left = insert(root->left, d);
        } else {
            root->right = insert(root->right, d);
        }
    }
    return root;
}

// Function to perform inorder traversal (Left, Root, Right)
void inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to perform postorder traversal (Left, Right, Root)
void postorder(node* root) {
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function to perform preorder traversal (Root, Left, Right)
void preorder(node * root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to search for an element in the binary search tree
int search(node* root, int n) {
    if (root == nullptr) {
        cout << "Data not found\n";
        return 0;
    }
    if (root->data == n) {
        cout << "Data found\n";
        return 1;
    } else if (root->data > n) {
        return search(root->left, n);
    } else {
        return search(root->right, n);
    }
}
