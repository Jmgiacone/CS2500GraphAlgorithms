#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Graph.h"
#include "Node.h"

using namespace std;

void dfsVisit(Graph g, int n);
int numConnectedComponents(Graph g);
int numElementsInTree(Graph g, int id);
int sizeOfLargestConnectedComponent(Graph g);
float averageNodeDistance(Graph g);
int diameterOfGraph(Graph g);
bool inRange(Node& a, Node& b, int range);
const int AOI_LENGTH = 500, AOI_WIDTH = 500;
int main()
{
    srand(time(NULL));
    int numNodes = 5, range = 100;
    Graph g(numNodes);
    Node* nodes = new Node[numNodes];

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    /*for(int i = 0; i < numNodes; i++)
    {
        nodes[i].setId(i);
        nodes[i].setX(rand() % AOI_WIDTH);
        nodes[i].setY(rand() % AOI_LENGTH);

        cout << nodes[i] << endl;
    }

    for(int i = 0; i < numNodes; i++)
    {
        for(int j = 0; j < numNodes; j++)
        {
            if(j != i && inRange(nodes[i], nodes[j], range))
            {
                g.addEdge(nodes[i].id, nodes[j].id);
            }
        }
    }*/

    cout << g << endl;

    cout << numConnectedComponents(g) << endl;
    g.reset();
    cout << sizeOfLargestConnectedComponent(g) << endl;
    return 0;
}

int numConnectedComponents(Graph g)
{
    int count = 0;
    for(int i = 0; i < g.numVertices; i++)
    {
        if(!g.nodes[i]->visited)
        {
            dfsVisit(g, g.nodes[i]->id);
        }
    }

    for(int i = 0; i < g.numVertices; i++)
    {
        if(g.nodes[i]->pi == -1)
        {
            count++;
        }
    }

    return count;
}

void dfsVisit(Graph g, int n)
{
    int id;
    g.nodes[n]->visited = true;
    Node* tmp = g.list[n].head;
    while(tmp != NULL)
    {
        id = tmp->id;
        if(!g.nodes[id]->visited)
        {
            g.nodes[id]->pi = g.nodes[n]->id;
            g.nodes[id]->visited = true;
            dfsVisit(g, tmp->id);
        }
        tmp = tmp->next;
    }
}

bool inRange(Node& a, Node& b, int range)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) <= range;
}

int sizeOfLargestConnectedComponent(Graph g)
{
    int count = 1, largest = 0;

    for(int i = 0; i < g.numVertices; i++)
    {
        if(!g.nodes[i]->visited)
        {
            dfsVisit(g, g.nodes[i]->id);
        }
    }

    for(int i = 0; i < g.numVertices; i++)
    {
        if(g.nodes[i]->pi == -1)
        {
            count = numElementsInTree(g, g.nodes[i]->id);
        }

        if(count > largest)
        {
            largest = count;
        }
    }

    return largest;
}

int numElementsInTree(Graph g, int id)
{
    int count = 0;

    for(int i = 0; i < g.numVertices; i++)
    {
        if(g.nodes[i]->pi == id)
        {
            count += numElementsInTree(g, g.nodes[i]->id);
        }
    }

    return count + 1;
}
