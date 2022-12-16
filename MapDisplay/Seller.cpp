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

int Seller::BuyPoition(int poition)
{
	DiceRoller dice;

	switch (poition) {
	case 1:
	{
		if (thePlayer.coins >= strPoitionPrice) {
			if (strPoitionQuantity >= 1)
			{
				thePlayer.coins -= strPoitionPrice;
				coins += strPoitionPrice;
				strPoitionQuantity--;
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
		if (thePlayer.coins >= defPoitionPrice) {
			if (defPoitionQuantity >= 1)
			{
				thePlayer.coins -= defPoitionPrice;
				coins += defPoitionPrice;
				defPoitionQuantity--;
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
		if (thePlayer.coins >= aglPoitionPrice) {
			if (aglPoitionQuantity >= 1)
			{
				thePlayer.coins -= aglPoitionPrice;
				coins += aglPoitionPrice;
				aglPoitionQuantity--;
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
		if (thePlayer.coins >= vtlPoitionPrice) {
			if (vtlPoitionQuantity >= 1)
			{
				thePlayer.coins -= vtlPoitionPrice;
				coins += vtlPoitionPrice;
				vtlPoitionQuantity--;
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
		if (thePlayer.coins >= lukPoitionPrice) {
			if (strPoitionQuantity >= 1)
			{
				thePlayer.coins -= lukPoitionPrice;
				coins += lukPoitionPrice;
				lukPoitionQuantity--;
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

void Seller::Talk() {
	system("cls");
	theMap.Draw();
	int choice = -1;
	int result = -1;

	std::cout << "\n\tBlahblahblah\n";
	std::cout << "\n\tStr = 1, price is " << strPoitionPrice << "c and I have " << strPoitionQuantity << " of them.";
	std::cout << "\n\tDef = 2, price is " << defPoitionPrice << "c and I have " << defPoitionQuantity << " of them.";
	std::cout << "\n\tAgl = 3, price is " << aglPoitionPrice << "c and I have " << aglPoitionQuantity << " of them.";
	std::cout << "\n\tVit = 4, price is " << vtlPoitionPrice << "c and I have " << vtlPoitionQuantity << " of them.";
	std::cout << "\n\tLuk = 5, price is " << lukPoitionPrice << "c and I have " << lukPoitionQuantity << " of them.";
	std::cout << "\n\n\tWhat do you want? If you want none (0), feel free to come back any time you want";

	while (choice != 0) {
		std::cin >> choice;
		switch (choice) {
		case 1:
		{
			result = BuyPoition(choice);
			break;
		}
		case 2:
		{
			result = BuyPoition(choice);
			break;
		}
		case 3:
		{
			result = BuyPoition(choice);
			break;
		}
		case 4:
		{
			result = BuyPoition(choice);
			break;
		}
		case 5:
		{
			result = BuyPoition(choice);
			break;
		}
		default:
			std::cin.clear();
			break;
		}

		switch (result)
		{
		case 0:
			choice = 0;
			std::cout << "\n\tThanks, bye!";
			break;
		case 1:
			std::cout << "\n\tGet more coins, " << thePlayer.name;
			break;
		case 2:
			std::cout << "\n\tSorry, " << thePlayer.name << ", I don't have any of these.\n\tCome back later, maybe I'll get some!";
			break;
		default:
			std::cout << "\n\tSorry, what was that? Could you repeat, please?";
			break;
		}
	}
}