#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class Node{
public:
      Node()
      {
        this->num=0;
        this->is_allowed=false;
        this->name;
      }

      Node(int name, bool allowed, int value)
      {
        this->num= num;
        this->is_allowed= allowed;
        this->name= name;
        
      }



      Node(Node& n)
      {
        
       this->num= n.num;
       this->is_allowed= n.is_allowed;
       this->name= n.name;
      }


      ~Node()
      {
        
      }

      Node& operator=(Node& n)
      {
        this->num=n.num;
        this->name=n.name;
        this->is_allowed= n.is_allowed;
        return *this;
      }

string getname()
{
  return this->name;
}


int getnum()
{
  return this->num;
}


bool getIs_allowed()
{
  return this->is_allowed;
}


void display()
 {
    cout<<this->name<<" "<<this->is_allowed<<" "<<this->num<<endl;
 }
    

      

friend ostream& operator<<(ostream& out, Node& N)
{
  return out<<N.name<<" "<<N.is_allowed<<" "<<N.num<<endl;
}

friend std::istream& operator >> (std::istream & is, Node & s)
{
    is >> s.name >> s.is_allowed >> s.num;
    return is;
} 

   


private:
string name;
bool is_allowed;
int num;

};
