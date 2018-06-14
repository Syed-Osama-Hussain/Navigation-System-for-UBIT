#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

#ifndef node_h
#define node_h


class Node{
public:
      Node()
      {
        this->num=0;
        this->is_allowed=false;
        this->name=" ";
        this->floor=0;
      }

      Node(string name, bool allowed, int value,int floor)
      {
        this->name= name;
        this->is_allowed= allowed;
        this->num= value;
        this->floor= floor;
      }



      Node(Node& n)
      {
        
       this->num= n.num;
       this->is_allowed= n.is_allowed;
       this->name= n.name;
       this->floor=n.floor;
      }


     virtual ~Node()
      {
        
      }

      Node& operator=(Node& n)
      {
        this->num=n.num;
        this->name=n.name;
        this->is_allowed= n.is_allowed;
        this->floor=n.floor;
        return *this;
      }

string getname()
{
  return this->name;
}

int getfloor()
{
  return this->floor;
}


int getnum()
{
  return this->num;
}


bool getIs_allowed()
{
  return this->is_allowed;
}


virtual void display()
 {
    cout<<this->name<<" "<<this->is_allowed<<" "<<this->num<<" "<<floor<<endl;
 }

virtual istream& fileInput(std::istream& is)
{
  is>>name>>is_allowed>>num>>floor;
  return is;
}
 

      

friend ostream& operator<<(ostream& out, Node &N)
{
  return out<<N.name<<" "<<N.is_allowed<<" "<<N.num<<" "<<N.floor<<endl;
}

friend std::istream& operator >> (std::istream & is, Node  *s)
{
    is >> s->name >> s->is_allowed >> s->num>>s->floor;
    return is;
} 

   


protected:
string name;
bool is_allowed;
int num;
int floor;

};
#endif