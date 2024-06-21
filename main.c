#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* Function to print the tree in a structured format */
void print_tree(bst_t *root, int space)
{
    if (root == NULL)
        return;
    
    space += 5; // Increase distance between levels
    
    // Process right child first
    print_tree(root->right, space);
    
    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    
    // Process left child
    print_tree(root->left, space);
}

int main(void)
{
    bst_t *root = NULL;
    int choice, data, search_data;
    
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a value into the tree\n");
        printf("2. Delete a value from the tree\n");
        printf("3. Search for a value in the tree\n");
        printf("4. Display the tree using Inorder traversal\n");
        printf("5. Print the tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                root = insert(root, data);
                if (root == NULL) {
                    printf("Failed to insert. Memory allocation error.\n");
                } else {
                    printf("%d has been inserted into the tree.\n", data);
                }
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty. Cannot delete.\n");
                } else {
                    printf("Enter a value to delete: ");
                    if (scanf("%d", &data) != 1) {
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        break;
                    }
                    root = delete_node(root, data);
                    if (root == NULL) {
                        printf("Element %d not found in the tree.\n", data);
                    } else {
                        printf("%d has been deleted from the tree.\n", data);
                    }
                }
                break;
            case 3:
                printf("Enter a value to search for: ");
                if (scanf("%d", &search_data) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                if (search(root, search_data)) {
                    printf("%d found in the tree.\n", search_data);
                } else {
                    printf("%d not found in the tree.\n", search_data);
                }
                break;
            case 4:
                printf("Inorder traversal of the tree: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Printing the tree structure:\n");
                print_tree(root, 0);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}