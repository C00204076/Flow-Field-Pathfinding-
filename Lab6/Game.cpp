//
// C00204076
// Brandon Seah-Dempsey
// Started at 9:51 16 November 2018
// Finished at
// Time Taken:
// Known bugs:

#include "Game.h"

//
Game::Game() :
	m_window{ sf::VideoMode{2500, 2000, 32}, "Lab 6" },
	is_running{ true }
{
	m_flowField = new FlowField();

	
}

//
Game::~Game()
{

}

//
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			//timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timeSinceLastUpdate);
			timeSinceLastUpdate = sf::Time::Zero;

		}

		render();
	}
}

//
void Game::update(sf::Time deltaTime)
{
	m_flowField->update(deltaTime);

	//
	if (!is_running)
	{
		m_window.close();
	}
}

//
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				is_running = false;
			}
		}
	}
}

//
void Game::render()
{
	//
	m_window.clear(sf::Color(0, 0, 0));
	
	//

	//
	m_window.display();
}