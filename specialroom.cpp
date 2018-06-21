#include <iostream>
#include "specialroom.h"
using namespace std;

Specialroom::Specialroom():room()
{
this->purpose=" ";
}

Specialroom::Specialroom(string purpose,string code,int floor,string name,int num):room(code,floor,name,num)
{
  this->purpose=purpose;
}

Specialroom::Specialroom(Specialroom& spcopy):room(spcopy)
{
  this->purpose= spcopy.purpose;
}

Specialroom::~Specialroom()
{

}

string Specialroom::get_purpose()
{
  return this->purpose;
}

void Specialroom::display()
{
  cout<<*this;
}

istream& Specialroom::fileInput(std::istream& is)
{
 is >>name>>num>>room_code>>floor>>purpose;
    return is;
}

ostream& operator <<(ostream& out, Specialroom& r1)
{
  return out<<r1.name<<" "<<r1.num<<" "<<r1.room_code<<" "<<r1.floor<<" "<<r1.purpose<<endl;
}

std::istream& operator >> (std::istream & is, Specialroom  *s)
{
    is >> s->name>>s->num>>s->floor>>s->room_code>>s->purpose;
    return is;
}