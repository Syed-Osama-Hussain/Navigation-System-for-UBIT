#include <iostream>
#include "node.h"
using namespace std;

#ifndef stairs_h
#define stairs_h

class stairs:public Node
{
public:

stairs();

stairs(string name,int num,int floor);

stairs(stairs& s);

~stairs();

virtual void display();

virtual istream& fileInput(std::istream& is);

friend ostream& operator <<(ostream& out, stairs& r1);

friend std::istream& operator >> (std::istream & is, stairs *s);


private:

};
#endif