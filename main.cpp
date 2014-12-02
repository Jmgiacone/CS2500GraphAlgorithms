// Project #2
// Jesse White, Jordan Giacone, Nick Argast

#include <iostream>
#include <random>
#include <ctime>
#include "Node.h"
using namespace std;

vector<Node> testNodes;

main() // purely test of node struct
{
    for(int i = 0; i < 10; i++)
    {
        Node temp;
        testNodes.push_back(temp);
        testNodes[i].x = rand()%100;
        testNodes[i].y = rand()%100;
        testNodes[i].r = 50;
    }

    for(int i = 0; i < 10; i++)
    {
        testNodes[i].Link(testNodes);
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < testNodes[i].adjNodes.size(); j++)
        {
            std::cout << testNodes[i].x << ", " << testNodes[i].y << " is linked to " << testNodes[i].adjNodes[j].x << ", " << testNodes[i].adjNodes[j].y << ".\n";
        }
    }
}
