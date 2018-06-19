#include <iostream>
#include "room.cpp"
using namespace std;

#ifndef specialroom_h
#define specialroom_h

class Specialroom:public room
{
public:
Specialroom();

Specialroom(string purpose,string code,int floor,string name,int num);

Specialroom(Specialroom& spcopy);

virtual ~Specialroom();

virtual string get_purpose();

virtual void display();

virtual istream& fileInput(std::istream& is);

friend ostream& operator <<(ostream& out, Specialroom& r1);

friend std::istream& operator >> (std::istream & is, Specialroom  *s);

private:
string purpose;
};
#endif