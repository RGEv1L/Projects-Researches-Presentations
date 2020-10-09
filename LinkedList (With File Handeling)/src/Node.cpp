#include "Node.h"

Node::Node()
{
    next = nullptr;
    prev = nullptr;
    name = "";
    format = "";
    loc = "";
    id   = 0;
    hours = 0;
    mins = 0;
    secs = 0;
    v_size = 0;
    d_created = 0;
    rating = 0;

}


//Setters
void Node::setID(int x)
{
    id = x;
}
void Node::setHours(int x)
{
    hours = x;
}
void Node::setMins(int x)
{
    mins = x;
}
void Node::setSecs(int x)
{
    secs = x;
}
void Node::setV_Size(int x)
{
    v_size = x;
}
void Node::setD_Created(int x)
{
    d_created = x;
}
void Node::setRating(int x)
{
    rating = x;
}
void Node::setName(string x)
{
    name = x;
}
void Node::setFormat(string x)
{
    format = x;
}
void Node::setLoc(string x)
{
    loc = x;
}
void Node::setNext(Node* x)
{
    next = x;
}
void Node::setPrev(Node* x)
{
    prev = x;
}


//Getters

int Node::getID()
{
    return id;
}
int Node::getHours()
{
    return hours;
}
int Node::getMins()
{
    return mins;
}
int Node::getSecs()
{
    return secs;
}
int Node::getV_Size()
{
    return v_size;
}
int Node::getD_Created()
{
    return d_created;
}
int Node::getRating()
{
    return rating;
}
string Node::getName()
{
    return name;
}
string Node::getFormat()
{
    return format;
}
string Node::getLoc()
{
    return loc;
}
Node* Node::getNext()
{
    return next;
}
Node* Node::getPrev()
{
    return prev;
}

