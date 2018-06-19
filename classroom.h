#include <iostream>
#include <fstream>
#include "room.cpp"
using namespace std;

#ifndef classroom_h
#define classroom_h

class classroom:public room
{
public:
classroom();

classroom(string code,int floor,string name,int num);


classroom(classroom& copyclass);

virtual ~classroom();

virtual void display();

virtual istream& fileInput(std::istream& is);

friend ostream& operator <<(ostream& out, classroom r1);

friend std::istream& operator >> (std::istream & is, classroom  *s);


private:
};

#endif