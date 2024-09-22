#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf(" Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int i, value;
    
                printf("Enter value to push: ");
                for(i=0;i<5;i++){
                scanf("%d", &value);
                push(value);
                }
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
           
    return 0;
}