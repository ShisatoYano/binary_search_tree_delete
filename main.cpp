#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// create new function
struct node* new_node(int key) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

// insert a new node with given key
struct node* insert(struct node* node, int key) {
    if (node == NULL) {
        return new_node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    return node;
}

// inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// found a node with minimum key value
struct node* min_value_node(struct node* node) {
    struct node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// given a binary search tree
// delete the key and return the new node
struct node* delete_node(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL){
            struct node* tmp = root->left;
            free(root);
            return tmp;
        }
        struct node* tmp = min_value_node(root->right);
        root->key = tmp->key;
        root->right = delete_node(root->right, tmp->key);
    }

    return root;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Given tree\n";
    inorder(root);

    cout << "Delete 20\n";
    root = delete_node(root, 20);
    cout << "modified tree\n";
    inorder(root);

    cout << "Delete 30\n";
    root = delete_node(root, 30);
    cout << "modified tree\n";
    inorder(root);

    cout << "Delete 50\n";
    root = delete_node(root, 50);
    cout << "modified tree\n";
    inorder(root);

    return 0;
}
