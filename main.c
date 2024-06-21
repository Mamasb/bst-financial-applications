#include <stdio.h>
#include "bst.h"

int main(void)
{
    bst_t *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    printf("Searching for 70: %s\n", search(root, 70) ? "Found" : "Not found");
    printf("Searching for 100: %s\n", search(root, 100) ? "Found" : "Not found");

    printf("Deleting 30 from the BST\n");
    root = delete_node(root, 30);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
