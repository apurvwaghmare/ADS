// TWO MISTAKENLY 
// SWAPPED ELEMENTS




#include <stdio.h>
#include <stdlib.h>

void findSwappedPair(int arr[], int n) {
    int first_wrong = -1, second_wrong = -1;

   // we find the 1st wrong index 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            first_wrong = i;
            break;
        }
    }

    // here we traverse from the end and find the second wrong index
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            second_wrong = i;
            break;
        }
    }

    // we swap the positions of the two 
    int temp = arr[first_wrong];
    arr[first_wrong] = arr[second_wrong];
    arr[second_wrong] = temp;

    printf("Swapped elements: %d and %d\n", arr[first_wrong], arr[second_wrong]);
    printf("Their positions: %d and %d\n", first_wrong, second_wrong);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findSwappedPair(arr, n);

    return 0;
}



// LINEAR PROBING 
// WITH CHAINING
// WITHOUT REPLACEMENT




#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int data[], int flag[], int chain[], int x, int *collisions) {
    int i = 0, start, j;
    start = hashFunction(x);

    // Linear probing to find an empty slot
    while (flag[start] && i < SIZE) {
        if (data[start] % SIZE == x % SIZE) {
            break;
        }
        i++;
        start = (start + 1) % SIZE;
        (*collisions)++;  // Increment collision counter
    }

    if (i == SIZE) {
        printf("Hash Table is Full\n");
        return;
    }

    if (!flag[start]) {
        // Insert the key if an empty slot is found
        data[start] = x;
        flag[start] = 1;
        chain[start] = -1;
    } else {
        // Find the end of the chain
        j = start;
        while (chain[j] != -1) {
            j = chain[j];
        }

        // Find an empty slot
        int emptySlot = start;
        i = 0;
        while (flag[emptySlot] && i < SIZE) {
            emptySlot = (emptySlot + 1) % SIZE;
            i++;
            (*collisions)++;  // Increment collision counter
        }

        if (i == SIZE) {
            printf("Hash Table is Full\n");
            return;
        }

        // Insert the key in the empty slot
        data[emptySlot] = x;
        flag[emptySlot] = 1;
        chain[emptySlot] = -1;
        chain[j] = emptySlot;
    }
}

void display(int data[], int flag[], int chain[]) {
    printf("\nHash Table:\n");
    printf("Index  Key  Chain\n");
    for (int i = 0; i < SIZE; i++) {
        if (flag[i]) {
            printf("(%d)    %d    %d\n", i, data[i], chain[i]);
        } else {
            printf("(%d)    -    %d\n", i, chain[i]);
        }
    }
}

int main() {
    int data[SIZE], flag[SIZE], chain[SIZE], i, x, op;
    int collisions = 0;  // Initialize collision counter

    // Initialize the arrays
    for (i = 0; i < SIZE; i++) {
        flag[i] = 0;
        chain[i] = -1;
    }

    printf("Enter the number of keys to be inserted: ");
    scanf("%d", &op);

    for (i = 0; i < op; i++) {
        printf("Enter key to be inserted: ");
        scanf("%d", &x);
        insert(data, flag, chain, x, &collisions);
    }

    display(data, flag, chain);
    printf("Total collisions: %d\n", collisions);  // Display total collisions
    return 0;
}


