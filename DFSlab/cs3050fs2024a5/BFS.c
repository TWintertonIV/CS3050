// You might want some more includes here
#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"

// Implement your function here
void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    Queue * q = createQueue();
    enqueue(q, s);
    while(isEmpty(q) == 0){
        int u = getFront(q);
        dequeue(q);
        
    }

}
