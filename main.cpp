#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Graph.h"

using namespace std;

void dfsVisit(Graph* g, int n);//DFS function
void parray (int **a, int b);//test function to output aosp function
int numConnectedComponents(Graph* g);//returns number of separate connected components
float aosp(Graph* g, int& totalDiameter);//average of shortest paths in graph, also finds greatest diameter of largest connected component
int numElementsInTree(Graph* g, int id);//returns number of nodes in a connected component
int sizeOfLargestConnectedComponent(Graph* g);//returns number of nodes of the largest connected components
bool inRange(Node* a, Node* b, int range);//test if two nodes can form a connection
const int AOI_LENGTH = 500, AOI_WIDTH = 500, MIN_NODES = 50, MAX_NODES = 1250, NUM_REPETITIONS = 10, ARBITRARY_RANGE = 20, MIN_RANGE = 5, MAX_RANGE = 85, ARBITRARY_NODES = 200;
const string FILENAME = "GraphTestingSuite.txt";



int main()
{
    srand(time(NULL));
    int numNodes = 0, range = ARBITRARY_RANGE, totalConnectedComponents = 0,
            totalLargestConnectedComponent = 0, totalAverageDistance = 0, totalDiameter = 0 , numRange = 0;
    ofstream outputFile;
    outputFile.open(FILENAME.c_str());
    Graph* g;
    Node** nodes;
    outputFile << "VARYING NUMBER OF NODES WITH TRANSMISSION RANGE OF " << ARBITRARY_RANGE << endl;



    while(numNodes != MAX_NODES)
    {
        numNodes += MIN_NODES;
        cout << numNodes << "\n";
        outputFile << "Number of Nodes: " << numNodes << endl;
        for(int i = 0; i < NUM_REPETITIONS; i++)
        {
            cout << "Rep: " << i+1 << "\n";
            g = new Graph(numNodes);
            nodes = new Node*[numNodes];

            for (int i = 0; i < numNodes; i++)
            {
                nodes[i] = new Node(i,rand() % AOI_WIDTH,rand() % AOI_LENGTH);
            }

            for (int i = 0; i < numNodes; i++) {
                for (int j = 0; j < numNodes; j++) {
                    if (j != i && inRange(nodes[i], nodes[j], range)) {
                        g->addEdge(nodes[i]->id, nodes[j]->id);
                    }
                }
            }

            for(int i = 0; i < numNodes; i++)
            {
                delete nodes[i];
            }
            delete [] nodes;
            nodes = NULL;
            totalConnectedComponents += numConnectedComponents(g);
            g->reset();
            totalLargestConnectedComponent += sizeOfLargestConnectedComponent(g);
            g->reset();
            totalAverageDistance += aosp(g, totalDiameter);

            delete g;
            g = NULL;
        }

        outputFile << "Average number of Connected Components: " << totalConnectedComponents / static_cast<float>(NUM_REPETITIONS) << endl;
        outputFile << "Average size of the largest connected Component: " << totalLargestConnectedComponent / static_cast<float>(NUM_REPETITIONS) << endl;
        outputFile << "Average of the average node distance: " << totalAverageDistance / static_cast<float>(NUM_REPETITIONS) << endl;
        outputFile << "Average Diameter: " << totalDiameter / static_cast<float>(NUM_REPETITIONS) << endl;

        totalConnectedComponents = 0;
        totalLargestConnectedComponent = 0;
        totalAverageDistance = 0;
        totalDiameter = 0;
    }

    cout << "Node done Range started\n";

    ///////
    while(numRange != MAX_RANGE)
    {
        numRange += MIN_RANGE;
        cout << numRange << "\n";
        outputFile << "Range: " << numRange << endl;
        for(int i = 0; i < NUM_REPETITIONS; i++)
        {
            cout << "Rep: " << i+1 << "\n";

            g = new Graph(ARBITRARY_NODES);
            nodes = new Node*[ARBITRARY_NODES];

            for (int i = 0; i < ARBITRARY_NODES; i++)
            {
                nodes[i] = new Node(i,rand() % AOI_WIDTH,rand() % AOI_LENGTH);

            }


            for (int i = 0; i < ARBITRARY_NODES; i++) {
                for (int j = 0; j < ARBITRARY_NODES; j++) {
                    if (j != i && inRange(nodes[i], nodes[j], numRange)) {
                        g->addEdge(nodes[i]->id, nodes[j]->id);

                    }
                }
            }



            for(int i = 0; i < ARBITRARY_NODES; i++)
            {
                delete nodes[i];

            }

            delete [] nodes;

            nodes = NULL;

            totalConnectedComponents += numConnectedComponents(g);

            g->reset();

            totalLargestConnectedComponent += sizeOfLargestConnectedComponent(g);

            g->reset();

            totalAverageDistance += aosp(g, totalDiameter);
            cout << "\n++Deleting++\n";

            delete g;
            cout << "\n++Deleted++\n";
            g = NULL;
        }

        outputFile << "Average number of Connected Components: " << totalConnectedComponents / static_cast<float>(NUM_REPETITIONS) << endl;
        outputFile << "Average size of the largest connected Component: " << totalLargestConnectedComponent / static_cast<float>(NUM_REPETITIONS) << endl;
        outputFile << "Average of the average node distance: " << totalAverageDistance / static_cast<float>(NUM_REPETITIONS) << endl;
        outputFile << "Average Diameter: " << totalDiameter / static_cast<float>(NUM_REPETITIONS) << endl;

        totalConnectedComponents = 0;
        totalLargestConnectedComponent = 0;
        totalAverageDistance = 0;
        totalDiameter = 0;
    }

    return 0;
}

