#pragma once
#include "SFML/Graphics/CircleShape.hpp"
#include "../Component.hpp"
#include "../Game.hpp"

using namespace wn2d;

class ExampleComponent : public Component{
private:
	sf::CircleShape image;

public:
	//pass in the Score component and both Paddle components to do game logic later on
	ExampleComponent(sf::Vector2f startingPosition){
		//set up the image
		image.setRadius(100.0f);
		image.setOrigin(image.getRadius() / 2.0f, image.getRadius() / 2.0f);
		image.setPosition(startingPosition);
		image.setFillColor(sf::Color::Red);
	}

	~ExampleComponent(){

	}

	void init() override{
		owner->setZ(0);
	}

	void update(float frameTime) override{
		init();
	}

	void draw(sf::RenderTarget& target) override{
		target.draw(image);
	}
};