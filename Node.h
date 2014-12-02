#ifndef NODE_H
#define NODE_H

using namespace std;

struct Node
{
    void Link(vector<Node> g);

    int x, y, r;
    vector<Node> adjNodes;
    //Node* parent;
    //bool used = false;

};

#endif // NODE_H
