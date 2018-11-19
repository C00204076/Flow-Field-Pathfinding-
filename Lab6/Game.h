//
// C00204076
// Brandon Seah-Dempsey
// Started at 9:43 16 November 2018
// Finished at
// Time Taken:
// Known bugs:

#include "Flow_Field_Pathfinding .h"

#include "SFML/Graphics.hpp"

#include <iostream>


#ifndef GAME_H
#define GAME_H

//
class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow m_window;

	bool is_running;

	FlowField * m_flowField;
};

#endif // !GAME_H