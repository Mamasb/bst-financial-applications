#include "bst.h"
#include <stdlib.h>

/* Create New Nodes */
bst_t *create_new_node(int data)
{
    bst_t *new_node = malloc(sizeof(bst_t));
    if (new_node == NULL)
        return NULL;
    
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Inorder traversal function */
void inorder(bst_t *root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Inserting data into BST */
bst_t *insert(bst_t *root, int data)
{
    if (root == NULL)
        return create_new_node(data);

    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

/* Find the minimum value in the tree */
bst_t *findmin(bst_t *root)
{
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

/* Search for an element in BST */
int search(bst_t *root, int data)
{
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

/* Delete a node from BST */
bst_t *delete_node(bst_t *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete_node(root->left, data);
    else if (data > root->data)
        root->right = delete_node(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = findmin(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}
