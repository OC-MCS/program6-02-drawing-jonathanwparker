#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include <SFML/Graphics.hpp>
#include "Shape.h"
// finish this code; add functions, data as needed

/* SettingsUI Class
Private Data:
redButton = stores the shape data of the red button displayed on screen
blueButton = stores the shape data of the blue button displayed on screen
greenButton = stores the shape data of the green button displayed on screen
isRectangle = stores the shape data of the rectangle choice button displayed on screen
isCircle = stores the shape data of the circle choice button displayed on screen
Public Functions:
SettingsUI(settingsMgr*) = constructor to setup the initial states of the settings buttons
handleMouseUp(Vector2f,settignsMgr*) = function to check if a mouse click was on one of the buttons
draw(RenderWindow&) = function to draw the buttons to the drawing window
*/
class SettingsUI
{
private:
	ShapeData redButton,blueButton,greenButton,isRectangle,isCircle;
public:
	/* Constructor Function
	Purpose: to setup the initial states of the settings buttons
	Inputs:
	mgr = the initial states of the settings for the drawing shape
	Outputs: N/A
	*/
	SettingsUI(SettingsMgr *mgr)
	{
		redButton.location = Vector2f(2.5*SIZE + SIZE/2, 3*SIZE);
		greenButton.location = Vector2f(2.5*SIZE + SIZE / 2, 3*SIZE+3*SIZE);
		blueButton.location = Vector2f(2.5 * SIZE + SIZE / 2, 3 * SIZE + 6*SIZE);
		isRectangle.location = Vector2f(2.5 * SIZE + SIZE / 2, 3 * SIZE + 12*SIZE);
		isCircle.location = Vector2f(2.5 * SIZE + SIZE / 2, 3 * SIZE + 15*SIZE);
		redButton.colorO = RED;
		greenButton.colorO = GREEN;
		blueButton.colorO = BLUE;
		isRectangle.colorO = WHITE;
		isCircle.colorO = WHITE;
		if (mgr->getCurColor() == Color::Blue)
		{
			redButton.colorF = TRANSPARENT;
			greenButton.colorF = TRANSPARENT;
			blueButton.colorF = BLUE;
			mgr->setCurColor(Color::Blue);
		}
		else if (mgr->getCurColor() == Color::Red)
		{
			redButton.colorF = RED;
			greenButton.colorF = TRANSPARENT;
			blueButton.colorF = TRANSPARENT;
			mgr->setCurColor(Color::Red);
		}
		else if (mgr->getCurColor() == Color::Green)
		{
			redButton.colorF = TRANSPARENT;
			greenButton.colorF = GREEN;
			blueButton.colorF = TRANSPARENT;
			mgr->setCurColor(Color::Green);
		}
		if (mgr->getCurShape() == ShapeEnum(CIRCLE))
		{
			isRectangle.colorF = TRANSPARENT;
			isCircle.colorF = WHITE;
			mgr->setCurShape(CIRCLE);
		}
		else if (mgr->getCurShape() == ShapeEnum(SQUARE))
		{
			isRectangle.colorF = WHITE;
			isCircle.colorF = TRANSPARENT;
			mgr->setCurShape(SQUARE);
		}
	}
	/* handleMouseUp Function
	Purpose: draw the buttons to the drawing window
	Inputs:
	mouse =  the position of the mouse when it was clicked
	mgr = controls the states of the drawing shape
	Outputs: N/A
	*/
	void handleMouseUp(Vector2f mouse, SettingsMgr *mgr)
	{
		FloatRect redB(redButton.location, Vector2f(2*SIZE, 2 * SIZE));
		FloatRect blueB(blueButton.location, Vector2f(2 * SIZE, 2 * SIZE));
		FloatRect greenB(greenButton.location, Vector2f(2 * SIZE, 2 * SIZE));
		FloatRect isRect(isRectangle.location, Vector2f(2 * SIZE, 2 * SIZE));
		FloatRect isCirc(isCircle.location, Vector2f(2 * SIZE, 2 * SIZE));
		if (redB.contains(mouse))
		{
			redButton.colorF = RED;
			greenButton.colorF = TRANSPARENT;
			blueButton.colorF = TRANSPARENT;
			mgr->setCurColor(Color::Red);
		}
		else if (blueB.contains(mouse))
		{
			redButton.colorF = TRANSPARENT;
			greenButton.colorF = TRANSPARENT;
			blueButton.colorF = BLUE;
			mgr->setCurColor(Color::Blue);
		}
		else if (greenB.contains(mouse))
		{
			redButton.colorF = TRANSPARENT;
			greenButton.colorF = GREEN;
			blueButton.colorF = TRANSPARENT;
			mgr->setCurColor(Color::Green);
		}
		else if (isRect.contains(mouse))
		{
			isRectangle.colorF = WHITE;
			isCircle.colorF = TRANSPARENT;
			mgr->setCurShape(SQUARE);
		}
		else if (isCirc.contains(mouse))
		{
			isRectangle.colorF = TRANSPARENT;
			isCircle.colorF = WHITE;
			mgr->setCurShape(CIRCLE);
		}
	}

	/* draw Function
	Purpose: draw the buttons to the drawing window
	Inputs:
	win = the window where the buttons and the text will be drawn
	Outputs: N/A
	*/
	void draw(RenderWindow& win)
	{
		Circle redB(redButton.colorF,redButton.colorO, redButton.location);
		Circle blueB(blueButton.colorF, blueButton.colorO, blueButton.location);
		Circle greenB(greenButton.colorF, greenButton.colorO, greenButton.location);
		Circle isCirc(isCircle.colorF, isCircle.colorO, isCircle.location);
		Square isRect(isRectangle.colorF,isRectangle.colorO, isRectangle.location);
		redB.draw(win);
		blueB.draw(win);
		greenB.draw(win);
		redB.draw(win);
		isCirc.draw(win);
		isRect.draw(win);
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			cout << "Couldn't load font.";
		}
		else
		{
			Text drawingColor("Drawing Color", font, 25);
			Text drawingShape("Drawing Shape", font, 25);
			drawingColor.setPosition(SIZE, SIZE);
			win.draw(drawingColor);
			drawingShape.setPosition(SIZE - 8, SIZE * 13);
			win.draw(drawingShape);
		}
	}

};
