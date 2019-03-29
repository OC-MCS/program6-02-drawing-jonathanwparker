#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
const int SIZE = 25;
const unsigned int RED = Color::Red.toInteger(), GREEN = Color::Green.toInteger(), BLUE = Color::Blue.toInteger(),WHITE = Color::White.toInteger(), TRANSPARENT = Color::Transparent.toInteger();
/* ShapeData Structure
colorF = holds the fill color of the shape
colorO = holds the outline color of the shape
isRectangle = bool to check if the shape is a rectangle or not
location = the upper right position of the shape
*/
struct ShapeData
{
	unsigned int colorF;
	unsigned int colorO;
	bool isRectangle;
	Vector2f location;
};
/* Drawing Shape Class
Public Functions:
draw(RenderWindow) = a pure virtual function meant to hold the position of a square or circle
returnData() = a pure virtual function meant to hold the position of a square or circle
*/
class DrawingShape 
{
public:
	virtual void draw(RenderWindow&) = 0;
	virtual ShapeData returnData() = 0;
};

/* Circle Class
Private Data:
cs = circle shape that holds the data to be drawn in the window
Public Functions:
draw(RenderWindow&) = draws the circle shape
returnData() = returns the data in the form of the ShapeData structure
*/
class Circle : public DrawingShape
{
private:
	CircleShape cs;
public:
	Circle(int,int, Vector2f);
	void draw(RenderWindow&);
	ShapeData returnData();
};

/* Square Class
Private Data:
rs = rectangle shape that holds the data to be drawn in the window
Public Functions:
draw(RenderWindow&) = draws the square shape
returnData() = returns the data in the form of the ShapeData structure
*/
class Square : public DrawingShape
{
private:
	RectangleShape rs;
public:
	Square(int,int, Vector2f);
	void draw(RenderWindow&);
	ShapeData returnData();
};