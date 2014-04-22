#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "InputController.h"

int main()
{
	//////////////////////////////////////////////////
	//- Creating a Window and displaying a shape - //
	////////////////////////////////////////////////
	sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!", sf::Style::Default);
	window.setKeyRepeatEnabled(true);


	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Green);
	int color = 0;
	const int limit = 5;
	const float right = 55.0f;
	sf::Color colorz[limit] = { sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::White};

	/////Platforming wat wat
	sf::Vector2f footSize(100, 10);
	sf::RectangleShape foot;
	foot.setSize(footSize);
	foot.setFillColor(sf::Color::Red);
	foot.setPosition(400.0f, 300.0f);

	sf::RectangleShape floor;
	sf::Vector2f floorSize(700, 20);
	floor.setSize(floorSize);
	floor.setFillColor(sf::Color::Yellow);
	floor.setPosition(0.0f, 500.0f);

	Player test;
	
	float wat = test.body.getRadius();
	std::cout << wat ;
	
	InputController input;
	

	

	//Resizing
	//sf::Vector2u size(400, 400);

	//Display size/Setting Position
	//std::cout << size.x << " " << size.y << std::endl;
	shape.setPosition(400.0f, 200.0f);

	sf::Clock clock;
	sf::Clock fallClock;
	sf::Time time = sf::milliseconds(0);
	sf::Time fallTime = sf::milliseconds(0);
	//use Clock for time
	//sf::Time t2;
	//int timetick = 5;
	
	//Write to file
	std::fstream myfile;
	myfile.open("example.txt");

	//String
	//std::string message =  "Hello, this is a DJG production";
	//std::string display = "";
	//int index = 0;
	
	/////////////////////////////////////////////
	//- Game Loop / Keyboard Event Inputs / - //
	///////////////////////////////////////////
	float x, y;
	while (window.isOpen())
	{
		//time = sf::milliseconds(time.asMilliseconds() + 1);
		time = clock.getElapsedTime();
		
		//std::cout << "CPU Time: " << time.asSeconds() << std::endl;
		
		myfile << "CPU Time: " << time.asSeconds() << std::endl;
		
		//system("cls");

		test.Gravity(clock, floor);

		sf::Event event;
		while (window.pollEvent(event))
		{		
			switch (input.InputHandle(event))
			{
			case -1:
				myfile.close();
				window.close();
				break;
			case 1:
				test.velocity.x = 55.0f;
				test.velocity.y = 0;
				test.Move(sf::Vector2f(1, 0));
				break;
			case 2:
				test.velocity.x = -55.0f;
				test.velocity.y = 0;
				test.Move(sf::Vector2f(-1, 0));
				break;
			case 3:
				//JUMPING
				//fallClock.restart();
				test.velocity.y = -100.0f;
				test.Jump(fallClock, floor);
				break;

			}
			
		}
		
		window.clear();
		window.draw(shape);
		window.draw(foot);
		window.draw(floor);
		window.draw(test.body);
		window.draw(test.foot);
		window.display();
	}
	return 0;
}