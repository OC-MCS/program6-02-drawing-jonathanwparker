//================================================
// JONATHAN PARKER
//================================================
#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;



int main()
{
	/* Variables
	WINDOW_WIDTH = width of the drawing window
	WINDOW_HEIGHT = height of the drawing window
	drawingWindow = the upper right position of the drawing area
	shapesFile 
	*/
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	Vector2f drawingWindowPos(200, 50);
	fstream shapesFile;

	//Class Initializations
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);
	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE);
	SettingsUI  settingsUI(&settingsMgr); 
	ShapeMgr    shapeMgr;
	DrawingUI   drawingUI(drawingWindowPos,WINDOW_WIDTH,WINDOW_HEIGHT);
	


	shapeMgr.readFromFile(shapesFile);

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				shapeMgr.writeToFile(shapesFile);
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				//The following code checks for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos, &settingsMgr);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				mousePos.x -= SIZE;
				mousePos.y -= SIZE;
				// Checks to see if mouse is in the drawing area
				if (drawingUI.isMouseInCanvas(mousePos))
				{
					// add a shape to the list based on current settings
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor(),drawingWindowPos, WINDOW_WIDTH, WINDOW_HEIGHT);
				}
			}
		}

		// The remainder of the body of the loop draws one frame of the animation
		window.clear();

		// this draws the left hand side of the window (all of the settings info)
		settingsUI.draw(window);

		// this draws the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);

		window.display();
	} // end body of animation loop

	return 0;
}