#include "Globals.h"
#include "Seller.h"
#include "DiceRoller.h"

#include <iostream>
#include <conio.h>

Seller::Seller()
{
	DiceRoller dice;

	strPoitionQuantity = dice.Roll1DN(5);
	defPoitionQuantity = dice.Roll1DN(5);
	aglPoitionQuantity = dice.Roll1DN(5);
	vtlPoitionQuantity = dice.Roll1DN(5);
	lukPoitionQuantity = dice.Roll1DN(5);

	strPoitionPrice = 10 * dice.Roll1DN(5);
	defPoitionPrice = 10 * dice.Roll1DN(5);
	aglPoitionPrice = 10 * dice.Roll1DN(5);
	vtlPoitionPrice = 10 * dice.Roll1DN(5);
	lukPoitionPrice = 10 * dice.Roll1DN(5);

	coins = 0;
}

int BuyPoition(int poition, Seller& seller)
{
	DiceRoller dice;

	switch (poition) {
	case 1:
	{
		if (thePlayer.coins >= seller.strPoitionPrice) {
			if (seller.strPoitionQuantity >= 1)
			{
				thePlayer.coins -= seller.strPoitionPrice;
				seller.strPoitionQuantity--;
				thePlayer.modStr += dice.Roll1DN(4);
				return 0;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
		break;
	}
	case 2:
	{
		if (thePlayer.coins >= seller.defPoitionPrice) {
			if (seller.defPoitionQuantity >= 1)
			{
				thePlayer.coins -= seller.defPoitionPrice;
				seller.defPoitionQuantity--;
				thePlayer.modDef += dice.Roll1DN(4);
				return 0;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
		break;
	}
	case 3:
	{
		if (thePlayer.coins >= seller.aglPoitionPrice) {
			if (seller.aglPoitionQuantity >= 1)
			{
				thePlayer.coins -= seller.aglPoitionPrice;
				seller.aglPoitionQuantity--;
				thePlayer.modAgl += dice.Roll1DN(4);
				return 0;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
		break;
	}
	case 4:
	{
		if (thePlayer.coins >= seller.vtlPoitionPrice) {
			if (seller.vtlPoitionQuantity >= 1)
			{
				thePlayer.coins -= seller.vtlPoitionPrice;
				seller.vtlPoitionQuantity--;
				thePlayer.vtl += 10 * dice.Roll1DN(4);
				return 0;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
		break;
	}
	case 5:
	{
		if (thePlayer.coins >= seller.lukPoitionPrice) {
			if (seller.strPoitionQuantity >= 1)
			{
				thePlayer.coins -= seller.lukPoitionPrice;
				seller.lukPoitionQuantity--;
				thePlayer.modStr += dice.Roll1DN(4);
				return 0;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
		break;
	}
	default:
	{
		return 3;
		break;
	}
	}
}

void Talk(Seller& seller) {
	system("cls");
	theMap.Draw();

	std::cout << "\n\tBlahblahblah\n";
	std::cout << "\n\tStr = 1, price is " << seller.strPoitionPrice << "c and I have " << seller.strPoitionQuantity << " of them.";
	std::cout << "\n\tDef = 2, price is " << seller.defPoitionPrice << "c and I have " << seller.defPoitionQuantity << " of them.";
	std::cout << "\n\tAgl = 3, price is " << seller.aglPoitionPrice << "c and I have " << seller.aglPoitionQuantity << " of them.";
	std::cout << "\n\tVit = 4, price is " << seller.vtlPoitionPrice << "c and I have " << seller.vtlPoitionQuantity << " of them.";
	std::cout << "\n\tLuk = 5, price is " << seller.lukPoitionPrice << "c and I have " << seller.lukPoitionQuantity << " of them.";
	std::cout << "\n\n\tWant some?";

	int result = -1;
	while (result != 0) {
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case 27:               // press ESC to exit
				result = 0;
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			{
				result = BuyPoition(ch, seller);
				break;
			}
			default:
				break;
			}
		}

		switch (result)
		{
		case 0:
			std::cout << "\n\tThanks, bye!";
			break;
		case 1:
			std::cout << "\n\tGet more coins, " << thePlayer.name;
			break;
		case 2:
			std::cout << "\n\tSorry, " << thePlayer.name << " I don't have any of these.\n\tCome back later, maybe I'll get some!";
			break;
		default:
			std::cout << "\n\tSorry, what was that? Could you repeat, please?";
			break;
		}

	}

}