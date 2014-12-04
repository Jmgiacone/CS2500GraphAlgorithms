#include "AdjacencyList.h"
class Graph
{
public:
    Graph(int vertices);
    bool addEdge(const int u, const int v);

    friend ostream& operator << (ostream& out, const Graph g)
    {
        int v;
        for (v = 0; v < g.numVertices; ++v)
        {
            Node* pCrawl = g.list[v].head;
            out << "\n Adjacency list of vertex " << v << "\n head";
            while (pCrawl)
            {
                out << " -> " << pCrawl->id;
                pCrawl = pCrawl->next;
            }
            out << "\n";
        }

        return out;
    }
private:
    int numVertices;
    AdjacencyList* list;
};