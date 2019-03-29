#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include "Shape.h"
#include "ShapeMgr.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.
/* ShapeMgr Class
Private Data:
shapeMgr vector = Vector to hold all of the shapes drawn on the window
Public Functions:
ShapeMgr() = default constructor for compile
addShape(Vector2f,ShapeEnum,Color,Vector2f,int,int) = adds a shape to the vector
drawShapes(RenderWindow&) = draws the all the shapes stored in the vector to the window
readFromFile(fstream&) = opens and reads the data from a file into the vector
writeToFile(fstream&) = writes data currently stored in the vector to the file
*/
class ShapeMgr
{
private:
	vector<ShapeData> shapeMgr;
public:

	/* Constructor Function
	Purpose: merely exists for compiler reasons
	Inputs: N/A
	Outputs: N/A
	*/
	ShapeMgr()
	{
		
	}

	/* addShape Function
	Purpose: adds a shape to the vector
	Inputs:
	pos = the current position of the shape
	whichShape = what type of shape the object is
	color = the color accociated with the shape
	dwPos = the position of the drawing area
	w = the width of the drawing window
	h = the height of the drawing window
	Outputs: N/A
	*/
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color,Vector2f dwPos,int w,int h)
	{
		ShapeData tempShape;
		if (whichShape == SQUARE)
		{
			if (!((pos.x < (dwPos.x)) || ((pos.x + SIZE * 2) > w - 0.5*dwPos.x-1)||(pos.y<dwPos.y)||((pos.y+SIZE*2)> h - 1*dwPos.y)))
			{
				tempShape.colorF = color.toInteger();
				tempShape.colorO = color.toInteger();
				tempShape.isRectangle = true;
				tempShape.location = pos;
				shapeMgr.push_back(tempShape);
			}
		}
		else
		{
			if (!((pos.x < (dwPos.x)) || ((pos.x + SIZE * 2) > w - 0.5*dwPos.x - 1) || (pos.y < dwPos.y) || ((pos.y + SIZE * 2) > h - 1 * dwPos.y)))
			{
				tempShape.colorF = color.toInteger();
				tempShape.colorO = color.toInteger();
				tempShape.isRectangle = false;
				tempShape.location = pos;
				shapeMgr.push_back(tempShape);
			}
			
		}
	}

	/* addShape Function
	Purpose: draws the all the shapes stored in the vector to the window
	Inputs:
	win = the drawing window where everything is drawing to
	Outputs: N/A
	*/
	void drawShapes(RenderWindow& win)
	{
		for (int i = 0; i < shapeMgr.size(); i++)
		{
			if (shapeMgr[i].isRectangle)
			{
				Square tempS(shapeMgr[i].colorF, shapeMgr[i].colorO, shapeMgr[i].location);
				tempS.draw(win);
			}
			else
			{
				Circle tempC(shapeMgr[i].colorF, shapeMgr[i].colorO, shapeMgr[i].location);
				tempC.draw(win);
			}
		}
	}

	/* readFromFile Function
	Purpose: opens and reads the data from a file into the vector
	Inputs:
	file = the file where all of the shape data is stored
	Outputs: N/A
	*/
	void readFromFile(fstream& file)
	{
		file.open("shape.bin", ios::in | ios::out | ios::binary);
		ShapeData temp;
		unsigned int x;
		unsigned int y;
		while (file.read(reinterpret_cast<char*>(&temp.colorF), sizeof(temp.colorF)))
		{
			file.read(reinterpret_cast<char*>(&temp.colorO), sizeof(temp.colorO));
			file.read(reinterpret_cast<char*>(&temp.isRectangle), sizeof(temp.isRectangle));
			file.read(reinterpret_cast<char*>(&x), sizeof(x));
			file.read(reinterpret_cast<char*>(&y), sizeof(y));
			temp.location.x = x;
			temp.location.y = y;
			shapeMgr.push_back(temp);
		}
	}

	/* writeToFile Function
	Purpose: writes data currently stored in the vector to the file
	Inputs:
	file = the file where all of the shape data is stored
	Outputs: N/A
	*/
	void writeToFile(fstream& file)
	{
		file.clear();
		file.seekg(0);
		file.seekp(0);
		unsigned int x;
		unsigned int y;
		for (int i = 0; i<shapeMgr.size(); i++)
		{
			x = shapeMgr[i].location.x;
			y = shapeMgr[i].location.y;
			file.write(reinterpret_cast<char*>(&shapeMgr[i].colorF), sizeof(shapeMgr[i].colorF));
			file.write(reinterpret_cast<char*>(&shapeMgr[i].colorO), sizeof(shapeMgr[i].colorO));
			file.write(reinterpret_cast<char*>(&shapeMgr[i].isRectangle), sizeof(shapeMgr[i].isRectangle));
			file.write(reinterpret_cast<char*>(&x), sizeof(x));
			file.write(reinterpret_cast<char*>(&y), sizeof(y));
		}
	}

};
