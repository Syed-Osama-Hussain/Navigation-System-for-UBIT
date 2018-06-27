#include <iostream>
#include "neighbors.h"
#include "stairs.h"
#include "classroom.h"
#include "teachersroom.h"
#include "specialroom.h"
#include <fstream>
using namespace std;

#ifndef graph_h
#define graph_h
const int len=200;


class graph{

public:


static graph* getInstance();

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
Node *vertices[len];
int **adjmatrix;
int count;
int init;
static bool InstanceFlag;
static graph *grp;

 graph();
void increasesize();

};

#endif
