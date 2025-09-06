#include <iostream>
#include "random.h" //for header file
namespace Intro
{
	void hello()
	{
		std::cout << "Welcome to NewbieTapDev!\n\n";
		std::cout << "Introduce to the game Hilo:\n";
		std::cout << "If right number is 11 and you guess it's 15. You will get a message too high compared right number.\n";
		std::cout << "Conversely, if you guess it's 5 you will get a message too low compared right number.\n\n";
		std::cout << "Let's start!\n";
	}
}
bool playHilo(int min, int max, int guess)
{
	const int rdNum{ Random::get(min, max) };
	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max << ". You have " << guess << " tries to guess what it is.\n";
	for (int i{ 1 }; i <= guess; ++i)
	{
		std::cout << "Guess #" << i << ": ";
		int g{};
		std::cin >> g;
		if (g == rdNum)
		{
			std::cout << "Correct! You win!\n";
			return true;
		}
		else if (g < rdNum)
			std::cout << "Your guess is too low\n";
		else if (g > rdNum)
			std::cout << "Your guess is too high\n";
	}
	std::cout << "Sorry, you lose. The correct number was " << rdNum << ".\n";
	return false;
}
bool playAgain()
{

	while (true)
	{
		std::cout << '\n';
		std::cout << "Would you like to play again (y/n) ? ";
		char c{};
		std::cin >> c;
		switch (c)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		}
		//if user input other y and n this loop will be repeated
	}
}
void introduce()
{
	std::cout << '\n';
	std::cout << "Enter minimum value for hilo game : ";
	int min{};
	std::cin >> min;
	std::cout << "Enter maximum value for hilo game : ";
	int max{};
	std::cin >> max;
	int guess{};
	std::cout << "Enter times guess : ";
	std::cin >> guess;
	playHilo(min, max, guess);
}
int main()
{
	using Intro::hello;
	hello();
	do
	{
		introduce(); //updated for short
	} while (playAgain());
	std::cout << "Thanks you for playing.\n";


}

