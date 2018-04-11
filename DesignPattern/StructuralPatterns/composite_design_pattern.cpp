/*
------------------ Composite Design Pattern | Structural Patterns ------------------

Use composite design pattern where you need to implement a tree structure object representing a part-whole hierarchy. 

Composite design pattern makes it simple to implement the tree structure by using a interface so that client can treat
all the objects uniformly.
*/


#include <iostream>
#include <list>


class Graphic
{
public:
    virtual void draw() = 0;
};

class Ellipse : public Graphic
{
public:
    void draw(){
        std::cout << "Ellipse" << std::endl;
    }
};

class Circle : public Graphic
{
public:
    void draw(){
        std::cout << "Circle" << std::endl;
    }
};

class CompositeGraphic : public Graphic
{
private:
    std::list<Graphic *> child_graphic;

public:
    void draw()
    {
        for(std::list<Graphic *>::iterator  graphic = child_graphic.begin();  graphic != child_graphic.end(); ++graphic){
            (*graphic)->draw();
        }
    }

    void add(Graphic *graphic)
    {
        child_graphic.push_back(graphic);
    }

    void remove(Graphic *graphic)
    {
		child_graphic.remove(graphic);
    }
};

int main()
{
	Ellipse *ellipse1 = new Ellipse();
	Ellipse *ellipse2 = new Ellipse();

	Circle *circle1 = new Circle();
	Circle *circle2 = new Circle();

	CompositeGraphic *graphic = new CompositeGraphic();
	CompositeGraphic *graphic1 = new CompositeGraphic();
	CompositeGraphic *graphic2 = new CompositeGraphic();

	graphic->add(ellipse1);
	graphic->add(graphic1);

	graphic1->add(circle1);
	graphic1->add(graphic2);
	graphic1->add(ellipse2);

	graphic2->add(circle2);

	graphic->draw();

    return 0;
}