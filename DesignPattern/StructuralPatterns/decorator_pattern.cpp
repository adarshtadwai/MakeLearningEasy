/*
----------------- Decorator Design Pattern | Structural Patterns ---------------------

Decorator Design Pattern can be used to solve these problems,
- To add or remove responsibilities to an object dynamically at run-time.
- A flexible alternative to subclassing for extending functionality should be provided.

*/


#include <iostream>


class Viewer
{
public:
	virtual void display() = 0;
};

class TextViewer : public Viewer
{
public:
	void display(){
		std::cout << "Display texts." << std::endl;
	}
};

class ImageViewer : public Viewer
{
public:
	void display(){
		std::cout << "Display image." << std::endl;
	}
};

class Decorator : public Viewer
{
protected:
	Viewer *viewer;

public:
	Decorator(Viewer *vr){
		viewer = vr;
	}

	void display(){
		viewer->display();
	}
};

class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(Viewer *vc) : Decorator(vc) { }

	void display(){
		Decorator::display();
		addScrollBar();
	}

	void addScrollBar(){
		std::cout << "Added Scrollbar with the Viewer." << std::endl;
	}
};

class BorderDecorator : public Decorator
{
public:
	BorderDecorator(Viewer *vc) : Decorator(vc) { }

	void display(){
		Decorator::display();
		addBorder();
	}

	void addBorder() {
		std::cout << "Added Border with the Viewer." << std::endl;
	}
};

int main()
{
	std::cout << "\n------- Only text viewer --------" << std::endl;
	Viewer *text_viewer = new TextViewer();
	text_viewer->display();

	std::cout << "\n------- Text viewer with the Scrollbar --------" << std::endl;
	Viewer *text_viewer_with_scroll = new ScrollDecorator(text_viewer);
	text_viewer_with_scroll->display();

	std::cout << "\n------- Text viewer with Scrollbar and Border --------" << std::endl;
	Viewer *text_viewer_with_border = new BorderDecorator(text_viewer_with_scroll);
	text_viewer_with_border->display();


	std::cout << "\n------- Only Image viewer --------" << std::endl;
	Viewer *image_viewer = new ImageViewer();
	image_viewer->display();

	std::cout << "\n------- Image viewer with the Border --------" << std::endl;
	Viewer *image_viewer_with_border = new BorderDecorator(image_viewer);
	image_viewer_with_border->display();

	return 0;
}
