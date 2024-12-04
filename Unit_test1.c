// Question 1: Implement a Doubly Linked List with Basic Operations (10 Marks)
// Problem:
// Design and implement a Doubly Linked List (DLL) in a programming language of your choice. Your implementation should include the following operations:
// Insertion at the front of the list.
// Insertion at the end of the list.
// Deletion from the front of the list.
// Deletion from the end of the list.
// Search an element in the list.
// Display the list in both forward and reverse directions.
// Instructions:
// Provide the class/structure for the Node and Doubly Linked List.
// Implement and demonstrate the basic operations in a main function.
// Your solution should have appropriate error handling (e.g., handling empty list scenarios).
// Time complexity analysis should be provided for each operation (e.g., O(1) for insertions/deletions at the front and end).

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;
struct DLL
{
    Node *head;
    Node *tail;
};
typedef struct DLL DLL;
DLL *createDLL()
{
    DLL *list = (DLL *)malloc(sizeof(DLL));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void insertEnd(DLL *list, int data)
{
    Node *node = createNode(data);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}
void insertFront(DLL *list, int data)
{
    Node *node = createNode(data);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
}
void deleteEnd(DLL *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
    }
}
void deleteFront(DLL *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
    }
}
void display(DLL *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    DLL *list = createDLL();
    insertEnd(list, 10);
    insertEnd(list, 20);
    insertFront(list, 30);
    insertEnd(list, 40);
    insertEnd(list, 50);
    printf("Initial list: ");
    display(list);
    insertFront(list, 5);
    printf("After inserting 5 at front: ");
    display(list);
    deleteFront(list);
    printf("After deleting front: ");
    display(list);
    deleteEnd(list);
    printf("After deleting end: ");
    display(list);
    return 0;
}
