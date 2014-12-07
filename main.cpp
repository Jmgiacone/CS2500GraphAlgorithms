#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Graph.h"
#include "Node.h"

using namespace std;

void dfsVisit(Graph g, int n);
void parray (int **a, int b);
int numConnectedComponents(Graph g);
float aosp(Graph g);
int numElementsInTree(Graph g, int id);
int sizeOfLargestConnectedComponent(Graph g);
float averageNodeDistance(Graph g);
int diameterOfGraph(Graph g);
bool inRange(Node& a, Node& b, int range);
const int AOI_LENGTH = 500, AOI_WIDTH = 500;

int main()
{
    srand(time(NULL));
    int numNodes = 10, range = 100;

    Graph g(numNodes);
    Node* nodes = new Node[numNodes];

    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 8);
    g.addEdge(3, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 9);
    g.addEdge(1, 0);

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

    cout << "\nAoSP result: " << aosp(g) << "\n";

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
    return pow((a.x - b.x),2) + pow((a.y - b.y) , 2) <= pow(range,2);
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

float aosp(Graph g)//average of shortest paths
{
    cout << "break";
    int numVerts = g.numVertices;

    int **aosparray;

    aosparray = new int *[numVerts];
    for(int i = 0; i < numVerts;i++)
    {
        aosparray[i] = new int[numVerts];
    }

    for(int i = 0; i < numVerts;i++)
    {
        for(int j = 0; j < numVerts;j++)
        {
            if(i==j)
            {
                aosparray[i][j]=0;
            }
            else
            {
                aosparray[i][j]=999;
            }
        }

        Node* temp = g.list[i].head;

        while(temp != NULL)
        {
            aosparray[i][temp->id]=1;
            temp = temp->next;
        }
    }

    for(int i = 0 ; i < numVerts ; i++)
    {
        for(int j = 0 ; j < numVerts ; j++)
        {
            for(int k = 0 ; k < numVerts ; k++)
            {
                if(aosparray[j][k] > aosparray[j][i] + aosparray[i][k] &&  aosparray[j][i] > 0 && aosparray[i][k] > 0)
                {
                    aosparray[j][k] = aosparray[j][i] + aosparray[i][k];
                }
            }
        }

    }
    parray(aosparray, numVerts);

    float sum = 0;
    float div = 0;
    int d = 0;

    for(int i = 0 ; i < numVerts ; i++)
    {
        for(int j = 0 ; j < numVerts ; j++)
        {
            if(aosparray[i][j] > 0 && aosparray[i][j] < 999)
            {
                sum += aosparray[i][j];
                div += 1;

                if(aosparray[i][j] > d)
                {
                    d = aosparray[i][j];
                }
            }
        }
    }

    cout << "\nDiameter = " << d << "\n\n";

    return (sum/div);


}

void parray(int **a, int b)
{
    cout << "\n";

    for(int i = 0; i < b;i++)
    {
        for(int j = 0; j < b;j++)
        {
            if(a[i][j] > -1 && a[i][j] < 10)
            {
                cout << "  ";
            }
            else if(a[i][j] == -1 || (a[i][j] > 9 && a[i][j] < 100))
            {
                cout << " ";
            }
            cout << a[i][j] << "   ";
        }

        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
}




