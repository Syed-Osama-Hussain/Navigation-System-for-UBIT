#include <iostream>
#include <string>
#include "graph.cpp"
using namespace std;

#ifndef algorithm_h
#define algorithm_h

class dijkstra{
public:


dijkstra();

~dijkstra();

void userinput();

void makegraph();

void dijkstra_search (string source,string target);

int findMinVertex();

bool check_neighbors(int target,int j);

void display_path(int tar);


private:
int *distance;
bool *visited;
int *path;
graph g1;
};
#endif