// EMPLOYEE_QUICKSORT


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Employee
struct Employee {
    char employee_name[50];
    int emp_no;
    float emp_salary;
};

// Swap function to swap two Employee structures
void swap(struct Employee *a, struct Employee *b, int *swap_count) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
    (*swap_count)++;
}

// Partition function for Quick Sort
int partition(struct Employee arr[], int low, int high, int *swap_count) {
    struct Employee pivot = arr[high]; // Pivot element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j].emp_no <= pivot.emp_no) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j], swap_count); // Swap elements
        }
    }
    swap(&arr[i + 1], &arr[high], swap_count);
    return (i + 1);
}

// Quick Sort function
void quickSort(struct Employee arr[], int low, int high, int *swap_count) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high, swap_count);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1, swap_count);
        quickSort(arr, pi + 1, high, swap_count);
    }
}

int main() {
    int n, swap_count = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Create an array of Employee structures
    struct Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", employees[i].employee_name);
        printf("Employee Number: ");
        scanf("%d", &employees[i].emp_no);
        printf("Salary: ");
        scanf("%f", &employees[i].emp_salary);
    }

    // Perform Quick Sort based on emp_no
    quickSort(employees, 0, n - 1, &swap_count);

    // Output sorted array
    printf("\nSorted employee list based on emp_no:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Employee Number: %d, Salary: %.2f\n", employees[i].employee_name, employees[i].emp_no, employees[i].emp_salary);
    }

    printf("\nTotal number of swaps performed: %d\n", swap_count);

    return 0;
}




/*

QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element
as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.


*/