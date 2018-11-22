//
// C00204076
// Brandon Seah-Dempsey
// Started at 14:22 19 November 2018
// Finished at
// Time Taken:
// Known bugs

#include "Tile.h"

//
Tile::Tile(float x, float y)
{
	m_position = sf::Vector2f(x, y);

	m_isGoal = false; 
	m_isNetural = true; 
	m_isStart = false; 
	m_isBlock = false;
}

//
Tile::~Tile()
{

}

//
void Tile::update(sf::Time deltaTime)
{
	//
	m_tile.setSize(sf::Vector2f(20, 20));
	m_tile.setOutlineColor(sf::Color::Black);
	m_tile.setOutlineThickness(5);
	m_tile.setPosition(m_position);

	//
	if (m_isGoal == true)
	{
		m_tile.setFillColor(sf::Color::Red);
	}
	//
	else if (m_isNetural == true)
	{
		m_tile.setFillColor(sf::Color::Blue);
	}
	//
	else if (m_isStart == true)
	{
		m_tile.setFillColor(sf::Color::Green);
	}
	//
	else if (m_isBlock == true)
	{
		m_tile.setFillColor(sf::Color::Black);
	}
}

//
void Tile::render(sf::RenderWindow& window)
{
	window.draw(m_tile);
}

/// <summary>
/// 
/// </summary>
void Tile::setGoal()
{
	m_isGoal = true;
	m_isNetural = false;
	m_isStart = false;
	m_isBlock = false;
}

/// <summary>
/// 
/// </summary>
void Tile::setNetural()
{
	m_isGoal = false;
	m_isNetural = true;
	m_isStart = false;
	m_isBlock = false;
}

/// <summary>
/// 
/// </summary>
void Tile::setStart()
{
	m_isGoal = false;
	m_isNetural = false;
	m_isStart = true;
	m_isBlock = false;
}

/// <summary>
/// 
/// </summary>
void Tile::setBlock()
{
	m_isGoal = false;
	m_isNetural = false;
	m_isStart = false;
	m_isBlock = true;
}