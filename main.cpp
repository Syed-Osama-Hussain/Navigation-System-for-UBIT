#include <iostream>
#include <string>
#include "algorithm.cpp"
using namespace std;


int main()
{
  dijkstra *d1;
  d1= dijkstra::getinstance();
  delete d1;
  system("pause");
}