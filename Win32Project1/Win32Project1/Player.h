#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef PLYR_H
#define PLYR_H

using namespace sf;

class Player
{
	public:
		//Player's image
		sf::CircleShape body;
		sf::RectangleShape foot;

		sf::Vector2f footSize;
		sf::Vector2f velocity;
		//Gravity Variables
		float falling;
		float jumpF, jumpH;
		float fall, jump;

		//sf::Window window();
		
		//Constructor
		Player();
		//Destructor
		~Player();
		//Method for falling
		void Gravity(sf::Clock, sf::RectangleShape);
		//Method for Moving
		void Move(sf::Vector2f);
		//Method for Jumps
		void Jump(sf::Clock, sf::RectangleShape);

};

#endif