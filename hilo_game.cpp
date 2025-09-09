#include <iostream>
#include "random.h" //for header file
#include <limits> //for std::numeric_limits
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool clearFailedExtracted()
{
	if (!std::cin) //std::cin has been moved to failure mode
	{
		std::cin.clear(); //put us to normal operation mode
		ignoreLine();
		return true;
	}
	return false; //otherwise
}
bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
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
void playHilo(int min, int max, int guess)
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
			if (clearFailedExtracted())
				continue;
			if (hasUnextractedInput())
			{
				ignoreLine();
				continue;
			}
			else
			{
				if (g < min || g > max)
				{
					std::cout << "You may input value beyond roughly minimum and maximum value, please try again!\n";
					ignoreLine();
					continue;
				}
				else
					break;
			}
		}
		if (g == rdNum)
		{
			std::cout << "Correct! You win!\n";
			return;
		}
		else if (g < rdNum)
			std::cout << "Your guess is too low\n";
		else if (g > rdNum)
			std::cout << "Your guess is to high\n";
	}
	std::cout << "Sorry, you lose. The correct number was " << rdNum << ".\n";
	return;
}
bool playAgain()
{
	char c{};
	while (true)
	{
		std::cout << '\n';
		std::cout << "Would you like to play again (y/n) ? ";
		std::cin >> c;
		if (clearFailedExtracted())
			continue;
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		else
		{
			if (c != 'y' && c != 'n')
			{
				ignoreLine();
				continue;
			}
			else
			{
				if (c == 'y')
					return true;
				else if (c == 'n')
				{
					std::cout << "Thanks you for playing.\n";
					return false;
				}
			}
		}
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
		if (clearFailedExtracted())
			continue;
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		break;
	}
	while (true)
	{
		std::cout << "Enter maximum value for hilo game : ";
		std::cin >> max;
		if (clearFailedExtracted())
			continue;
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		else
		{
			if (max <= min)
			{
				ignoreLine();
				continue;
			}
			else
				break;
		}
	}
	int guess{};
	while (true)
	{
		std::cout << "Enter times guess: ";
		std::cin >> guess;
		if (clearFailedExtracted())
			continue;
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		else
		{
			if (guess <= 0)
			{
				ignoreLine();
				continue;
			}
			else
				break;
		}
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
	


}



