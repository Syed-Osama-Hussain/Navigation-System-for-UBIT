#include <iostream>
#include "node.h"
using namespace std;

#ifndef stairs_h
#define stairs_h

class stairs:public Node
{
public:

stairs():Node()
{

}

stairs(string name,bool is_allowed,int num,int floor):Node(name,is_allowed,num,floor)
{

}

stairs(stairs& s):Node(s)
{

}

~stairs()
{

}

virtual void display()
{
  cout<<*this;
}

virtual istream& fileInput(std::istream& is)
{
 is >>name>>is_allowed>>num>>floor;
    return is;
}

friend ostream& operator <<(ostream& out, stairs r1)
{
  return out<<r1.name<<" "<<r1.is_allowed<<" "<<r1.num<<" "<<r1.floor<<endl;
}

friend std::istream& operator >> (std::istream & is, stairs *s)
{
    is >> s->name>>s->is_allowed>>s->num>>s->floor;
    return is;
} 




private:

};
#endif
