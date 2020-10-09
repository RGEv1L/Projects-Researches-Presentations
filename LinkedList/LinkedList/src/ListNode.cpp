#include "ListNode.h"
#include<iostream>
using namespace std;


ListNode::ListNode()
{
    head    =   nullptr;
    tail    =   nullptr;
}

int ListNode::menu()
{
    cout<<"Please choose the entries from the menu below.\n";
    cout<<"\n1.Press 1 to add entry at the start of the List";
    cout<<"\n2.Press 2 to add entry at the end of the List";
    cout<<"\n3.Press 3 to add entry at the mid of the List";
    cout<<"\n4.Press 4 to display List";
    cout<<"\n5.Press 5 to delete a Node";
    cout<<"\n6.Press 6 to update a Node";
    cout<<"\n6.Press 7 to delete second Node\n>>";
    int x;
    cin>>x;     //Menu selection from the user

    return x;   //Returning the choice

}

void ListNode::driver()
{
    int flag = 0;

    while (flag <= 6)
    {
      flag = menu();

      if (flag == 1)
      {
        sNode();
      }
      else if (flag == 2)
      {
        eNode();
      }
      else if(flag == 3)
      {
        mNode();
      }
      else if (flag == 4)
      {
        cin.ignore();
        display();
        cin.ignore();
      }
      else if (flag == 5)
      {
        cin.ignore();
        dNode();
        cin.ignore();
      }
      else if (flag == 6)
      {
        cin.ignore();
        upNode();
        cin.ignore();
      }


        cout<<"\n---------------------------------\n";

    }


}

void ListNode::eNode()
{
    int x;
    int y;
    string z;

    Node *temp = new Node();

    //Taking Data inputs for Node
    cout<<"Enter name:";
    cin>>z;
    cout<<"\nEnter ID:";
    cin>>x;
    cout<<"\nEnter Marks:";
    cin>>y;

    //Calling Setters
    temp->setID(x);
    temp->setMarks(y);
    temp->setName(z);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        tail->setNext(temp);
        tail = temp;
    }


}
void ListNode::sNode()
{

    int x;
    int y;
    string z;

    Node *temp = new Node();

    //Taking Data inputs for Node
    cout<<"Enter name:";
    cin>>z;
    cout<<"\nEnter ID:";
    cin>>x;
    cout<<"\nEnter Marks:";
    cin>>y;

    //Calling Setters
    temp->setID(x);
    temp->setMarks(y);
    temp->setName(z);

    temp->setNext(head);
    head = temp;

}

void ListNode::mNode()
{
    if(!isEmpty())
    {

    int pos = 0;//Mid value

    //Determining Midpoint
    Node *mid = new Node();
    mid = head;

    while(mid != nullptr)
    {
        pos++;
        mid = mid->getNext();
    }


    //Starting insertion at midpoint
    Node *pre = new Node();
    Node *cur = new Node();
    Node *temp = new Node();
    cur=head;

    for(int i = 1 ; i < pos ; i++)
    {
      pre = cur;
      cur = cur->getNext();
    }

    //Setters
    int x;
    int y;
    string z;

    //Taking Data inputs for Node
    cout<<"Enter name:";
    cin>>z;
    cout<<"\nEnter ID:";
    cin>>x;
    cout<<"\nEnter Marks:";
    cin>>y;

    //Calling Setters
    temp->setID(x);
    temp->setMarks(y);
    temp->setName(z);


    pre->setNext(temp);
    temp->setNext(cur);
    }

    else
    cout<<"Cant Enter Node in the Middle.List is Empty\n";


}

void ListNode::upNode()
{
    if(!isEmpty())
    {
        string name; //Name of Node to be deleted

        cout<<"Enter the name of Student to update its profile>>";
        cin>>name;

        Node *temp = new Node();
        temp = head;


        while(temp != nullptr)
        {
            if(temp->getName()== name)
            {
                cout<<"Enter New Entries\n";

                int x;
                int y;
                string z;

                //Taking Data inputs for Node
                cout<<"Enter name:";
                cin>>z;
                cout<<"\nEnter ID:";
                cin>>x;
                cout<<"\nEnter Marks:";
                cin>>y;

                //Calling Setters
                temp->setID(x);
                temp->setMarks(y);
                temp->setName(z);
                break;

            }
            temp = temp->getNext();
        }
        if(temp == nullptr)
            {
            cout<<"No Matching Entry\n";
            cin.ignore();
            }

    }
    else
        cout<<"List is Empty\n";

}

void ListNode::dNode()
{
    if(!isEmpty())
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

            if(temp == head && temp->getNext() == nullptr && temp->getName()== name )
            {
                head = nullptr;
                cout<<"The Node entry for '"<<name<<"' has been deleted successfully\n";
                break;
            }
            if(temp == head && temp->getNext() != nullptr && temp->getName()== name )
            {
                head = head->getNext();
                cout<<"The Node entry for '"<<name<<"' has been deleted successfully\n";
                break;
            }
            else if(temp->getName()!= name)
            {
                pre = temp;
            }
            else if(temp->getName()== name)
            {
                nex = temp->getNext();
                pre->setNext(nex);

                //delete &temp;
                cout<<"The Node entry for '"<<name<<"' has been deleted successfully\n";
                break;
            }
            temp = temp->getNext();
        }
        if(temp == nullptr)
            {
            cout<<"No Matching Entry\n";
            cin.ignore();
            }

    }
    else
        cout<<"List is Empty\n";

}

bool ListNode::isEmpty()
{
    if(head == nullptr && tail == nullptr)
        return 1;
    else
        return 0;

}

void ListNode::display()
{

        Node *temp = new Node();
        temp = head;

    if(!isEmpty())
    {
        while(temp != nullptr)
        {
            cout<<"Name:"<<temp->getName();
            cout<<"\nID:"<<temp->getID();
            cout<<"\nMarks:"<<temp->getMarks();
            temp = temp->getNext();
            cout<<"\n--------------------------------------\n";
        }
    }
    else
    cout<<"The List is Empty\n";

}

