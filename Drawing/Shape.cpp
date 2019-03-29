#include "Shape.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
/* Constructor Function
	Purpose: to initialze the Circle
	Inputs:
	cF = fill color of the circle
	cO = outline color of the circle
	l = upper right position of the circle
	Outputs: N/A
*/
Circle::Circle(int cF,int cO, Vector2f l)
{
	cs.setRadius(SIZE);
	cs.setOutlineThickness(SIZE/10);
	cs.setFillColor(Color(cF));
	cs.setOutlineColor(Color(cO));
	cs.setPosition(l);
}

/* Constructor Function
	Purpose: to initialze the Square
	Inputs:
	cF = fill color of the square
	cO = outline color of the square
	l = upper right position of the square
	Outputs: N/A
*/
Square::Square(int cF, int cO, Vector2f l)
{
	rs.setSize(Vector2f(2*SIZE, 2*SIZE));
	rs.setOutlineThickness(SIZE/10);
	rs.setFillColor(Color(cF));
	rs.setOutlineColor(Color(cO));
	rs.setPosition(l);
}

/* draw Function
	Purpose: to draw the circle shape
	Inputs:
	w = the drawing window
	Outputs: N/A
*/
void Circle::draw(RenderWindow& w)
{
	w.draw(cs);
}

/* draw Function
	Purpose: to draw the square shape
	Inputs:
	w = the drawing window
	Outputs: N/A
*/
void Square::draw(RenderWindow& w)
{
	w.draw(rs);
}

/* returnData Function
	Purpose: to return the circle data
	Inputs: N/A
	Outputs:
	shape = the shape data of the circle
*/
ShapeData Circle::returnData()
{
	ShapeData shape;
	shape.isRectangle = false;
	shape.colorF = (cs.getFillColor().toInteger());
	shape.colorO = (cs.getOutlineColor().toInteger());
	shape.location = cs.getPosition();
	return shape;
}

/* returnData Function
	Purpose: to return the square data
	Inputs: N/A
	Outputs:
	shape = the shape data of the square
*/
ShapeData Square::returnData()
{
	ShapeData shape;
	shape.isRectangle = true;
	shape.colorF = (rs.getFillColor().toInteger());
	shape.colorO = (rs.getOutlineColor().toInteger());
	shape.location = rs.getPosition();
	return shape;
}