#include "Node.h"

struct AdjacencyList
{
    int id;
    Node* head;
    ~AdjacencyList() {delete head;};
};