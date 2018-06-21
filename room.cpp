#include <iostream>
#include "room.h"
using namespace std;

#ifndef room_cpp
#define room_cpp


room::room():Node()
{
  this->room_code=" ";
}


room::room(string code,int floor,string name,int num):Node(name,num,floor)
{
this->room_code= code;
}

room::room(room& roomcopy):Node(roomcopy)
{
  this->room_code= roomcopy.room_code;
}

room::~room()
{

}

string room::getroom_code()
{
  return this->room_code;
}

string room::getTeacher_name()
{

}

string room::get_purpose()
{
  
}

void room::display()
{
  cout<<*this;
}

istream& room::fileInput(std::istream& is)
{
 is >>name>>num>>room_code>>floor;
    return is;
}

ostream& operator <<(ostream& out, room& r1)
{
  return out<<r1.name<<" "<<r1.num<<" "<<r1.room_code<<" "<<r1.floor<<endl;
}

std::istream& operator >> (std::istream & is, room  *s)
{
    is >> s->name>>s->num>>s->floor>>s->room_code;
    return is;
} 

#endif