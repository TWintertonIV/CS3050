// You might want some more includes here
#include "MUCSGraph.h"
#include "DFS.h"
#include <stdio.h>
#include <stdlib.h>
// Implement your function here


void DFS_visit(Vertex* V, int index, int* time){
    V[index].color = GRAY;
    *time += 1;

    V[index].d = *time;

    Adjacency* adj = V[index].list;
    while(adj != NULL){
            int i = getOtherVertex(*(adj->pEdge), V[index]);
            if(V[index].color == WHITE){
                DFS_visit(V, i, time);    
            }
            
            adj = adj->next;
        }
        V[index].color = BLACK;
        *time += 1;
        V[index].f = *time;
}
void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    for(int i = 0; i < countV; i++){
        V[i].color = WHITE;
    }
    int time = 0;

    for(int j = 0; j < countV; j++){
        if(V[j].color = WHITE){
            DFS_visit(V, j, &time);
        }
    }
}
