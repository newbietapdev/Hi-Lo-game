#include <iostream>
#include "random.h"
int main()
{
	while (true)
	{
		std::cout << "Cung nhau choi 1 tro choi. Toi dang nghi ve mot so giua 1 va 100.\n";
		std::cout << "Ban co 7 luot thu doan xem so nay la so nao.\n\n";
		int flag{ 0 };
		int numRan{ Random::get(1, 100) };
		for (int i{ 1 }; i <= 7; ++i)
		{
			std::cout << "Du doan #" << i << ": ";
			int guessU{};
			std::cin >> guessU;
			if (guessU == numRan)
			{
				flag = 1;
				std::cout << "Chinh xac! Ban chien thang!\n\n";
				break;
			}
			else if (guessU < numRan)
			{
				std::cout << "Ban du doan qua thap\n\n";
			}
			else if (guessU > numRan)
			{
				std::cout << "Ban du doan qua cao\n\n";
			}
		}
		if (flag != 1)
			std::cout << "Xin loi, ban da that bai. Con so chinh xac la : " << numRan << "\n\n";
		
	tryAgain:
		std::cout << "Ban co muon choi lai khong (y/n)? ";
		char pr{};
		std::cin >> pr;
		
		if (pr != 'y' && pr != 'n')
		{
			std::cout << "Ban vua nhap ky tu khong hop le! Vui long nhap lai!\n";
			goto tryAgain;
		}
		else if (pr == 'y')
			continue;
		else if (pr == 'n')
		{
			std::cout << "Developed by NewbieTapDev\n";
			break;
		}
	}
	return 0;
}