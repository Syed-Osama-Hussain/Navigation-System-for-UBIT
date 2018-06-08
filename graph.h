#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

int n=0;
class graph{
public:

graph()
{
  //this->no_of_vertices= 0;
  this->count=0;
  this->init=6;
  this->adjmatrix= new int*[this->init];
  for(int i=0;i<this->init;i++)
  {
    this->adjmatrix[i]= new int[this->init];
  }

  for(int i=0;i<this->init;i++)
  {
    for(int j=0;j<this->init;j++)
    {
      this->adjmatrix[i][j]= -1;
    }
  } 
  
}


/*~graph()
{
    
  for(int i=0;i<=this->init;i++)
  {
    delete[] adjmatrix[i];
  }
delete[] adjmatrix;
  
}*/


void add_element(int element)
{
  if(init==count)
  {
   increasesize();
  }
   
   this->vertices.push_back(element);
   this->count++;
  // this->no_of_vertices++;
  
}


void add_neighbour(int element,int neighbour,int weight)
{
  this->adjmatrix[element][neighbour]= weight;
}


void display()
{   
   for(std::vector<int>::iterator i=this->vertices.begin();i!=this->vertices.end();i++)
   {
     cout<<"The vertex "<< *i <<" has the neighbours: ";
     for(int j=0;j<=this->count;j++)
     {
       if(this->adjmatrix[*i][j]>=0)
       {
         //cout<<this->adjmatrix[*i][j]<<" ";
         cout<<j<<" with weight "<<this->adjmatrix[*i][j]<<"   ";
       }
       
     }
     
     cout<<endl;
   } 

}

void increasesize()
{
  bool **temp= nullptr;
  this->init*=2;
  temp= new bool*[this->init];
 
  for(int i=0;i<=this->init;i++)
  {
    temp[i]= new bool[this->init];
  }
  for(int i=0;i<this->count;i++)
  {
    for(int j=0;j<this->count;j++)
    {
      temp[i][j]= adjmatrix[i][j];
    }
    
  }
  for(int j=0;j<this->count;j++)
  {
     delete[] adjmatrix[j];
  }
  delete[] adjmatrix;

  //adjmatrix=temp;
 /* for(int i=this->count-1;i<=this->init;i++)
  {
    for(int j=0;j<=this->init;j++)
    {
      this->adjmatrix[i][j]=false;
    }
  }*/

}

int getcount()
{
  return this->count;
}

int getadjmatrix(int index1,int index2)
{
  return this->adjmatrix[index1][index2];
}




private:
std::vector <int> vertices;
std::vector <int> neighbors;
int **adjmatrix;
int count;
int init;
};