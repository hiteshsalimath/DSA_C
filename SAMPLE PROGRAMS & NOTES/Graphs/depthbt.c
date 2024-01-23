#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the depth of a binary tree
int findDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}

int main() {
    // Creating a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Finding and printing the depth of the binary tree
    int treeDepth = findDepth(root);
    printf("Depth of the binary tree: %d\n", treeDepth);

    return 0;
}
