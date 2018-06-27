#include <iostream>
#include "graph.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
using namespace std;
#ifndef graph_cpp
#define graph_cpp


graph* graph::grp=nullptr;
bool graph::InstanceFlag=false;

graph::graph()
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


graph* graph::getInstance()
{
    if(!InstanceFlag)
    {
      graph::grp= new graph();
      graph::InstanceFlag=true;
      return graph::grp;
    }
    else
    {
      return graph::grp;
    }
}




graph::~graph()
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



int graph::getcount()
{
  return this->count;
}


int graph::getadjmatrix(int index1,int index2)
{
  return this->adjmatrix[index1][index2];
}


void graph::readNodeData()
 {
   string type;
   ifstream fin;
   fin.open("E:\\OOP\\Final project\\Navigation System for UBIT\\nodedata.txt",ios::in);
   if(fin.is_open())
   {
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

     if(type=="Classroom")
     {
       this->vertices[this->count]= new classroom;
       this->vertices[this->count]->fileInput(fin);
     }

     if(type=="TeacherRoom")
     {
       this->vertices[this->count]= new TeacherRoom;
       this->vertices[this->count]->fileInput(fin);
     }

      if(type=="Specialroom")
     {
       this->vertices[this->count]= new Specialroom;
       this->vertices[this->count]->fileInput(fin);
     }
    //this->vertices[this->count]->display();
    this->count++;
   }
   }

   fin.close();
}


void graph::readNeighborData()
{
   neighbors nei;
   ifstream fin;
   fin.open("E:\\OOP\\Final project\\Navigation System for UBIT\\neighborsdata.txt",ios::in);

     while(fin.good())
     {
      fin>>nei;
     add_neighbour(nei);
     }


   fin.close();
}



void graph::add_element(Node& element)
{
  if(init==count)
  {
   increasesize();
  }

   this->vertices[this->count]=&element;
   this->count++;

}


void graph::add_neighbour(neighbors& n)
{
  this->adjmatrix[n.getSource()][n.getDest()]= n.getweight();
}


int graph::SearchByName(string ch)
{
  int flag=0;
  int i;
for(i=0;i<this->count;i++)
{
  if(this->vertices[i]->getname()==ch)
  {
    flag++;
    break;
  }
}

if(flag>0)
{
     return vertices[i]->getnum();
}
else
  {
   i=SearchByTeachername(ch);
   return i;
  }
}


int graph::SearchByTeachername(string ch)
{
  int flag=0;
  int k;
for(k=0;k<this->count;k++)
{
  if(this->vertices[k]->getTeacher_name()==ch)
  {
    flag++;
    break;
  }
}

if(flag>0)
{
     return vertices[k]->getnum();
}
else
  {
    k=SearchByCode(ch);
    return k;
  }

}


int graph::SearchByCode(string ch)
{
  int flag=0;
  int i;
for(i=0;i<this->count;i++)
{
  if(this->vertices[i]->getroom_code()==ch)
  {
    flag++;
    break;
  }
}

if(flag>0)
{
     return vertices[i]->getnum();
}
else
  {
  i= SearchByPurpose(ch);
  return i;
  }
}


int graph::SearchByPurpose(string ch)
{
 int flag=0;
  int j;
for(j=0;j<this->count;j++)
{
  if(this->vertices[j]->get_purpose()==ch)
  {
    flag++;
    break;
    cout<<"\nCorrect\n";
  }
}

if(flag>0)
{
     return vertices[j]->getnum();
}
else
  {
   try{
      if(flag<=0)
    throw -1;
    }
    catch(...)
    {
        MainWindow p;
        QMessageBox::warning(&p, "Error","No such node found in the map",
                             QMessageBox::Ok);
    }

 exit(-1);
  }
}



string graph::SearchByNum(int num)
{
  for(int i=0;i<=this->count;i++)
{
  if(num>0)
  {
      if(this->vertices[i]->getnum()==num && this->vertices[i]->get_purpose() != " ")
  {
    return this->vertices[i]->get_purpose();
  }

  if(this->vertices[i]->getnum()==num && this->vertices[i]->getroom_code() != " ")
  {
    return this->vertices[i]->getroom_code();
  }
  }
  if(this->vertices[i]->getnum()==num && this->vertices[i]->getname() != " ")
  {
      return this->vertices[i]->getname();
  }
}
  return 0;
}


void graph::display()
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


void graph::increasesize()
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
  adjmatrix=temp;
}
#endif
