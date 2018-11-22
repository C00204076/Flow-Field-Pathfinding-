//
// C00204076
// Brandon Seah-Dempsey
// Started at 15:50 22 November 2018
// Finished at
// Time Taken:
// Known bugs:

#include "TileMap.h"

//
TileMap::TileMap()
{

}

//
TileMap::~TileMap()
{

}

//
void TileMap::initialise()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			m_tileVector.push_back(Tile(i * 60, j * 60));
		}
	}
}

//
void TileMap::update(sf::Time deltaTime)
{
	for (int i = 0; i < 50; i++)
	{
		/*for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == 0)
			{

			}
		}*/
		m_tileVector[i].setNetural();
		
	}
}

//
void TileMap::render(sf::RenderWindow & window)
{
	for (int i = 0; i < m_tileVector.size(); i++)
	{
		m_tileVector[i].render(window);
	}
}