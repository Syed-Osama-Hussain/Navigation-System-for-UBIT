#include <iostream>
#include "node.h"
using namespace std;

#ifndef node_cpp
#define node_cpp

    Node::Node()
      {
        this->num=0;
        this->name=" ";
        this->floor=0;
      }

      Node::Node(string name,int value,int floor)
      {
        this->name= name;
        this->num= value;
        this->floor= floor;
      }



      Node::Node(Node& n)
      {
        
       this->num= n.num;
       this->name= n.name;
       this->floor=n.floor;
      }


     Node::~Node()
      {
        
      }

      string Node::getroom_code()
      {

      }

      string Node::getTeacher_name()
      {
        
      }

      string Node::get_purpose()
      {

      }

      Node& Node::operator=(Node& n)
      {
        this->num=n.num;
        this->name=n.name;
        this->floor=n.floor;
        return *this;
      }

string Node::getname()
{
  return this->name;
}

int Node::getfloor()
{
  return this->floor;
}


int Node::getnum()
{
  return this->num;
}



void Node::display()
 {
    cout<<this->name<<" "<<this->num<<" "<<floor<<endl;
 }

istream& Node::fileInput(std::istream& is)
{
  is>>name>>num>>floor;
  return is;
}
 

ostream& operator<<(ostream& out, Node &N)
{
  return out<<N.name<<" "<<N.num<<" "<<N.floor<<endl;
}

std::istream& operator >> (std::istream & is, Node  *s)
{
    is >> s->name>>s->num>>s->floor;
    return is;
} 
#endif