#include "Graph.h"

Graph::~Graph()
{
    for(int i = 0; i < numVertices; i++)
    {
        delete nodes[i];
        delete list[i];
    }

    delete [] list;
    delete [] nodes;
    list = NULL;
    nodes = NULL;
}
Graph::Graph()
{
    numVertices = 0;
    list = NULL;
    nodes = NULL;
}
Graph::Graph(int vertices)
{
    numVertices = vertices;

    list = new AdjacencyList*[numVertices];
    nodes = new Node*[numVertices];

    for(int i = 0; i < numVertices; i++)
    {
        list[i] = new AdjacencyList();
        nodes[i] = new Node(i);
    }
}

//Resets pi and visited values
void Graph::reset()
{
    for(int i = 0; i < numVertices; i++)
    {
        nodes[i]->pi = -1;
        nodes[i]->visited = false;
    }
}

bool Graph::addEdge(const int u, const int v)
{
    //Can't add if out-of-bounds
    if(u < 0 || v < 0 || u >= numVertices || v >= numVertices)
    {
        return false;
    }

    AdjacencyListNode* tmp = list[u]->head;

    //Checking if alread added
    while(tmp != NULL)
    {
        if(tmp->id == v)
        {
            return false;
        }

        tmp = tmp -> next;
    }

    AdjacencyListNode* src = new AdjacencyListNode(u);
    AdjacencyListNode* dest = new AdjacencyListNode(v);

    //Traincar chaining
    src -> next = list[v]->head;
    list[v]->head = src;

    dest -> next = list[u]->head;
    list[u]->head = dest;

    src = NULL;
    dest = NULL;
    tmp = NULL;

    return true;
}