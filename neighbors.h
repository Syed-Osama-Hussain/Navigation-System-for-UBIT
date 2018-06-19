#include <iostream>
using namespace std;

#ifndef neighbors_h
#define neighbors_h

class neighbors{
public:

neighbors();

neighbors(int sn,int w,int dn);

neighbors(neighbors& n);

int getSource();

int  getDest();

int getweight();

friend ostream& operator <<(ostream& o,neighbors& n);

friend std::istream& operator >> (std::istream & is, neighbors & s);

private:
int sourceNum;
int weight;
int destNum;
};
#endif