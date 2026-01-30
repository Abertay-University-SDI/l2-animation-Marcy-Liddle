#pragma once

#include "Framework/BaseLevel.h"
#include "Framework/GameObject.h"
#include "sheep.h"

class Level :public BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();
	
	
private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	
	Sheep m_sheep;
	
	bool m_gameOver = false;
	
	sf::Texture m_sheepSprites;
};