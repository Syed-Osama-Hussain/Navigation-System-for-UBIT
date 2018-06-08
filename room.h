#include <iostream>
#include "node.h"
using namespace std;


class room:public Node
{
public:
room():Node()
{
  this->room_code=" ";
  this->floor=0;
}


room(string code,int floor,string name,int num):Node(name,true,num)
{
this->room_code= code;
this->floor= floor;
}

room(room& roomcopy):Node(roomcopy)
{
  this->room_code= roomcopy.room_code;
  this->floor=roomcopy.floor;
}

virtual ~room()
{

}

virtual void display()
{
  cout<<*this;
}

virtual istream& fileInput(std::istream& is)
{
 is >>name>>is_allowed>>num>>room_code>>floor;
    return is;
}

friend ostream& operator <<(ostream& out, room r1)
{
  return out<<r1.name<<" "<<r1.num<<" "<<r1.is_allowed<<" "<<r1.room_code<<" "<<r1.floor<<endl;
}

friend std::istream& operator >> (std::istream & is, room  *s)
{
    is >> s->name>>s->is_allowed>>s->num >> s->room_code >> s->floor;
    return is;
} 




protected:
string room_code;
int floor;

};