int numConnectedComponents(Graph* g)
{
    int count = 0;
    for(int i = 0; i < g->numVertices; i++)
    {
        if(!g->nodes[i]->visited)
        {
            dfsVisit(g, g->nodes[i]->id);
        }
    }

    for(int i = 0; i < g->numVertices; i++)
    {
        if(g->nodes[i]->pi == -1)
        {
            count++;
        }
    }

    return count;
}

void dfsVisit(Graph* g, int n)
{
    int id;
    g->nodes[n]->visited = true;
    AdjacencyListNode* tmp = g->list[n]->head;
    while(tmp != NULL)
    {
        id = tmp->id;
        if(!g->nodes[id]->visited)
        {
            g->nodes[id]->pi = g->nodes[n]->id;
            g->nodes[id]->visited = true;
            dfsVisit(g, tmp->id);
        }
        tmp = tmp->next;
    }
}

bool inRange(Node* a, Node* b, int range)
{
    return pow((a->x - b->x),2) + pow((a->y - b->y) , 2) <= pow(range,2);
}

int sizeOfLargestConnectedComponent(Graph* g)
{
    int count = 1, largest = 0;

    for(int i = 0; i < g->numVertices; i++)
    {
        if(!g->nodes[i]->visited)
        {
            dfsVisit(g, g->nodes[i]->id);
        }
    }

    for(int i = 0; i < g->numVertices; i++)
    {
        if(g->nodes[i]->pi == -1)
        {
            count = numElementsInTree(g, g->nodes[i]->id);
        }

        if(count > largest)
        {
            largest = count;
        }
    }

    return largest;
}

int numElementsInTree(Graph* g, int id)
{
    int count = 0;

    for(int i = 0; i < g->numVertices; i++)
    {
        if(g->nodes[i]->pi == id)
        {
            count += numElementsInTree(g, g->nodes[i]->id);
        }
    }

    return count + 1;
}

float aosp(Graph* g, int& totalDiameter)//average of shortest paths
{
    //cout << "break";
    int numVerts = g->numVertices;

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
                aosparray[i][j]=9999;
            }
        }

        AdjacencyListNode* temp = g->list[i]->head;

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
    //parray(aosparray, numVerts);

    float sum = 0;
    float div = 0;
    int d = 0;

    for(int i = 0 ; i < numVerts ; i++)
    {
        for(int j = 0 ; j < numVerts ; j++)
        {
            if(aosparray[i][j] > 0 && aosparray[i][j] < 9999)
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

    totalDiameter += d;
    return (div == 0 ? 0 : sum/div);


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




