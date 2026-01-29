#include "sheep.h"

Sheep::Sheep() 
{
	for (int i = 0; i > 4; i++)
	{
		m_walkDown.addFrame(sf::IntRect({ i * 64,0 }, { 64,64 }));
		m_walkDown.setLooping(true);
		m_walkDown.setFrameSpeed(1.f / 1.4f);

	}

};

void::Sheep::handleInput(float dt) {}

void::Sheep::update(float dt) {}

