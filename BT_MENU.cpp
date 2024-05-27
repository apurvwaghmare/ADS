// BT MENU



#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a key into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to find the minimum value node in a subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a key from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to find a key in BST
struct Node* find(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return find(root->right, key);

    return find(root->left, key);
}

// Function to print nodes at a given level
void printGivenLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// Function to calculate height of the tree
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// Function to print level order traversal of tree
void printLevelOrder(struct Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

// Function to display menu
void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Find\n");
    printf("4. Level-wise Display\n");
    printf("5. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter key to find: ");
                scanf("%d", &key);
                if (find(root, key))
                    printf("Key %d is found in the tree.\n", key);
                else
                    printf("Key %d is not found in the tree.\n", key);
                break;
            case 4:
                printf("Level-wise Display of BST: ");
                printLevelOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

/*
Level-wise Display Logic (printLevelOrder function)
The printLevelOrder function is responsible for printing the nodes of the BST level by level, starting from the root. It utilizes a helper function printGivenLevel which prints the nodes at a given level.

printGivenLevel Function
This function takes two parameters: the root of the subtree to be printed and the level to be printed.
If the current node is NULL, it returns, as there are no nodes to print at this level.
If the level is 1 (meaning we are at the level we want to print), it prints the key of the node.
If the level is greater than 1, it recursively calls printGivenLevel for the left and right subtrees with level - 1.


printLevelOrder Function
It calculates the height of the BST using the height function.
Then, it iterates from level 1 to the height and calls printGivenLevel for each level.


Delete Node Logic (deleteNode function)
The deleteNode function is responsible for deleting a node with a given key from the BST.

Base Cases
If the root is NULL, it simply returns NULL.
If the key is less than the root's key, it recursively calls deleteNode for the left subtree.
If the key is greater than the root's key, it recursively calls deleteNode for the right subtree.


Deleting a Node with Two Children
If the node to be deleted has two children, it finds the minimum value node in the right subtree (the node with the smallest key larger than the node to be deleted). It then replaces the key of the node to be deleted with the key of this minimum value node.
Finally, it recursively calls deleteNode to delete the minimum value node from the right subtree.


Deleting a Node with One or No Children
If the node to be deleted has one child or no child, it handles the deletion by rearranging the pointers appropriately.


Returning the Updated Root
It returns the root of the modified subtree after deletion.
*/