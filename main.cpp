////////Torsha Mazumdar - TM//////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//TM - this is the component interface that declares the common operation for both leaf and composite objects
class Component
{
  public:
        virtual void play()=0;
};

//TM - leaf object 1 doing the actual work
class LegoBrick1X1 : public Component
{
  string color;
  public:
    LegoBrick1X1(string val)
    {
        color = val;
    }
    void play()
    {
        cout << "A " << color << " Lego 1X1 brick" << endl;
    }
    
};

//TM - leaf object 2 doing the actual work
class LegoBrick1X2 : public Component
{
  string color;
  public:
    LegoBrick1X2(string val)
    {
        color = val;
    }
    void play()
    {
        cout << "A " << color << " Lego 1X2 brick" << endl;
    }
};

//TM - leaf object 3 doing the actual work
class LegoBrick2X2 : public Component
{
  string color;
  public:
    LegoBrick2X2(string val)
    {
        color = val;
    }
    void play()
    {
        cout << "A " << color << " Lego 2X2 brick" << endl;
    }
  
};

//TM - leaf object 4 doing the actual work
class LegoFigure : public Component
{
  string occupation;
  public:
    LegoFigure(string val)
    {
        occupation = val;
    }
    void play()
    {
        cout << "A " << occupation << " Lego figure." << endl;
    }
  };

//TM - composite object delegating the work to leaf objects
class LegoProduct : public Component
{
  //TM - vector that forms the tree structure with parent and child/leaf nodes
  vector < Component * > child_array;
  string name;
  public:
    LegoProduct(string val)
    {
      name = val;
    }
    void add(Component *e)
    {
      child_array.push_back(e);
    }
    void play()
    {
        cout << "A Lego " << name << " that contains: " << endl;
        for (int i = 0; i < child_array.size(); i++)
          child_array[i]->play();//TM - polymorphic function which makes a call to play() function of the desired object.
    }
};

int main()
{
  //TM - leaf objects
  LegoBrick1X1 brick1("red");
  LegoBrick1X2 brick2("yellow");
  LegoBrick2X2 brick3("blue");
  LegoBrick2X2 brick4("green");
  
  LegoFigure figure1("prince");
  LegoFigure figure2("princess");
  LegoFigure figure3("knight");
  
  //TM - composite object
  LegoProduct product1("castle");
  LegoProduct product2("kingdom");
  
  //TM - adding leaf nodes(building blocks) of castle to child_array
  product1.add(&brick1);
  product1.add(&brick2);
  product1.add(&brick3);
  product1.add(&brick4);
  
  //TM - adding leaf nodes to child_array - these nodes do not have a parent or child node. they belong to the final product kingdom itself
  product2.add(&figure1);
  product2.add(&figure2);
  product2.add(&figure3);

  //TM - adding castle to the kingdom
  product2.add(&product1);
  product2.play();
  
  return 0;
}
