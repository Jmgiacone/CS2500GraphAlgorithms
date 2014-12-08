#ifndef ADJACENCYLISTNODE_H
#define ADJACENCYLISTNODE_H
class AdjacencyListNode
{
public:
    int id;
    AdjacencyListNode* next;
    AdjacencyListNode(int id);
    AdjacencyListNode();
    ~AdjacencyListNode();
};
#endif