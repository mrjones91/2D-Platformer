#include "InputController.h"

int InputController::InputHandle(sf::Event evnt)
{
	int val = 1;
	switch (evnt.type)
	{
			case sf::Event::Closed:
				val = -1;
				std::cout << val << std::endl;
				return val;
				break;
			default:
				val = 0;
				return val;
			case sf::Event::KeyPressed:
			{
				switch (evnt.key.code)
				{
				case sf::Keyboard::Escape:
					val = -1;
					return val;
					break;
				case sf::Keyboard::Right:
					std::cout << "right" << std::endl;
					val = 1;
					return val;
					break;
				case sf::Keyboard::Left:
					std::cout << "left" << std::endl;
					val = 2;
					return val;
					break;
				case sf::Keyboard::Space:
					std::cout << "JUMP" << std::endl;
					val = 3;
					return val;
					break;
				default:
					val = 0;
					return val;
					break;
				}
			}
				/*
				if (event.key.code == sf::Keyboard::Up)
				{
					
					/*
					if (foot.getGlobalBounds().intersects(floor.getGlobalBounds()) )
					{
						std::cout << "jump";
						jump = jumpF * fallClock.getElapsedTime().asSeconds();
						shape.move(0, jump);
						foot.move(0, jump);
						fallClock.restart();
					}
					*/
					
					
	}
}