#include <iostream>
#include "stairs.h"
using namespace std;

stairs::stairs():Node()
{

}

stairs::stairs(string name,int num,int floor):Node(name,num,floor)
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
 is >>name>>num>>floor;
    return is;
}

ostream& operator <<(ostream& out, stairs& r1)
{
  return out<<r1.name<<" "<<r1.num<<" "<<r1.floor<<endl;
}

std::istream& operator >> (std::istream & is, stairs *s)
{
    is >> s->name>>s->num>>s->floor;
    return is;
}