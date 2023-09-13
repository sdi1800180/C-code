#include "GraphTypes.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    
    
    Graph *G = Initialize(G,8);
    
    InsertEdge(G,0,1);
    InsertEdge(G,1,2);
    InsertEdge(G,2,3);
    InsertEdge(G,2,4);
    InsertEdge(G,3,0);
    InsertEdge(G,4,5);
    InsertEdge(G,5,6);
    InsertEdge(G,6,4);
    InsertEdge(G,6,7);
    
    
    
    printf("Our Graph: \n");
    ShowGraph(G);
    
    
    printf("Depth Traverse : \n");
    
    DepthFirst(G,PrintElement);
    
    
    printf("\n");
    

    printf("We are going to reverse our graph\n");
    Graph *Greversed= GraphReverse(G);
    ShowGraph(Greversed);
    
    
    StrongComponents(G,Greversed,G->n);

    


    return 0;
}