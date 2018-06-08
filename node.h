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
        this->name;
      }

      Node(string name, bool allowed, int value)
      {
        this->name= name;
        this->is_allowed= allowed;
        this->num= value;
      }



      Node(Node& n)
      {
        
       this->num= n.num;
       this->is_allowed= n.is_allowed;
       this->name= n.name;
      }


     virtual ~Node()
      {
        
      }

      Node& operator=(Node& n)
      {
        this->num=n.num;
        this->name=n.name;
        this->is_allowed= n.is_allowed;
        return *this;
      }

string getname()
{
  return this->name;
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
    cout<<this->name<<" "<<this->is_allowed<<" "<<this->num<<endl;
 }

virtual istream& fileInput(std::istream& is)
{
  is>>name>>is_allowed>>num;
  return is;
}
 

      

friend ostream& operator<<(ostream& out, Node N)
{
  return out<<N.name<<" "<<N.is_allowed<<" "<<N.num<<endl;
}

friend std::istream& operator >> (std::istream & is, Node  *s)
{
    is >> s->name >> s->is_allowed >> s->num;
    return is;
} 

   


protected:
string name;
bool is_allowed;
int num;

};
#endif