/*

Sure, here’s an explanation of the overall logic and sequence of execution for the hash table implementation using linear probing with chaining and without replacement, all in one place:

Overall Logic and Sequence of Execution

Define Constants and Functions:
SIZE is defined as 10, representing the size of the hash table.
hashFunction: A simple hash function that returns the index by taking the remainder of the key divided by SIZE.


Initialization:
Arrays data, flag, and chain are declared and initialized.
data stores the keys.
flag indicates whether a slot is occupied.
chain maintains the chaining links.


Insert Function:
The insert function handles inserting a key into the hash table while managing collisions using linear probing and chaining.
The function first calculates the starting index using the hash function.


Linear Probing:
It checks if the slot at the starting index is occupied.
If occupied, it moves to the next slot using linear probing.
Collisions are counted each time an occupied slot is encountered.


Insertion:
If an empty slot is found, the key is inserted.
If the key hashes to an already occupied slot with the same hash, it follows the chain to find the end.
It then finds the next empty slot using linear probing and updates the chain.


Display Function:
The display function prints the current state of the hash table, showing the index, key, and chain link for each slot.


Main Function:
Handles user input, initializes arrays, and manages the insertion and display of keys.
Prompts the user for the number of keys and each key to be inserted.
Calls the insert function for each key.
Calls the display function to show the hash table.
Prints the total number of collisions.



*/



// LINEAR PROBING 
// WITH CHAINING 
// WITH REPLACEMENT





#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int data[], int flag[], int chain[], int x, int *collisions) {
    int start = hashFunction(x);

    // If the starting position is empty, place the key there
    if (!flag[start]) {
        data[start] = x;
        flag[start] = 1;
        chain[start] = -1;
        return;
    }

    // If the starting position is occupied, check for replacement
    if (hashFunction(data[start]) == start) {
        // Normal chaining (no replacement needed)
        int current = start;
        int next = (current + 1) % SIZE;

        while (flag[next]) {
            next = (next + 1) % SIZE;
            (*collisions)++;
        }

        data[next] = x;
        flag[next] = 1;
        chain[next] = chain[start];
        chain[start] = next;
    } else {
        // Replacement chaining
        int temp = data[start];
        int tempChain = chain[start];

        data[start] = x;
        chain[start] = -1;

        int next = (start + 1) % SIZE;
        while (flag[next]) {
            next = (next + 1) % SIZE;
            (*collisions)++;
        }

        data[next] = temp;
        flag[next] = 1;
        chain[next] = tempChain;
    }
}

void display(int data[], int flag[], int chain[]) {
    printf("\nHash Table:\n");
    printf("Index  Key  Chain\n");
    for (int i = 0; i < SIZE; i++) {
        if (flag[i]) {
            printf("(%d)    %d    %d\n", i, data[i], chain[i]);
        } else {
            printf("(%d)    -    %d\n", i, chain[i]);
        }
    }
}

int main() {
    int data[SIZE] = {0};
    int flag[SIZE] = {0};
    int chain[SIZE] = {-1};
    int op, x;
    int collisions = 0;  // Initialize collision counter

    printf("Enter the number of keys to be inserted: ");
    scanf("%d", &op);

    for (int i = 0; i < op; i++) {
        printf("Enter key to be inserted: ");
        scanf("%d", &x);
        insert(data, flag, chain, x, &collisions);
    }

    display(data, flag, chain);
    printf("Total collisions: %d\n", collisions);  // Display total collisions
    return 0;
}


/*


Here's an explanation of the provided C program implementing a hash table using linear probing with chaining and with replacement, along with the sequence of execution:

Overall Logic and Sequence of Execution


Define Constants and Functions:
SIZE is defined as 10, representing the size of the hash table.
hashFunction: A simple hash function that returns the index by taking the remainder of the key divided by SIZE.


Insert Function:
The insert function inserts a key into the hash table while handling collisions using linear probing with replacement.
If the starting position is empty, the key is placed there.
If the starting position is occupied:
If the key at the starting position hashes to its own index, normal chaining is performed.
If not, replacement chaining is performed:
The existing key at the starting position is moved to the next available slot.
The new key is inserted at the starting position.

Display Function:
The display function prints the current state of the hash table, showing the index, key, and chain link for each slot.


Main Function:
Handles user input, initializes arrays, and manages the insertion and display of keys.
Prompts the user for the number of keys and each key to be inserted.
Calls the insert function for each key.
Calls the display function to show the hash table.
Prints the total number of collisions.


*/