// Employee tree


#include<stdio.h>
#include<stdlib.h>

struct Employee {
    int empID;
    char name[50];
};

struct Node {
    struct Employee data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(struct Employee emp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = emp;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, struct Employee emp) {
    if (root == NULL) {
        return createNode(emp);
    }

    if (emp.empID < root->data.empID) {
        root->left = insert(root->left, emp);
    } else if (emp.empID > root->data.empID) {
        root->right = insert(root->right, emp);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
        inorderTraversal(root->right);
    }
}

struct Node* searchByID(struct Node* root, int empID) {
    if (root == NULL || root->data.empID == empID) {
        return root;
    }

    if (empID < root->data.empID) {
        return searchByID(root->left, empID);
    } else {
        return searchByID(root->right, empID);
    }
}

int main() {
    struct Node* root = NULL;
    int numEmployees;

    // Get the number of employees from the user
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    // Get employee records from the user and insert into the BST
    for (int i = 0; i < numEmployees; ++i) {
        struct Employee emp;
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp.empID);
        printf("Name: ");
        scanf("%s", emp.name);
        root = insert(root, emp);
    }

    // Display the employee records in ascending order
    printf("\nEmployee records sorted by ID (ascending order):\n");
    inorderTraversal(root);

    // Search for an employee record by ID
    int searchID;
    printf("\nEnter the Employee ID to search: ");
    scanf("%d", &searchID);

    struct Node* result = searchByID(root, searchID);
    if (result != NULL) {
        printf("Employee found - Employee ID: %d, Name: %s\n", result->data.empID, result->data.name);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}
