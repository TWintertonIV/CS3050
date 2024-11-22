
#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef __cplusplus
extern "C" 
{
#endif

// Data types
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {

    // Pointer to the front and the rear of the linked list
    Node *front, *rear;
} Queue;


// Prototypes
Node* createNode(int new_data);
Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Queue* q, int new_data);
void dequeue(Queue* q);
int getFront(Queue* q);
int getRear(Queue* q);


#ifdef __cplusplus
}
#endif

#endif