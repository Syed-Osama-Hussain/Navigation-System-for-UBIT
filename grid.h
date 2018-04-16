#include <iostream>
#include <string>
#include "node.h"
using namespace std;

class grid{
public:
grid()
{
  this->rows=25;
  this->cols=25;
 // this->map= new Node[this->cols];
  for(int i=0;i<=this->cols;i++)
{
  for(int j=0;j<=this->rows;j++)
  {
    this->*map[0][0]= new Node;
  }
}
  
}


void visited(Node vs)
{

}


private:
Node *map;
int rows;
int cols;
Node *path;
Node start;
Node end;
Node current_node;
Node visited_node[100];
Node neighbour_node[8];


};