#include <stddef.h>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
    head = NULL;
}

AdjacencyList::~AdjacencyList()
{
    /*
    AdjacencyListNode* tmp1 = head;
    AdjacencyListNode* tmp2 = NULL;

    while(tmp1 != NULL)
    {
        tmp2 = tmp1->next;

        delete tmp1;

        tmp1 = tmp2;
    }

    tmp1 = NULL;
    tmp2 = NULL;*/
    delete head;

}
