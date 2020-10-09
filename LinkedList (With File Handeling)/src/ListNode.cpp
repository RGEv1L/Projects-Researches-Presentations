#include "ListNode.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<ctime>
using namespace std;


ListNode::ListNode()
{
    head    =   nullptr;
    tail    =   nullptr;
}

int ListNode::menu()
{
    cout<<"Please choose the entries from the menu below.\n";
    cout<<"\n2.Press 1 to add entry at the end of the List";
    cout<<"\n4.Press 2 to display List";
    cout<<"\n5.Press 3 to delete a Node";
    cout<<"\n5.Press 4 write List to a File\n>>";
    int x;
    cin>>x;     //Menu selection from the user

    return x;   //Returning the choice

}

void ListNode::driver()
{
    int flag = 0;       //Control Variable

    while (flag <= 4)
    {
      flag = menu();    //Recalls menu function on every iteration

      if (flag == 1)
      {
        eNode();
      }
      else if (flag == 2)
      {
        display();
        system("pause");
        system("cls");
      }
      else if(flag == 3)
      {
        dNode();
        system("pause");
        system("cls");
      }
      else if (flag == 4)
      {
        system("Cls");
        wList();
        system("pause");
        system("cls");
      }




    }


}

void ListNode::eNode()
{
    system("cls");

    int p,q,r,s,t,u,v;
    string a,b,c;

    Node *temp = new Node();

    //Taking Data inputs for Node
    cout<<"Enter Name:";
    cin>>a;
    cout<<"\nEnter Format:";
    cin>>b;
    cout<<"\nEnter Location:";
    cin>>c;
    cout<<"\nEnter ID:";
    cin>>p;
    cout<<"\nEnter Hours:";
    cin>>q;
    cout<<"\nEnter Minutes:";
    cin>>r;
    cout<<"\nEnter Seconds:";
    cin>>s;
    cout<<"\nEnter Video Size:";
    cin>>t;
    cout<<"\nEnter Date of Video creation:";
    cin>>u;
    cout<<"\nEnter Rating of Video:";
    cin>>v;

    //Calling Setters
    temp->setName(a);
    temp->setFormat(b);
    temp->setLoc(c);
    temp->setID(p);
    temp->setHours(q);
    temp->setMins(r);
    temp->setSecs(s);
    temp->setV_Size(t);
    temp->setD_Created(u);
    temp->setRating(v);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
        head->setPrev(nullptr);
        temp = nullptr;
    }
    else
    {
        tail->setNext(temp);
        temp->setPrev(tail);
        tail = temp;
    }
    system("cls");

}


void ListNode::dNode()
{
    system("cls");

    if(!isEmpty())  //Check if List is already empty
    {
        string name; //Name of Node to be deleted

        cout<<"Enter the name of Student to delete its profile>>";
        cin>>name;

        Node *temp = new Node();
        Node *pre = new Node();
        Node *nex = new Node();
        temp = head;


        while(temp != nullptr)
        {
            //Condition if the node required is the first element of List
            if(temp == head  && temp->getName()== name )
            {
                head = head->getNext();
                cout<<"The Node entry for '"<<name<<"' has been deleted successfully\n";
                break;
            }
            //Deleting in between
            else if(temp != head && temp != tail && temp->getName() == name )
            {
                nex = temp->getNext();
                pre = temp->getPrev();
                nex->setPrev(pre);
                pre->setNext(nex);
                cout<<"The Node entry for '"<<name<<"' has been deleted successfully\n";
                break;
            }
            else if( temp == tail && temp->getName()== name )
            {
                tail = tail->getPrev();
                tail->setNext(nullptr);
                cout<<"The Node entry for '"<<name<<"' has been deleted successfully\n";
                break;

            }
            temp = temp->getNext();
        }
        //Condition if none of the element matched
        if(temp == nullptr)
            {
            cout<<"No Matching Entry\n";
            cin.ignore();
            }

    }
    else
        cout<<"List is Empty\n";


}

bool ListNode::isEmpty()    //Function to check if list is empty or not
{
    if(head == nullptr )
        return 1;
    else
        return 0;

}

void ListNode::display()
{
    system("cls");


        Node *temp = new Node();
        temp = head;

    if(!isEmpty())
    {
        while(temp != nullptr)
        {
            //Printing Node Elements
            cout<<"Name:"<<temp->getName();
            cout<<"\nFormat:"<<temp->getFormat();
            cout<<"\nLocation:"<<temp->getLoc();
            cout<<"\nID:"<<temp->getID();
            cout<<"\nHours:"<<temp->getHours();
            cout<<"\nMinutes:"<<temp->getMins();
            cout<<"\nSeconds:"<<temp->getSecs();
            cout<<"\nSize:"<<temp->getV_Size();
            cout<<"\nDate Created:"<<temp->getD_Created();
            cout<<"\nRating:"<<temp->getRating();
            temp = temp->getNext();
            cout<<"\n--------------------------------------\n";
        }
    }

    else
    cout<<"The List is Empty\n";



}

void ListNode::wList()
{
    time_t now = time(0);       //Time Object
    char* dt = ctime(&now);    //Time Pointer

    fstream file;   //File Object
    file.open("Video List.txt", ios :: app);

        Node *temp = new Node();
        temp = head;

    if(!isEmpty())
    {
        while(temp != nullptr)
        {
            //Writing Node Elements to File
            file<<"Name:"<<temp->getName();
            file<<"\nFormat:"<<temp->getFormat();
            file<<"\nLocation:"<<temp->getLoc();
            file<<"\nID:"<<temp->getID();
            file<<"\nHours:"<<temp->getHours();
            file<<"\nMinutes:"<<temp->getMins();
            file<<"\nSeconds:"<<temp->getSecs();
            file<<"\nSize:"<<temp->getV_Size();
            file<<"\nDate Created:"<<temp->getD_Created();
            file<<"\nRating:"<<temp->getRating();
            temp = temp->getNext();
            file<<"\n--------------------------------------\n";
        }
        file<<"Record was Create on:"<<dt;
    }

    else
    file<<"The List is Empty\n";

    cout<<"File Written Successfully\n";

}

