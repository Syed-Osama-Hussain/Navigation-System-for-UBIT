#include <iostream>
#include "neighbors.cpp"
#include "stairs.cpp"
#include "classroom.cpp"
#include "teachersroom.cpp"
#include "specialroom.cpp"
#include <fstream>
using namespace std;

#ifndef graph_h
#define graph_h
int n=0;

class graph{

public:

graph();

void readNodeData(); 
 
void readNeighborData();

~graph();

void add_element(Node& element);

void add_neighbour(neighbors& n);

void display();

int getcount();

int getadjmatrix(int index1,int index2);

int SearchByName(string ch);

int SearchByCode(string ch);

int SearchByTeachername(string ch);

int SearchByPurpose(string ch);

string SearchByNum(int num);


private:
Node *vertices[200];
int **adjmatrix;
int count;
int init;


void increasesize();

};

#endif