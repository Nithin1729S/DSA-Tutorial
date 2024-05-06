#include<stdio.h>
#include<stdlib.h>
//the code is using insert at head in LL...and also adj is array of structs
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear) printf("Queue is Empty");
    else 
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}


int isEmpty(struct Queue *q)
{
    if(q->front==q->rear) return 1;
    else return 0;
}

struct Node
{
    int vertex;
    char* color;
    int parent;
    int d;
    struct Node*next;
};

struct Graph
{
    int numVertices;
    struct Node **adj;//an array of structs ie nodes
    int *visited;
};

struct Node* createNode(int v)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}


struct Graph*createGraph(int vertices)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->adj=(struct Node**)malloc(vertices*sizeof(struct Node*));
    graph->visited=(int*)malloc(vertices*sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        graph->adj[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}

void addEdge(struct Graph *graph,int src, int dest)
{
    struct Node* newNode=createNode(dest);
    newNode->next=graph->adj[src];
    graph->adj[src]=newNode;

    newNode=createNode(src);
    newNode->next=graph->adj[dest];
    graph->adj[dest]=newNode;
}

void bfs(struct Graph*graph,int start)
{
    struct Queue q;
    create(&q,graph->numVertices);
    graph->visited[start]=1;
    enqueue(&q,start);
    while(!isEmpty(&q))
    {
        int curr=dequeue(&q);
        printf("%d ",curr);

        struct Node* temp=graph->adj[curr];
        while(temp)
        {
            int adjVertex=temp->vertex;
            if(graph->visited[adjVertex]==0)
            {
                graph->visited[adjVertex]=1;
                enqueue(&q,adjVertex);
            }
            temp=temp->next;
        }
    }    
}



void printGraph(struct Graph*graph)
{
    for(int i=0;i<graph->numVertices;i++)
    {
        struct Node*temp=graph->adj[i];
        //printf("%d",temp->vertex);
        printf("\nVertex %d: ",i);
        while(temp)
        {
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Graph* graph=createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,1,2);

    printGraph(graph);
    bfs(graph,0);
    return 0;



}