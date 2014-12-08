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
