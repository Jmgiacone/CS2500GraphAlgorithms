#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
class Node
{
public:
    int id, x, y, pi;
    bool visited;
    Node();
    Node(int anId, int anX, int aY);
    Node(int anId);

    friend ostream& operator << (ostream& out, const Node n)
    {
        out << "Node #" << n.id << " is at position (" << n.x << ", " << n.y << ")";
        return out;
    }
};

#endif
