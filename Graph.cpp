#include "Graph.h"

Graph::Graph(int vertices)
{
    numVertices = vertices;
    list = new AdjacencyList[numVertices];

    for(int i = 0; i < numVertices; i++)
    {
        list[i].id = i;
        list[i].head = NULL;
    }
}

bool Graph::addEdge(const int u, const int v)
{
    if(u < 0 || v < 0 || u >= numVertices || v >= numVertices)
    {
        return false;
    }

    Node* tmp = list[u].head;
    while(tmp != NULL)
    {
        if(tmp->id == v)
        {
            return false;
        }
        else
        {
            tmp = tmp -> next;
        }
    }
    Node* src = new Node();
    Node* dest = new Node();

    src -> id = u;
    src -> next = list[v].head;
    list[v].head = src;

    dest -> id = v;
    dest -> next = list[u].head;
    list[u].head = dest;

    return true;
}