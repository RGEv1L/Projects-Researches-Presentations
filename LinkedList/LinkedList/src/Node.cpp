#include "Node.h"

Node::Node()
{
    next = nullptr;
    name = "";
    id   = 0;
    marks= 0;
}


//Setters
void Node::setID(int x)
{
    id = x;
}
void Node::setMarks(int x)
{
    marks = x;
}
void Node::setName(string x)
{
    name = x;
}
void Node::setNext(Node* x)
{
    next = x;
}


//Getters

int Node::getID()
{
    return id;
}
int Node::getMarks()
{
    return marks;
}
string Node::getName()
{
    return name;
}
Node* Node::getNext()
{
    return next;
}

