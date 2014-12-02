#include "Node.h"

Node::Node()
{
    //ctor
}

Node::~Node()
{
    //dtor
}

Node::Node(const Node& other)
{
    //copy ctor
}

Node& Node::operator=(const Node& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Node::Link(vector<Node> g)
{
    for(int i = 0; i < g.size(); i++)
    {
        if((x - g[i].x)**2 + (y - g[i].y)**2 <= r**2)
        {
            adjNodes.push_back(g[i]);
        }
    }
}


