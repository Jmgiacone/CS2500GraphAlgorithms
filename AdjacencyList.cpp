#include <stddef.h>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
    head = NULL;
}

AdjacencyList::~AdjacencyList()
{
    delete head;
}
