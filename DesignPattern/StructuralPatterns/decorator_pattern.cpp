/*
----------------- Decorator Design Pattern | Structural Patterns ---------------------

Decorator Design Pattern can be used to solve these problems,
- To add or remove responsibilities to an object dynamically at run-time.
- A flexible alternative to subclassing for extending functionality should be provided.

*/


#include <iostream>


class VisualComponent
{
public:
	virtual void display() = 0;
};

class TextViewer : public VisualComponent
{
public:
	void display(){
		std::cout << "Display texts." << std::endl;
	}
};

class ImageViewer : public VisualComponent
{
public:
	void display(){
		std::cout << "Display image." << std::endl;
	}
};

class Decorator : public VisualComponent
{
protected:
	VisualComponent *visual_component;

public:
	Decorator(VisualComponent *vc){
		visual_component = vc;
	}

	void display(){
		visual_component->display();
	}
};

class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(VisualComponent *vc) : Decorator(vc) { }
	
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
	BorderDecorator(VisualComponent *vc) : Decorator(vc) { }

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
	VisualComponent *text_viewer = new TextViewer();
	text_viewer->display();

	std::cout << "\n------- Text viewer with the Scrollbar --------" << std::endl;
	VisualComponent *text_viewer_with_scroll = new ScrollDecorator(text_viewer);
	text_viewer_with_scroll->display();

	std::cout << "\n------- Text viewer with Scrollbar and Border --------" << std::endl;
	VisualComponent *text_viewer_with_border = new BorderDecorator(text_viewer_with_scroll);
	text_viewer_with_border->display();


	std::cout << "\n------- Only Image viewer --------" << std::endl;
	VisualComponent *image_viewer = new ImageViewer();
	image_viewer->display();

	std::cout << "\n------- Image viewer with the Border --------" << std::endl;
	VisualComponent *image_viewer_with_border = new BorderDecorator(image_viewer);
	image_viewer_with_border->display();

	return 0;
}
