#include <iostream>
#include "neighbors.h"
using namespace std;

#ifndef neighbors_cpp
#define neighbors_cpp

neighbors::neighbors()
{
  this->sourceNum=0;
  this->destNum=0;
  this->weight=0;
}

neighbors::neighbors(int sn,int w,int dn)
{
  this->sourceNum=sn;
  this->weight=w;
  this->destNum=dn;
}

neighbors::neighbors(neighbors& n)
{
  this->sourceNum=n.sourceNum;
  this->destNum=n.destNum;
  this->weight=n.weight;
}

int neighbors::getSource()
{
  return this->sourceNum;
}

int  neighbors::getDest()
{
  return this->destNum;
}

int neighbors::getweight()
{
 return this->weight;
}


ostream& operator <<(ostream& o,neighbors& n)
{
  return o<<n.sourceNum<<" "<<n.destNum<<" "<<n.weight<<"\n"<<endl;
}

std::istream& operator >> (std::istream & is,neighbors & s)
{
    return  is >> s.sourceNum >> s.destNum >> s.weight;
} 

#endif