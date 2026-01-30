#include "Level.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) : BaseLevel(hwnd, in)
{

	//in level constructor
	m_sheep.setInput(&m_input);

	

	if (!m_sheepSprites.loadFromFile("gfx/sheep_sheet.png")) { std::cerr << "gfx/sheep_sheet.png not found\n"; }
	m_sheep.setTexture(&m_sheepSprites, true);
	m_sheep.setTextureRect(sf::IntRect({ 0,0 }, { 64,64 }));

	m_sheep.setSize({64,64});
	
	
}

// handle user input
void Level::handleInput(float dt)
{
	//in level::handleInput(dt)
	m_sheep.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	if (m_gameOver) return;
	m_sheep.update(dt);

	// check wall collision
	sf::Vector2f pos = m_sheep.getPosition();
	float radius = m_sheep.getSize().x;

	if (pos.x < 0 || pos.x + radius > m_window.getSize().x || pos.y < 0 || pos.y + radius > m_window.getSize().y)
	{
		m_gameOver = true;
		std::cout << "Game over";
	}
	
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_sheep);
	endDraw();
}

