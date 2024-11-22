// You might want some more includes here
#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"
#include <stdio.h>
#include <stdlib.h>
// Implement your function here


int getOtherVertex(Edge edge, Vertex currentVertex)
{
    if (edge.from == currentVertex.number) {
        return edge.to;
    } else {
        return edge.from;
    }
}


void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    Queue * q = createQueue();
    enqueue(q, s);
    
    for (int i = 0; i < countV; i++) {
            V[i].color = WHITE;
            V[i].d = -1;
    }

    V[s].color = GRAY;
    V[s].d = 0;

    while(isEmpty(q) == 0){
        int u = getFront(q);
        //translate into 0-index
        dequeue(q);
        
        Adjacency* adj = V[u-1].list;


        while(adj != NULL){
            int i = getOtherVertex(*(adj->pEdge), V[u-1]);
            if(V[i].color == WHITE){
                V[i].color = GRAY;
                V[i].d = V[u-1].d + 1;
                enqueue(q, adj->pEdge->to);
            }
            
            adj = adj->next;
        }
        V[u-1].color = BLACK;
        printf("%d(%d)", u-1, V[u-1].d);
        // Vertex adj = V[V[index].list->pEdge->to];
    }

    printf("\n\n");

}
