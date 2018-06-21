#include <iostream>
#include "classroom.h"
using namespace std;

classroom::classroom():room()
{
}

classroom::classroom(string code,int floor,string name,int num):room(code,floor,name,num)
{
}


classroom::classroom(classroom& copyclass):room(copyclass)
{
}

classroom::~classroom()
{

}

void classroom::display()
{
  cout<<*this;
}

istream& classroom::fileInput(std::istream& is)
{
 is >>name>>num>>room_code>>floor;
    return is;
}

ostream& operator <<(ostream& out, classroom r1)
{
  return out<<r1.name<<" "<<r1.num<<" "<<r1.room_code<<" "<<r1.floor<<endl;
}

std::istream& operator >> (std::istream & is, classroom  *s)
{
    is >> s->name>>s->num>>s->floor>>s->room_code;
    return is;
} 