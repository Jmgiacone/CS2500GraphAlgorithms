#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "AdjacencyList.h"


using namespace std;

class Graph
{
public:
    Graph(int vertices);
    bool addEdge(const int u, const int v);
    void reset();
    friend ostream& operator << (ostream& out, const Graph g)
    {
        int v;
        for (v = 0; v < g.numVertices; ++v)
        {
            Node* pCrawl = g.list[v].head;
            out << "\n Adjacency list of vertex " << g.nodes[v]->id << "\n head";
            while (pCrawl)
            {
                out << " -> " << pCrawl->id;
                pCrawl = pCrawl->next;
            }
            out << "\n";
        }

        return out;
    }
    int numVertices;
    AdjacencyList* list;
    Node** nodes;
};

#endif
