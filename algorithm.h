#include <iostream>
#include <string>
#include "graph.cpp"
using namespace std;

#ifndef algorithm_h
#define algorithm_h

class dijkstra{
public:

~dijkstra();

static dijkstra* getinstance();

void userinput();

void makegraph();

void dijkstra_search (int source,int target);

int findMinVertex();

bool check_neighbors(int target,int j);

void display_path(int tar);



private:
static bool instanceFlag;
static dijkstra *algo;
int *distance;
bool *visited;
int *path;
graph *g1;

dijkstra();
};
#endif