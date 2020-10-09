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
        void    setName(string);    //Name of Video
        void    setFormat(string);  //Format of Video
        void    setLoc(string);     //Location in Directory of Video
        void    setID(int);         //Unique ID of the Video
        void    setHours(int);      //Hours of video length
        void    setMins(int);       //Minutes of video length
        void    setSecs(int);       //Seconds of Video length
        void    setV_Size(int);     //Total Size of Video
        void    setD_Created(int);  //Date on which video was created
        void    setRating(int);     //User Defined rating of Video
        void    setNext(Node*);
        void    setPrev(Node*);

        //Getters
        string  getName();
        string  getFormat();
        string  getLoc();
        int     getID();
        int     getHours();
        int     getMins();
        int     getSecs();
        int     getV_Size();
        int     getD_Created();
        int     getRating();
        Node*   getNext();
        Node*   getPrev();

    private:
        Node *next,*prev;
        string name,format,loc;
        int id,hours,mins,secs,v_size,d_created,rating;
};

#endif // NODE_H
