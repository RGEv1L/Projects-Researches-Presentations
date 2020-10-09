#ifndef LISTNODE_H
#define LISTNODE_H
#include "Node.h"

class ListNode
{
    public:
        ListNode();
        void    driver();   //Control Function
        void    eNode();    //Insert at front
        void    sNode();    //Insert at back
        void    mNode();    //Insert at middle
        int     menu();      //Lists options provided by the program
        bool    isEmpty();  //Empty List check
        void    display();  //Dumps the complete Linked List
        void    upNode();   //Update a present node
        void    dNode();    //Delete a present node

    private:
        Node*   head;
        Node*   tail;
};

#endif // LISTNODE_H
