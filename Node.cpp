#include "Node.h"

Node::Node()
{
    id = -1;
}
Node::Node(int anId)
{
    id = anId;
}
Node::Node(int anId, int anX, int aY)
{
    id = anId;
    x = anX;
    y = aY;
}
/*Node::Node(const Node& other)
{
    //copy ctor
}*/
/*
Node& Node::operator=(const Node& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/

