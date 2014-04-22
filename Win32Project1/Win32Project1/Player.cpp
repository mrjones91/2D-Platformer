#include "Player.h"


		

		void Player::Gravity(sf::Clock fallClock ,sf::RectangleShape floor)
		{
			if (!(foot.getGlobalBounds().intersects(floor.getGlobalBounds())))
			{
				if (jump == 0)
				{
				//fallTime = fallClock.restart();
				fall = falling * fallClock.getElapsedTime().asSeconds();
				std::cout << "Fall = " << fall << std::endl;
				std::cout << fallClock.getElapsedTime().asSeconds() << std::endl;
				foot.move(0, fall);
				body.move(0, fall);
				}
			}
			else
			{
				fallClock.restart();

			}

			//return 0;
		}
		void Player::Jump(sf::Clock fallClock, sf::RectangleShape floor)
		{
			if (foot.getGlobalBounds().intersects(floor.getGlobalBounds()) )
			{
				sf::Time time; //fallClock.getElapsedTime().asMilliseconds();
				//fallClock.restart();
				//body.setPosition(200.0f, 200.0f);
				//foot.setPosition(200.0f, 300.0f);
				//if (jump < jumpH)
				{
					std::cout << jumpF << " * " << fallClock.getElapsedTime().asMicroseconds() << std::endl;
					jump += jumpF * fallClock.getElapsedTime().asSeconds();
					body.move(0, jump);
					foot.move(0, jump);
				}
				/*else if (jump >= jumpH)
				{
					jump = 0;
				}*/
			}
		}

		void Player::Move(sf::Vector2f vel)
		{
			velocity.x *= vel.x;
			velocity.y *= vel.y;
			body.move(velocity.x, velocity.y);
			foot.move(velocity.x, velocity.y);
		}
		Player::Player()
		{			
			falling = 9.8f;
			jumpF = -5000.0f;
			jumpH = 200.0f;
			jump = 0;
			velocity.x = 55.0f;
			velocity.y = 0;

			footSize = Vector2f(100, 10);
			body.setRadius(50.0f);
			body.setPosition(200.0f, 200.0f);
			body.setFillColor(sf::Color::Blue);

			foot.setSize(footSize);
			foot.setPosition(200.0f, 300.0f);
			foot.setFillColor(sf::Color::Green);
					
		}

		Player::~Player()
		{

		}
