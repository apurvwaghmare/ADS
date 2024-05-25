// Student Heapsort


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

// Function to swap two Student objects
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify operation
void heapify(struct Student arr[], int n, int i, int* swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
        largest = left;

    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swapCount)++; // Increment swap count
        heapify(arr, n, largest, swapCount);
    }
}

// Function to perform Heap sort
void heapSort(struct Student arr[], int n, int* swapCount) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swapCount);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        (*swapCount)++; // Increment swap count
        heapify(arr, i, 0, swapCount);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (int i = 0; i < n; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].student_name);
        printf("Roll No: ");
        scanf("%d", &students[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%d", &students[i].total_marks);
    }

    int swapCount = 0; // Variable to count the number of swaps

    // Perform Heap sort
    heapSort(students, n, &swapCount);

    // Output sorted student details
    printf("\nSorted Student Details:\n");
    for (int i = 0; i < n; ++i) {
        printf("Name: %s, Roll No: %d, Total Marks: %d\n", students[i].student_name, students[i].student_roll_no, students[i].total_marks);
    }

    printf("\nNumber of swaps performed: %d\n", swapCount);

    return 0;
}

/*

Input

3 
Apurv
3 
90 
Asmi 
2 
99 
Arun 
1 
100
What is Heapify?
=> Heapify is the process of converting a binary tree into a valid heap data structure.
   This is usually achieved by starting from the last internal node (i.e., the parent of
   the rightmost leaf node) and working towards the root node, swapping the node
   with its largest (or smallest, depending on whether it is a max or min heap) child
   node until the heap property is satisfied. The process is repeated for the affected
   subtrees until the entire tree is a valid heap. The time complexity of heapify is
   O(log n), where n is the number of nodes in the tree.
   
        7
     10     5 
   3    8
   
  Heap Sort Algorithm?
  
=> 1. Build a max-heap from the input data: The first step is to build a binary max-
      heap from the input data. This is done by transforming the array into a
      complete binary tree where the largest value is at the root node.
      
    2.Swap the first and last elements of the array: After building the max heap,
      the largest value will be at the root node. Swap this value with the last
      element of the array. This will place the largest value at the end of the array, 
      which is its final position in the sorted array.
      
    3.Heapify the remaining data: After swapping the first and last elements, the
      heap size is reduced by one. The root node may now violate the max-heap
      property, so the algorithm needs to reheapify the data to restore the max-heap.
     
    4. Repeat steps 2 and 3 until the heap size is reduced to 1: The algorithm
       continues to repeat steps 2 and 3 until the heap size is reduced to 1. This
       means that the entire array has been sorted in ascending order.
       
    5. Return the sorted array: After the heap size has been reduced to 1, 
       the array is sorted and can be returned as the final result.
      
*/
      