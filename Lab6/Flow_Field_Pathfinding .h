//
// C00204076
// Brandon Seah-Dempsey
// Started at 10:47 16 November 2018
// Finished at
// Time Taken:
// Known bugs:

#include "SFML/Graphics.hpp"

#include "Tile.h"

#include <vector>
#include <iostream>

//
class FlowField
{
public:
	FlowField();
	~FlowField();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);


private:


	//
	const int gridSizeX = 50, gridSizeY = 50; // X is row and Y is column
	const float tileScale = 0.25;
	const int blockedCost = 999;

	// Start Grid variables
	int startX = 1;
	int startY = 1;
	int pathType = 0; // 0 for follow Tiles, 1 for Flow
	bool showFlow = false;
	bool showPath = false;

	// Goal Grid variables
	int goalX = 0;
	int goalY = 0;
	bool goalChanged = true;
	bool startChanged = true;

};