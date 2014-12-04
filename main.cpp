#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Graph.h"
#include "Node.h"

using namespace std;

bool inRange(Node& a, Node& b, int range);
const int AOI_LENGTH = 500, AOI_WIDTH = 500;
int main()
{
    srand(time(NULL));
    int numNodes = 5, range = 250;
    Graph g(numNodes);
    Node* nodes = new Node[numNodes];

    for(int i = 0; i < numNodes; i++)
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
    }

    cout << g << endl;
    return 0;
}

bool inRange(Node& a, Node& b, int range)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) <= range;
}
