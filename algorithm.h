#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

#ifndef algorithm_h
#define algorithm_h

class dijkstra{
public:


dijkstra()
{
  
 
  makegraph();
  this->path= new int[this->g1.getcount()+1];
  this->distance= new int[this->g1.getcount()];
  this->visited= new bool[this->g1.getcount()];

}

~dijkstra()
{
 delete[] path;
 delete[] distance;
 delete[] visited;
 path= nullptr;
 distance= nullptr;
 visited= nullptr;
}

void makegraph()
{
  g1.readNodeData();
  g1.readNeighborData();
}

void dijkstra_search (string source,string target)
{
  int src;
  int tar;
  src=g1.SearchByName(source);
  tar=g1.SearchByName(target);
  n=0;

for(int i=0;i<this->g1.getcount();i++)
{
  this->distance[i]=WINT_MAX;
  this->visited[i]= false;
}
distance[src]=0;

for(int i=0;i<this->g1.getcount()-1;i++)
{
  
  int min_vertex= findMinVertex();
  if(min_vertex==tar)
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
        this->path[j]=min_vertex;
        distance[j]= dist;
      }
      
    }
  }
}
this->path[n]=tar;
display_path(tar);
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
cout<<"\nThe path to the destination is ";
    
    int i= 0;
     do{
       if(path[i]>=0)
       {
       i=path[i];
      string temp;
      temp=g1.SearchByNum(i);
    cout<<temp<<"<-";
       }

       else
       {
         break;
       }
     }while(i!=0);
  

  cout<<" with total distance of "<<distance[tar]<<" units.\n"<<endl;
}


private:
int *distance;
bool *visited;
int *path;
graph g1;
};
#endif