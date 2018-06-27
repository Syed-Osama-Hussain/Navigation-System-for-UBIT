#include <iostream>
#include "room.h"
using namespace std;

#ifndef teachersroom_h
#define teachersroom_h

class TeacherRoom:public room
{
public:
TeacherRoom();

TeacherRoom(string TN,string code,int floor,int num,string name);

TeacherRoom(TeacherRoom& TRcopy);

virtual ~TeacherRoom();

string getTeacher_name();

void display();

virtual istream& fileInput(std::istream& is);

friend ostream& operator <<(ostream& out, TeacherRoom& r1);

friend std::istream& operator >> (std::istream & is, TeacherRoom  *s);

private:
string teacher_name;
};

#endif
