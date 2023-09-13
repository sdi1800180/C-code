#include "GraphTypes.h"
#include <stdio.h>
#include <stdlib.h>


Stack* StackInit(){
   Stack * S=malloc(sizeof(Stack));
   if(S==NULL){
      printf("failed to create Stack\n");
      return NULL;
   }
   S->list=malloc(sizeof(Node));
   return S;
}

void TraverseStacking(Graph * G,Vertex v,Boolean visited[],Stack * S){
   Vertex w;
   Edge * curedge;
   visited[v]=TRUE;
   
   curedge=G->firstedge[v];

   while(curedge){
      w=curedge->endpoint;
      if(!visited[w]){
         TraverseStacking(G,w,visited,S);
      }
      curedge=curedge->nextedge;
   }
   Push(v,S); 
   
   
}
void Push(Vertex v,Stack * S){
   Node * temp;
   temp=malloc(sizeof(Node));
   if(temp==NULL){
      printf("no storage");
   
   }else{
      temp->next=S->list;
      temp->item=v;
      S->list=temp;
   }
}
int Pop(Stack * S){
   
   if(S->list==NULL){
      printf("attempt to pop the empty stack");
   }else {
      Node * temp;
      temp=S->list;
      int r=temp->item;
      S->list=S->list->next;
      free(temp);
      return r;
   }
}










Graph * Initialize(Graph* G,int n)
{   
   
   Graph *g=malloc(sizeof(Graph));
   g->n=n;  
   for(int i=0; i<n; i++){
      g->firstedge[i]=NULL;
   }   
   G=g;
   return G;
}
 void InsertEdge(Graph* G,Vertex start, Vertex end){
   //Create the Edge
   Edge * E = malloc(sizeof(Edge));
   E->startpoint= start;
   E->endpoint = end;
   E->nextedge = NULL;
   

   if( G->firstedge[start] == NULL ) {
      G->firstedge[start] =  E;
   }
   else
   {
      Edge* lastNode = G->firstedge[start];      

      //last node's next address will be NULL.
      while(lastNode->nextedge != NULL)
      {
         lastNode = lastNode->nextedge;
      }

      //add the newNode at the end of the linked list
      lastNode->nextedge = E;
      
   }
}
void ShowGraph(Graph * G){

   Edge* temp;
   for(int i=0; i<(G->n) ; i++){
      
      temp=G->firstedge[i];   
      printf("%d",i);
      
      
      
      
      while(temp!=NULL)
      {
         
         
         printf("->%d",temp->endpoint); 
         temp=temp->nextedge;
         
      }
      
      
      printf("\n");
      
      }
      
   }




Graph * GraphReverse(Graph * G){
   
   Graph * GR=Initialize(GR,G->n);
   
   
   Edge* temp;
   
   for(int i=0; i<=G->n; i++){
      
      temp=G->firstedge[i];
      
        
        while (temp!=NULL)
         {
             
             InsertEdge( GR, temp->endpoint, temp->startpoint );
             
             temp=temp->nextedge;
          
         }

      
   }
return GR;
}

void Traverse(Graph * G, Vertex v, void (*Visit)(Vertex x),Boolean visited[])
{
   Vertex w;
   Edge * curedge;

   visited[v]=TRUE;
   
   
   Visit(v);
  
   
   curedge=G->firstedge[v];
   
   
   while(curedge){
      w=curedge->endpoint;
      
      if(!visited[w])
       {
         Traverse(G, w, Visit,visited);
       }
      curedge=curedge->nextedge;
      
   }
   

}

void DepthFirst(Graph * G, void(*Visit)(Vertex x))
{
   
   Vertex v;

   for(v=0; v < G->n; v++) visited[v]=FALSE;
   
   for(v=0; v < G->n; v++) { if(!visited[v]) Traverse(G, v, Visit,visited); }

   
}

void PrintElement(Vertex x)
{
  printf("%d", x);
}

void StrongComponents(Graph * G,Graph *RG,int V)
{
   
   Stack *S= StackInit();
   
   Boolean visited[V];
   
   //Dfs and stacking 
   for(int i=0; i<V; i++) visited[i]=FALSE;

   for(int i=0; i<V; i++){  if(!visited[i]) {TraverseStacking(G,i,visited,S);}   }

   
   
   //dfs in the reversed graph
   
   for(int i=0; i<V; i++) visited[i]=FALSE;
   
   printf("Strong Components : \n");
   while(S->list != NULL)
   {
      
      int s= Pop(S);
      

   
      if(!visited[s])
      {     
          Traverse(RG,s,PrintElement,visited);
          printf("\n");
      }

   }

}