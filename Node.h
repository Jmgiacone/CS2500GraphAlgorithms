#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
class Node
{
public:
    Node* next;
    int id, x, y, start, end, pi;
    bool visited;
    Node() : pi(-1), next(NULL), id(-1), x(-1), y(-1), start(-1), end(-1), visited(false){};
    Node(int anId);
    //~Node() {delete pi; delete next;};
    void setId(int idVal) {id = idVal;};
    void setX(int xVal) {x = xVal;};
    void setY(int yVal) {y = yVal;};
    void setStart(int startVal) {start = startVal;};
    void setEnd(int endVal) {end = endVal;};
    void setVisited(bool visitedVal) {visited = visitedVal;};
    bool setPi(int piVal) {pi = piVal;};

    friend ostream& operator << (ostream& out, const Node n)
    {
        out << "Node #" << n.id << " is at position (" << n.x << ", " << n.y << ")";
        return out;
    }
};

#endif
