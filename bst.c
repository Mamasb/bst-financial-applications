#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

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
        root = create_new_node(data);
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

/* Find a minimum value of a tree */
bst_t *findmin(bst_t *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

/* Search an element from BST */
int search(bst_t *root, int data)
{
    if (root == NULL)
        return 0;
    else if(root->data == data)
        return 1;
    else if(data <= root->data)
        return search(root->left,data);
    else
        return search(root->right,data);
}

/* Delete a node from a tree */
bst_t *delete_node(bst_t *root, int data)
{
    if (root == NULL)
        return root;
    else if(data < root->data)
        root->left = delete_node(root->left, data);
    else if(data > root->data)
        root->right = delete_node(root->right, data);
    else
    {
        /* Delete a node with no child */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        /* Delete a node with one child */
        else if(root->left == NULL)
        {
            bst_t *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            bst_t *temp = root;
            root = root->left;
            free(temp);
        }
        /* Delete a node with two children */
        else {
            bst_t *temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);
        }
    }
    return root;
}
