#ifndef LISTNODE_H
#define LISTNODE_H
#include "Node.h"

class ListNode
{
    public:
        ListNode();
        void    driver();   //Control Function
        void    eNode();    //Insert at front
        int     menu();      //Lists options provided by the program
        bool    isEmpty();  //Empty List check
        void    display();  //Dumps the complete Linked List
        void    dNode();    //Delete a present node
        void    wList();

    private:
        Node*   head;
        Node*   tail;
};

#endif // LISTNODE_H
