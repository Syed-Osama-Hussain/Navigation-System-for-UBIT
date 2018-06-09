#include <iostream>
#include <vector>
#include "Node.h"
#include "neighbors.h"
#include <fstream>
using namespace std;

int n=0;
class graph{
public:

graph()
{
  this->count=0;
  this->init=5;
  this->vertices= new Node[this->init];
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



void readNodeData()
 {
   Node n1;
   ifstream fin;
   fin.open("nodedata.txt",ios::in);
   for(int i=0;i<=this->init;i++)
   {
     if(fin.good())
     {
        if(init==count)
  {
   increasesize();
  }
     fin>>n1;
     this->vertices[i]= n1;
     this->count++;
     }

     else
     {
       break;
     }
   }
   fin.close();
}


void readNeighborData()
{
   neighbors nei;
   ifstream fin;
   fin.open("neighborsdata.txt",ios::in);
   
     while(fin.good())
     {
  
     fin>>nei;
     add_neighbour(nei);
     }

    
   fin.close();
}


~graph()
{
    delete[] vertices;
    vertices= nullptr;
  for(int i=0;i<=this->init;i++)
  {
    delete[] adjmatrix[i];
  }
//delete[] adjmatrix;
}


void add_element(Node& element)
{
  if(init==count)
  {
   increasesize();
  }
   
   this->vertices[this->count]=element;
   this->count++;
  
}


void add_neighbour(neighbors& n)
{
  this->adjmatrix[n.getSource()][n.getDest()]= n.getweight();
}


void display()
{   
   for(int i=0;i<this->count;i++)
   {
     cout<<"The vertex "<< i <<" has the neighbours: ";
     for(int j=0;j<=this->count;j++)
     {
       if(this->adjmatrix[i][j]>=0)
       {
         //cout<<this->adjmatrix[*i][j]<<" ";
         cout<<j<<" with weight "<<this->adjmatrix[i][j]<<"   ";
       }
       
     }
     
     cout<<endl;
   } 

}

void increasesize()
{
  int **temp= nullptr;
  this->init*=2;
  temp= new int*[this->init];
 
  for(int i=0;i<=this->init;i++)
  {
    temp[i]= new int[this->init];
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


  adjmatrix=temp;

   Node *tempv= new Node[this->init];
   for(int i=0;i<this->count;i++)
   {
     tempv[i]= this->vertices[i];
   }

   delete[] this->vertices;
   this->vertices= tempv;


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

int SearchByName(string ch)
{
  int flag=0;
for(int i=0;i<=this->count;i++)
{
  if(this->vertices[i].getname()==ch)
  {
    return this->vertices[i].getnum();
  }
}  
}


string SearchByNum(int num)
{
  for(int i=0;i<=this->count;i++)
{
  if(this->vertices[i].getnum()==num)
  {
    return this->vertices[i].getname();
  }
}  
}

private:
Node *vertices;
int **adjmatrix;
int count;
int init;
};