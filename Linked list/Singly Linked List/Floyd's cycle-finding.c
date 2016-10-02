/**
 * This program creates a linked list, one node at a time           insert(Node*)
 * Create a cycle                                                   cycle(Node*)
 * Checks if there is a cycle in the list.                          hare_tortoise(Node*)
 */
#include <stdio.h>
#include <stdlib.h>

// The Abstract DataType
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// Functions
Node* insert(Node*, int);
void cycle(Node*);
int hare_tortoise(Node*);

/** The algorithm
 *  returns 1 when cycle exists
 */
int hare_tortoise(Node* list){
    Node *hare = list, *tortoise = list;
    while (1) {
        if ( hare == NULL || hare -> next == NULL )
            return 0;
        // Hare takes the first leap
        hare = hare -> next;
        if ( hare == NULL )
            return 0;

        // Hare takes the second leap
        hare = hare -> next;
        // Tortoise takes the first leap
        tortoise = tortoise -> next;
        // speed of hare = 2 * (speed of tortoise)

        /* If they land up in the same node by moving at different
         * speeds, then there exist a "cycle" in the linked list.
         */
        if ( hare == tortoise )
            return 1;
        }
}

// Testing code

int main(void){
    int num, i = 0, dd;
    Node* head = NULL;
    // Creating a linked list
    printf("Enter the number of elements\n");
    scanf("%d", &num);
    while ( i != num )
    {
        printf("Enter element# %d >", ( i + 1 ) );
        scanf("%d", &dd);
        head = insert(head, dd);
        i++;
    }
    cycle(head); // Comment this out, to skip creating a cycle.
    i = hare_tortoise(head);
    if (i == 0)
        printf("No cycle exists\n");
    else
        printf("Cycle exists\n");
    return 0;
}
/**
 * Inserts nodes in the list
 */
Node* insert(Node* Head, int datum){
    Node  *curr = (Node*) malloc(sizeof(Node));
    curr -> data = datum;
    curr -> next = Head;
    return curr;
}
/**
 * Creates a cycle by linking the last node to the first node
 */
void cycle(Node* join){
    Node* end = join;
    // Finds the last node
    while ( end -> next ) // same as join->next != NULL
        end = end -> next;
    end -> next = join;// Connects the last node to the first node
}
