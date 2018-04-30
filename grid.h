#include <iostream>
#include <string>
#include "node.h"
using namespace std;

class grid{
public:
grid()
{
  this->rows=5;
  this->cols=5;
  this->map= new Node**[this->cols];
  for(int i=0;i<=this->cols;i++)
{
  this->map[i]= new Node*[this->rows];
  for(int j=0;j<=this->rows;j++)
  {
    this->map[i][j]= new Node();
  }
}
  
}


void visited(Node vs)
{

}

void display_map()
{
  for(int i=0; i<=this->cols;i++)
  {
    for(int j=0; j<=this->rows;j++)
    {
      cout<<*map[i][j]<<endl;
    }
  }
}


private:
Node ***map;
int rows;
int cols;
Node *path;
Node start;
Node end;
Node current_node;
Node visited_node[100];
Node neighbour_node[8];


};