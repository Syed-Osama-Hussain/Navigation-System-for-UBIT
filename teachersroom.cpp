#include <iostream>
#include "teachersroom.h"
using namespace std;

TeacherRoom::TeacherRoom():room()
{
  this->teacher_name=" ";
}

TeacherRoom::TeacherRoom(string TN,string code,int floor,int num,string name):room(code,floor,name,num)
{
this->teacher_name= TN;
}

TeacherRoom::TeacherRoom(TeacherRoom& TRcopy):room(TRcopy)
{
  this->teacher_name= TRcopy.teacher_name;
}

TeacherRoom::~TeacherRoom()
{

}

string TeacherRoom::getTeacher_name()
{
  return this->teacher_name;
}

void TeacherRoom::display()
{
  cout<<*this;
}

istream& TeacherRoom::fileInput(std::istream& is)
{
 is >>name>>num>>room_code>>floor>>teacher_name;
    return is;
}

ostream& operator <<(ostream& out, TeacherRoom& r1)
{
  return out<<r1.name<<" "<<r1.num<<" "<<r1.room_code<<" "<<r1.floor<<" "<<r1.teacher_name<<endl;
}

std::istream& operator >> (std::istream & is, TeacherRoom  *s)
{
    is >> s->name>>s->num>>s->floor>>s->room_code>>s->teacher_name;
    return is;
} 