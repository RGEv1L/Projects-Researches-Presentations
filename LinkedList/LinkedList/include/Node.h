#ifndef NODE_H
#define NODE_H
#include<string>
#include<iostream>
using namespace std;

class Node
{
    public:
        Node();

        //Setters
        void    setName(string);
        void    setID(int);
        void    setMarks(int);
        void    setNext(Node*);

        //Getters
        string  getName();
        int     getID();
        int     getMarks();
        Node*   getNext();

    private:
        Node *next;
        string name;
        int id,marks;
};

#endif // NODE_H
