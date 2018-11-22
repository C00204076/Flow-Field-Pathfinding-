//
// C00204076
// Brandon Seah-Dempsey
// Started at 14:22 19 November 2018
// Finished at
// Time Taken:
// Known bugs

#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

//
class Tile
{
public:
	Tile(float x, float y);
	~Tile();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);

	void setGoal();
	void setNetural();
	void setStart();
	void setBlock();

private:
	sf::RectangleShape m_tile;

	sf::Vector2f m_position;

	bool m_isGoal, m_isNetural, m_isStart, m_isBlock;
};

#endif // !TILE_H