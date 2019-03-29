#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"


/* DrawingUI Class
Private Data:
drawingWindow = the shape containing the data of the drawing area
Public Functions:
drawingUI(Vector2f,const int,const int) = constructor to set the size of the drawing area
draw(RenderWindow&,ShapeMgr*) = function to draw both the drawing area and the shapes
isMouseInCanvas(Vector2f) = function to check if the mouse is inside the drawing area
*/
class DrawingUI
{
private:
	RectangleShape drawingWindow;

public:
	/* Constructor Function
	Purpose: to set the size of the drawing area
	Inputs:
	p = the position of the drawing area
	w = the width of the drawing window
	h = the height of the drawing window
	Outputs: N/A
	*/
	DrawingUI(Vector2f p,const int w,const int h)
	{
		drawingWindow.setPosition(p);
		drawingWindow.setSize(Vector2f(w-1.5*p.x,h-2*p.y));
		drawingWindow.setFillColor(Color::Transparent);
		drawingWindow.setOutlineColor(Color::White);
		drawingWindow.setOutlineThickness(SIZE/10);
	}

	/* draw Function
	Purpose: to draw both the drawing area and the shapes
	Inputs:
	mouse =  the position of the mouse when it was clicked
	mgr = handles the vector containing all of the drawn shapes
	Outputs: N/A
	*/
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(drawingWindow);
		mgr->drawShapes(win);
		
	}
	
	/* isMouseInCanvas Function
	Purpose: to check if the mouse is inside the drawing area
	Inputs:
	mousePos =  the position of the mouse when it was clicked
	Outputs:
	temp = a yes or no bool that says wether or not the mouse is in the Drawing Area
	*/
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool temp = drawingWindow.getGlobalBounds().contains(mousePos);
		return temp;
	}

};

