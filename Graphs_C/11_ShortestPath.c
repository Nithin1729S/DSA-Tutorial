
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 35000

int cityMappingToNums(char* cityName)
{
    char* places[] = {"Bangalore", "Delhi", "Mumbai", "Chennai", "Kolkata", "Hyderabad", "Jaipur", "Ahmedabad", "Pune"};
    for (int i = 0; i < sizeof(places) / sizeof(char*); i++)
    {
        if (strcmp(cityName, places[i]) == 0)
            return i;
    }
    return -1; // return -1 if city name is not found
}

char* cityNumsToName(int cityNum)
{
    char* places[] = {"Bangalore", "Delhi", "Mumbai", "Chennai", "Kolkata", "Hyderabad", "Jaipur", "Ahmedabad", "Pune"};
    if (cityNum >= 0 && cityNum < sizeof(places) / sizeof(char*))
        return places[cityNum];
    return NULL; // return NULL if city number is out of bounds
}

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adj;
};

struct Node* createNewNode(int vertex, int weight)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adj = (struct Node**)malloc(sizeof(struct Node*) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, char* source, char* destination, int weight)
{
    int src = cityMappingToNums(source);
    int dest = cityMappingToNums(destination);

    struct Node* newNode = createNewNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNewNode(src, weight);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

struct minHeapNode
{
    int v;
    int key;
};

struct minHeap
{
    int capacity;
    int size;
    int* pos;
    struct minHeapNode** array;
};

struct minHeapNode* createMinHeapNode(int vertex, int key)
{
    struct minHeapNode* minHeapNode = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    minHeapNode->v = vertex;
    minHeapNode->key = key;
    return minHeapNode;
}

struct minHeap* createMinHeap(int vertices)
{
    struct minHeap* minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->capacity = vertices;
    minHeap->size = 0;
    minHeap->pos = (int*)malloc(sizeof(int) * vertices);
    minHeap->array = (struct minHeapNode**)malloc(sizeof(struct minHeapNode*) * vertices);
    return minHeap;
}

void swapHeapNodes(struct minHeapNode** a, struct minHeapNode** b)
{
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct minHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx)
    {
        struct minHeapNode* smallestNode = minHeap->array[smallest];
        struct minHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isHeapEmpty(struct minHeap* minHeap)
{
    return minHeap->size == 0;
}

int isNodeInHeap(struct minHeap* minHeap, int vertex)
{
    return minHeap->pos[vertex] < minHeap->size;
}

struct minHeapNode* extractMin(struct minHeap* minHeap)
{
    if (isHeapEmpty(minHeap))
        return NULL;

    struct minHeapNode* root = minHeap->array[0];
    struct minHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;

    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct minHeap* minHeap, int v, int key)
{
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    while (i > 0 && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapHeapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void printArr(int dist[], int n, int parent[])
{

    printf("Vertex   Distance from Source   Path\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%s \t\t %d \t\t\t ", cityNumsToName(i), dist[i]);

        // Print path
        int j = i;
        while (j != -1)
        {
            printf("%s ", cityNumsToName(j));
            j = parent[j];
            if (j != -1)
                printf("-> ");
        }
        printf("\n");
    }
}

void dijkstra(struct Graph* graph, char* source)
{

    int

 src = cityMappingToNums(source);
    int V = graph->numVertices;
    int parent[V];
    int dist[V];

    struct minHeap* minHeap = createMinHeap(V);

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
        minHeap->pos[i] = i;
        minHeap->array[i] = createMinHeapNode(i, dist[i]);
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = V;

    while (!isHeapEmpty(minHeap))
    {
        struct minHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        struct Node* pCrawl = graph->adj[u];

        while (pCrawl)
        {
            int v = pCrawl->vertex;
            if (dist[u] != INF && isNodeInHeap(minHeap, v) && dist[v] > dist[u] + pCrawl->weight)
            {
                dist[v] = dist[u] + pCrawl->weight;
                parent[v] = u;

                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    printArr(dist, V, parent);
}

int main()
{
    // create the graph given in above figure
    int V = 9;
    struct Graph* graph = createGraph(V);

    addEdge(graph, "Bangalore", "Delhi", 4);
    addEdge(graph, "Bangalore", "Pune", 2);
    addEdge(graph, "Delhi", "Mumbai", 8);
    addEdge(graph, "Pune", "Mumbai", 3);
    addEdge(graph, "Chennai", "Mumbai", 6);
    addEdge(graph, "Kolkata", "Delhi", 5);
    addEdge(graph, "Chennai", "Kolkata", 4);
    addEdge(graph, "Kolkata", "Hyderabad", 7);
    addEdge(graph, "Hyderabad", "Jaipur", 3);
    addEdge(graph, "Bangalore", "Ahmedabad", 1);

    dijkstra(graph, "Bangalore");

    return 0;
}