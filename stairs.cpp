#include <iostream>
#include "stairs.h"
using namespace std;

stairs::stairs():Node()
{

}

stairs::stairs(string name,bool is_allowed,int num,int floor):Node(name,is_allowed,num,floor)
{

}

stairs::stairs(stairs& s):Node(s)
{

}

stairs::~stairs()
{

}

void stairs::display()
{
  cout<<*this;
}

istream& stairs::fileInput(std::istream& is)
{
 is >>name>>is_allowed>>num>>floor;
    return is;
}

ostream& operator <<(ostream& out, stairs& r1)
{
  return out<<r1.name<<" "<<r1.is_allowed<<" "<<r1.num<<" "<<r1.floor<<endl;
}

std::istream& operator >> (std::istream & is, stairs *s)
{
    is >> s->name>>s->is_allowed>>s->num>>s->floor;
    return is;
}