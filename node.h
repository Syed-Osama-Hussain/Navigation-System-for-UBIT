#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

#ifndef node_h
#define node_h


class Node{
public:
Node();

Node(string name, int value,int floor);

Node(Node& n);

virtual ~Node();

virtual string getroom_code();

virtual string getTeacher_name();

virtual string get_purpose();

Node& operator=(Node& n);

string getname();

int getfloor();

int getnum();

bool getIs_allowed();

virtual void display();

virtual istream& fileInput(std::istream& is);      

friend ostream& operator<<(ostream& out, Node &N);

friend std::istream& operator >> (std::istream & is, Node  *s);
   

protected:
string name;
int num;
int floor;

};
#endif