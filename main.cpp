#include <iostream>
#include <string>
<<<<<<< HEAD
#include "grid.h"
=======
#include "algorithm.h"
>>>>>>> Dijkstra algorithm on a simple graph.
using namespace std;


int main()
{
<<<<<<< HEAD
  grid G1;
  G1.display_map();
  system("pause");
  
=======
  int source;
  int destination;
  cout<<"\nEnter your loaction: ";
  cin>>source;
  cout<<"\nEnter the destination: ";
  cin>>destination;
  dijkstra d1;
  d1.dijkstra_search(source,destination);
  system("pause");
>>>>>>> Dijkstra algorithm on a simple graph.
}