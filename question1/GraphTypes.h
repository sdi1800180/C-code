
/*This is GraphTypes.h*/

//****CODE TAKEN FROM "ENOTITA 16" IN GitHub *******
//gcc GraphTypes.h GraphInterface.c GraphImplementation.c -o exe
//./exe

#define MAXVERTEX 20



typedef enum {FALSE, TRUE} Boolean;

Boolean visited[MAXVERTEX];

typedef int Vertex;



//STACK STRUCT FOR STRONG COMPOMONENTS
typedef struct NodeType{
   Vertex item;
   struct NodeType *next;
}Node;

typedef struct{
   Node * list ;
}Stack;


//GRAPH STRUCT
 

typedef struct edge {
   Vertex startpoint;
   Vertex endpoint;
   struct edge *nextedge;
} Edge;
                                                            
typedef struct graph {
   int n;                         /* number of vertices in the graph */
   Edge *firstedge[MAXVERTEX];    /*         ADJENCY LIST            */
} Graph;



// FUNCTIONS


Graph * Initialize(Graph * ,int );
void InsertEdge(Graph * ,Vertex ,Vertex );
void ShowGraph(Graph * );
 void Traverse(Graph * ,Vertex ,void (*Visit)(Vertex ),Boolean visited[]);
 void DepthFirst(Graph * ,void(*Visit)(Vertex x));




void DepthFirstSC(Graph * G,Vertex v,Boolean visited[]);
void PrintElement(Vertex );
Graph * GraphReverse(Graph * G);

void StrongComponents(Graph * G,Graph *RG, int V);


// STACK FUNCTIONS

Stack * StackInit();
void Push(Vertex ,Stack * );
int Pop(Stack *S);
void TraverseStacking(Graph * G,Vertex x,Boolean visited[],Stack *S);
