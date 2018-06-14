#include <iostream>
using namespace std;

#ifndef neighbors_h
#define neighbors_h

class neighbors{
public:

neighbors()
{
  this->sourceNum=0;
  this->destNum=0;
  this->weight=0;
}

neighbors(int sn,int w,int dn)
{
  this->sourceNum=sn;
  this->weight=w;
  this->destNum=dn;
}

neighbors(neighbors& n)
{
  this->sourceNum=n.sourceNum;
  this->destNum=n.destNum;
  this->weight=n.weight;
}

int getSource()
{
  return this->sourceNum;
}

int  getDest()
{
  return this->destNum;
}

int getweight()
{
 return this->weight;
}


friend ostream& operator <<(ostream& o,neighbors& n)
{
  return o<<n.sourceNum<<" "<<n.destNum<<" "<<n.weight<<"\n"<<endl;
}

friend std::istream& operator >> (std::istream & is, neighbors & s)
{
    is >> s.sourceNum >> s.destNum >> s.weight;
    return is;
} 

private:
int sourceNum;
int weight;
int destNum;
};
#endif