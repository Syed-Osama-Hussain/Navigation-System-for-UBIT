#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Node{
public:
      Node()
      {
        this->g_value= 0;
        this->h_value = 0;
        this->f_value=0;
        //this->is_allowed= true;
        this->x= 0;
        this->y= 0;
        //this->val=1;
      }

      Node(int g_v, int h_v, int f_v, int xx, int yy)
      {
        this->g_value= g_v;
        this->h_value= h_v;
        this->f_value= f_v;
        //this->is_allowed= is_a;
        this->x =xx;
        this->y= yy;
      }

      Node(Node& n)
      {
        this->g_value= n.g_value;
        this->h_value= n.h_value;
        this->f_value= n.f_value;
        //this->is_allowed= n.is_allowed;
        this->x= n.x;
        this->y= n.y;
      }


      void seth_value()
      {
        this->h_value= sqrt(pow(this->val,2)+pow(this->val,2));
      }

      void set_gvalue()
      {
        this->g_value= this->x+this->y;
      }


      void set_fvalue()
      {
        this->f_value= this->g_value+this->h_value;
      }


private:
int h_value;
int g_value;
//bool is_allowed;
int f_value;
int x;
int y;
int val;

};
