#ifndef BST_H
#define BST_H

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} bst_t;

bst_t *create_new_node(int data);
void inorder(bst_t *root);
bst_t *insert(bst_t *root, int data);
bst_t *delete_node(bst_t *root, int data);
int search(bst_t *root, int data);

#endif /* BST_H */
