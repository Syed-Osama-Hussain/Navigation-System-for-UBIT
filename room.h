#include <iostream>
#include "node.cpp"
using namespace std;

#ifndef room_h
#define room_h

class room:public Node
{
public:
room();

room(string code,int floor,string name,int num);

room(room& roomcopy);

virtual ~room();

string getroom_code();

virtual string getTeacher_name();

virtual string get_purpose();

virtual void display();

virtual istream& fileInput(std::istream& is);

friend ostream& operator <<(ostream& out, room& r1);

friend std::istream& operator >> (std::istream & is, room  *s);


protected:
string room_code;

};

#endif