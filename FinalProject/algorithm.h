#include <iostream>
#include <string>
#include "graph.h"
#include "path.h"

using namespace std;

#ifndef algorithm_h
#define algorithm_h


class dijkstra{
public:


~dijkstra();

static dijkstra* getinstance();

void userinput(string source, string destination);

void makegraph();

void dijkstra_search (int source,int target);

int findMinVertex();

bool check_neighbors(int target,int j);

void display_path(int tar);



private:
static dijkstra *algo;
static bool instanceFlag;
int *distance=nullptr;
bool *visited= nullptr;
int *path= nullptr;
graph *g1;
Path p;


dijkstra();

};
#endif
