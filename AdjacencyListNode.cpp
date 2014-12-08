#include <stddef.h>
#include "AdjacencyListNode.h"

AdjacencyListNode::AdjacencyListNode()
{
    id = -1;
    next = NULL;
}
AdjacencyListNode::AdjacencyListNode(int anId)
{
    id = anId;
    next = NULL;
}
AdjacencyListNode::~AdjacencyListNode()
{
    //Run through and delete nodes that are chained to this one
    AdjacencyListNode* tmp1 = next;
    AdjacencyListNode* tmp2 = NULL;

    while(tmp1 != NULL)
    {
        tmp2 = tmp1->next;

        delete tmp1;

        tmp1 = tmp2;
    }

    tmp1 = NULL;
    tmp2 = NULL;
}