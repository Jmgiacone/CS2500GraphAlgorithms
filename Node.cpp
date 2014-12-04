#include "Node.h"

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

