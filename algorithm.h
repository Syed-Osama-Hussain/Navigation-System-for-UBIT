#include <iostream>
#include <string>
#include "graph.h"
using namespace std;


class dijkstra{
public:


dijkstra()
{
  makegraph();
  this->path= new int[this->g1.getcount()];
  this->distance= new int[this->g1.getcount()];
  this->visited= new bool[this->g1.getcount()];

}


void makegraph()
{
  g1.add_element(0);
  g1.add_element(1);
  g1.add_element(2);
  g1.add_element(3);
  g1.add_element(4);
  g1.add_element(5);
  g1.add_neighbour(0,1,5);
  g1.add_neighbour(0,5,8);
  g1.add_neighbour(0,2,2);
  g1.add_neighbour(1,0,5);
  g1.add_neighbour(1,2,9);
  g1.add_neighbour(2,0,2);
  g1.add_neighbour(2,1,9);
  g1.add_neighbour(2,3,4);
  g1.add_neighbour(2,4,10);
  g1.add_neighbour(3,2,4);
  g1.add_neighbour(4,2,10);
  g1.add_neighbour(4,5,3);
  g1.add_neighbour(5,0,8);
  g1.add_neighbour(5,4,3);

}

void dijkstra_search (int src,int target)
{
  
  n=0;

for(int i=0;i<this->g1.getcount();i++)
{
  this->distance[i]=WINT_MAX;
  this->visited[i]= false;
}
distance[src]=0;

for(int i=0;i<this->g1.getcount();i++)
{
  
  int min_vertex= findMinVertex();
  if(min_vertex==target)
  {
    break;
  }
  visited[min_vertex]= true;
  for(int j=0;j<this->g1.getcount();j++)
  {
    if(check_neighbors(min_vertex,j) && !visited[j])
    {
      int dist= this->distance[min_vertex]+ this->g1.getadjmatrix(min_vertex,j);
      if(dist<distance[j])
      {
        distance[j]= dist;
      }
    }
    
  }
  

}

display_path(target);
//delete[] visited;
  //delete[] distance;

  //visited= nullptr;
  //distance= nullptr;
}


int findMinVertex()
{
  int min_vertex=-1;
  for(int i=0;i<this->g1.getcount();i++)
  {
    if(!visited[i]&&(min_vertex==-1 || this->distance[i]<this->distance[min_vertex]))
    {
      min_vertex=i;
    }
  }
  
  this->path[n]=min_vertex;
  n++;
  return min_vertex;
  
}


bool check_neighbors(int target,int j)
{

    if(this->g1.getadjmatrix(target,j)>0)
    {
      return 1;
    }
  else 
  {
    return 0;
  }

}

void display_path(int tar)
{

/*for(int i=0;i<this->count;i++)
{
  cout<<i<<" "<<this->distance[i]<<endl;
  
}*/
cout<<"\nThe path to the destination is: ";
for(int j=0;j<=tar;j++)
  {
    cout<<this->path[j]<<" ";
  }

  cout<<" with total distance of "<<distance[tar]<<" units."<<endl;

}



private:
int *distance;
bool *visited;
int *path;
graph g1;
};