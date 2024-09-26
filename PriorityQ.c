#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Define a constant for the maximum size

struct PriorityQ {
    int data;
    int p;
};

struct PriorityQ arr[MAX_SIZE]; // Use constant for array size
int curr_size = 0;

void insert(int data, int p) {
    if (curr_size == MAX_SIZE) {
        printf("Queue is overflow\n");
        return;
    }

    // Find the correct position to insert the new element
    int i;
    for (i = curr_size - 1; (i >= 0 && arr[i].p > p); i--) {
        arr[i + 1] = arr[i]; // Shift elements to the right
    }

    // Insert the new element at its correct position
    arr[i + 1].data = data;
    arr[i + 1].p = p;
    curr_size++;
}

void display() {
    if (curr_size == 0) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < curr_size; i++) {
        printf("Data: %d, Priority: %d\n", arr[i].data, arr[i].p);
    }
}

int main() {
    insert(10, 1);
    insert(20, 2);
    insert(30, 1);
    display();
    return 0;
}
