#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

bool is_deadlock_state(int allocation[][MAX_RESOURCES], int request[][MAX_RESOURCES], bool finish[], int num_processes, int num_resources) {
    bool work[MAX_RESOURCES];
    bool finish_copy[MAX_PROCESSES];

    for (int i = 0; i < num_processes; ++i) {
        finish_copy[i] = finish[i];
    }

    bool updated = true;
    while (updated) {
        updated = false;
        for (int i = 0; i < num_processes; ++i) {
            if (!finish_copy[i]) {
                bool can_allocate = true;
                for (int j = 0; j < num_resources; ++j) {
                    if (request[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    updated = true;
                    finish_copy[i] = true;
                    for (int j = 0; j < num_resources; ++j) {
                        work[j] = work[j] || allocation[i][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < num_processes; ++i) {
        if (!finish_copy[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int request[MAX_PROCESSES][MAX_RESOURCES] = {{0, 0, 0}, {2, 0, 2}, {0, 0, 0}, {1, 0, 0}, {0, 0, 2}};
    bool finish[MAX_PROCESSES] = {false};

    bool deadlock_state = is_deadlock_state(allocation, request, finish, MAX_PROCESSES, MAX_RESOURCES);

    if (deadlock_state) {
        printf("The system is in a deadlock state.\n");
    } else {
        printf("The system is not in a deadlock state.\n");
    }

    return 0;
}
