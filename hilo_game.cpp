#include <iostream>
#include "random.h" //for header file
#include <limits> //for std::numeric_limits
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool validationNum(int min, int max)
{
	if (min <= 0 || max <= 0)
		return false;
	else
		return true;
}
bool validationGuess(int guess, int min, int max)
{
	if (guess < min)
		return false;
	if (guess > max)
		return false;
	return true;
}
void hello()
{
	std::cout << "Welcome to NewbieTapDev!\n\n";
	std::cout << "Introduce to the game Hilo:\n";
	std::cout << "If right number is 11 and you guess it's 15. You will get a message too high compared right number.\n";
	std::cout << "Conversely, if you guess it's 5 you will get a message too low compared right number.\n";
	std::cout << "This game will ended when you guess right answer or you lose if expired guess you have just entered.\n";
	std::cout << "Let's start!\n\n";
}
bool playHilo(int min, int max, int guess)
{
	const int rdNum{ Random::get(min, max) };
	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max << ". You have " << guess << " tries to guess what it is.\n";
	for (int i{ 1 }; i <= guess; ++i)
	{
		
		int g{};
		while (true)
		{
			std::cout << "Guess #" << i << ": ";
			std::cin >> g;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete all characters unextracted until '\n'
			if (validationGuess(g, min, max))
				break;
			else
			{
				std::cout << "You have already entered invalid guess, please try again!\n";
				continue;
			}
		}
		if (g == rdNum)
			std::cout << "Correct! You win!\n";
		else if (g < rdNum)
			std::cout << "Your guess is too low\n";
		else if (g > rdNum)
			std::cout << "Your guess is to high\n";
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
	int min{};
	int max{};
	while (true)
	{
		std::cout << "Enter minimum value for hilo game : ";
		std::cin >> min;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter maximum value for hilo game : ";
		std::cin >> max;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (validationNum(min, max))
		{
			if (min < max)
				break;
			else
			{
				std::cout << "You have already entered invalid inputs, please try again!\n";
				continue;
			}
		}
		else
			std::cout << "You have already entered invalid inputs, please try again!\n";
	}
	int guess{};
	while (true)
	{
		std::cout << "Enter times guess : ";
		std::cin >> guess;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (guess <= 0)
			std::cout << "You just enter invalid value for guess, please try again!\n";
		else
			break;
	}
	playHilo(min, max, guess);
}
int main()
{
	//more modularity you can able more maintaining a lot.
	hello();
	do
	{
		introduce(); //updated for short
	} while (playAgain());
	std::cout << "Thanks you for playing.\n";


}


