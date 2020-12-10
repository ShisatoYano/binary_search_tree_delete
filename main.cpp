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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
