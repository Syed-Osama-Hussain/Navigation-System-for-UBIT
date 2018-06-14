#include <iostream>
#include <vector>
#include "Node.h"
#include "neighbors.h"
#include "room.h"
#include "stairs.h"
#include <fstream>
using namespace std;

#ifndef graph_h
#define graph_h
int n=0;


class graph{
public:

graph()
{
  this->count=0;
  this->init=5;
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
   string type;
   ifstream fin;
   fin.open("nodedata.txt",ios::in);
   while(!fin.eof())
   {
     if(count==init)
     {
       increasesize();
     }
     fin>>type;
     if(type=="Node")
     {
      this->vertices[this->count]= new Node;
      this->vertices[this->count]->fileInput(fin);
     }
     
    if(type=="Room")
      {
      this->vertices[this->count]= new room;
      this->vertices[this->count]->fileInput(fin);
      }
     
     if(type=="Stairs")
     {
       this->vertices[this->count]= new stairs;
       this->vertices[this->count]->fileInput(fin);
     }
      

     
    this->vertices[this->count]->display();
    this->count++;
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
  for(int i=0;i<this->count;i++)
  {

    delete vertices[i];
    vertices[i]=nullptr;
  }
  for(int i=0;i<=this->init;i++)
  {
    delete[] adjmatrix[i];
   
  }
 adjmatrix=nullptr;
}


void add_element(Node& element)
{
  if(init==count)
  {
   increasesize();
  }
   
   this->vertices[this->count]=&element;
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
  if(this->vertices[i]->getname()==ch)
  {
    return vertices[i]->getnum();
  }
}  
}


string SearchByNum(int num)
{
  for(int i=0;i<=this->count;i++)
{
  if(this->vertices[i]->getnum()==num)
  {
    return this->vertices[i]->getname();
  }
}  
}

private:
Node *vertices[100];
int **adjmatrix;
int count;
int init;
};

#endif