#include <iostream>
#include <string>
#include "algorithm.cpp"
using namespace std;


int main()
{ string source;
  string destination;
  cout<<"\nEnter your loaction: ";
  cin>>source;
  cout<<"\nEnter the destination: ";
  cin>>destination;
  dijkstra d1;
  d1.dijkstra_search(source,destination);
  system("pause");
}