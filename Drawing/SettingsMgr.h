#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

/* settingsMgr Class
Private Data:
color = stores the color of the drawing shape
shape = stores the shape type of the object
Public Functions:
settingsMgr(Color, ShapeEnum) = constructor to set up the initial settings
getCurColor() = function that returns the current Color settings
setCurColor(Color) = function that replaces the old color setting
getCurShape() = Function that returns the current Shape Settings
setCurShape(ShapeEnum) = Function that replaces the old shape setting
*/
class SettingsMgr
{
private:
	Color color;
	ShapeEnum shape;
public:
	/* Constructor Function
	Purpose: to set up the initial settings
	Inputs:
	startingColor = the intial color state
	startingShape = the initial shape state
	Outputs: N/A
	*/
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		color = startingColor;
		shape = startingShape;
	}

	/* getCurColor Function
	Purpose: to return the current Color settings
	Inputs: N/A
	Outputs:
	color = the current color settings
	*/
	Color getCurColor()
	{
		return color;
	}

	/* setCurColor Function
	Purpose: to replace the old color setting
	Inputs:
	c = the new color setting
	Outputs: N/A
	*/
	void setCurColor(Color c)
	{
		color = c;
	}

	/* getCurShape Function
	Purpose: to return the current shape settings
	Inputs: N/A
	Outputs:
	color = the current shape settings
	*/
	ShapeEnum getCurShape()
	{
		return shape; // just to make it compile;
	}

	/* setCurShape Function
	Purpose: to replace the old shape setting
	Inputs:
	s = the new shape setting
	Outputs: N/A
	*/
	void setCurShape(ShapeEnum s)
	{
		shape = s;
	}

};
