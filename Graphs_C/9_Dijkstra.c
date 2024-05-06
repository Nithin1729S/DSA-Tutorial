#include<stdio.h>
#include<stdlib.h>
#define INF 35000

struct Node
{
    int vertex;
    int weight;
    struct Node*next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct Node**adj;
};

struct Node* createNode(int v,int weight)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}

struct Graph*createGraph(int vertices)
{
    struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->visited=(int*)malloc(sizeof(int)*vertices);
    graph->adj=(struct Node**)malloc(sizeof(struct Node**)*vertices);

    for(int i=0;i<vertices;i++)
    {
        graph->adj[i]=NULL;
        graph->visited[i]=0;
    }

    return graph;
}

void addEdge(struct Graph *graph,int src, int dest,int weight)
{
    struct Node*newNode=createNode(dest,weight);
    newNode->next=graph->adj[src];
    graph->adj[src]=newNode;

    newNode=createNode(src,weight);
    newNode->next=graph->adj[dest];
    graph->adj[dest]=newNode;
}

struct minHeapNode
{
    int v;
    int key;
};

struct minHeap
{
    int size;
    int capacity;
    int *pos;
    struct minHeapNode**array;
};

struct minHeapNode* createMinHeapNode(int v,int key)
{
    struct minHeapNode *minHeapNode=(struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    minHeapNode->v=v;
    minHeapNode->key=key;
    return minHeapNode;
}

struct minHeap* createMinHeap(int capacity)
{
    struct minHeap*minHeap=(struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->pos=(int*)malloc(capacity*sizeof(int));
    minHeap->size=0;
    minHeap->array=(struct minHeapNode**)malloc(capacity*sizeof(struct minHeapNode));
    return minHeap;
}

void swapMinHeapNode(struct minHeapNode**a,struct minHeapNode**b)
{
    struct minHeapNode*t=*a;
    *a=*b;
    *b=t;
}

void minHeapify(struct minHeap*minHeap,int idx)
{
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;

    if(left<minHeap->size && minHeap->array[left]->key<minHeap->array[smallest]->key)
        smallest=left;
    if(right<minHeap->size && minHeap->array[right]->key<minHeap->array[smallest]->key)
        smallest=right;
    
    if(smallest!=idx)
    {
        struct minHeapNode*smallestNode=minHeap->array[smallest];
        struct minHeapNode*idxNode=minHeap->array[idx];

        minHeap->pos[smallestNode->v]=idx;
        minHeap->pos[idxNode->v]=smallest;
        
        //swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);

        swapMinHeapNode(&smallestNode,&idxNode);

        minHeapify(minHeap,smallest);
    }
}

int isHeapEmpty(struct minHeap*minHeap)
{
    return minHeap->size==0;
}

struct minHeapNode* extractMin(struct minHeap*minHeap)
{
    if(isHeapEmpty(minHeap)) return NULL;

    struct minHeapNode*root=minHeap->array[0];

    struct minHeapNode*lastNode=minHeap->array[minHeap->size-1];
    minHeap->array[0]=lastNode;

    minHeap->pos[root->v]=minHeap->size-1;
    minHeap->pos[lastNode->v]=0;

    --minHeap->size;
    minHeapify(minHeap,0);

    return root;
}

void decreaseKey(struct minHeap*minHeap,int v,int key)
{
    int i=minHeap->pos[v];

    minHeap->array[i]->key=key;

    while(i && minHeap->array[i]->key<minHeap->array[(i-1)/2]->key)
    {
        minHeap->pos[minHeap->array[i]->v]=(i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v]=i;
        swapMinHeapNode(&minHeap->array[i],&minHeap->array[(i-1)/2]);

        i=(i-1)/2;
    }

    //minHeapify(minHeap,i);


}
int isInMinHeap(struct minHeap*minHeap,int v)
{
    if(minHeap->pos[v]<minHeap->size) return 1;
    return 0;
}

void printArr(int dist[], int n, int parent[])
{
    printf("Vertex   Distance from Source              Path\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d \t\t %d \t\t\t ", i, dist[i]);

        // Print path
        int j = i;
        while (j != -1)
        {
            printf("%d ", j);
            j = parent[j];
            if (j != -1)
                printf("-> ");
        }
        printf("\n");
    }
}

void dijkstra(struct Graph*graph,int start)
{
    int V=graph->numVertices;
    int dist[V];
    int parent[V];

    struct minHeap*minHeap=createMinHeap(V);

    for(int v=0;v<V;v++)
    {
        dist[v]=INF;
        minHeap->array[v]=createMinHeapNode(v,dist[v]);
        minHeap->pos[v]=v;
        parent[v]=-1;
    }

    //minHeap->array[start]=createMinHeapNode(start,dist[start]);
    //minHeap->pos[start]=start;
    dist[start]=0;

    decreaseKey(minHeap,start,dist[start]);

    minHeap->size=V;

    while(!isHeapEmpty(minHeap))
    {
        struct minHeapNode* minHeapNode=extractMin(minHeap);
        int u=minHeapNode->v;

        struct Node*pCrawl=graph->adj[u];

        while(pCrawl)
        {
            int v=pCrawl->vertex;

            if(isInMinHeap(minHeap,v) && dist[u]!=INF && pCrawl->weight+dist[u]<dist[v])
            {
                dist[v]=dist[u]+pCrawl->weight;
                parent[v]=u;

                decreaseKey(minHeap,v,dist[v]);
            }
            pCrawl=pCrawl->next;
        }
    }
    printArr(dist, V,parent);

    
}


int main()
{
    // create the graph given in above figure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
 
    dijkstra(graph, 0);
 
    return 0;
}



