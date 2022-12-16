#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "Globals.h"
#include "Map.h"
#include "Player.h"
#include "DiceRoller.h"

using namespace std::literals::chrono_literals;

Player::Player()
{
	name = "Stranger";
	str = 0;            // physical attack
	def = 0;
	agl = 0;
	vtl = 0;
	luk = 0;

	modStr = 0;
	modDef = 0;
	modAgl = 0;
	modVtl = 0;
	modLuk = 0;

	x = 1;
	y = 1;

	sprite = '&';
	
	kills = 0;

	coins = 10;
}

void Player::Draw()
{
	std::cout << sprite;
}

void Player::Print()
{
	std::cout << "\n\tName: " << name << std::endl;

	std::cout << "\n\tDEF: " << def << " (";
	if (modDef > 0) std::cout << "+" << modDef << ")" << std::endl;
	else std::cout << modDef << ")" << std::endl;

	std::cout << "\tSTR: " << str << " (";
	if (modStr > 0) std::cout << "+" << modStr << ")" << std::endl;
	else std::cout << modStr << ")" << std::endl;

	std::cout << "\tAGL: " << agl << " (";
	if (modAgl > 0) std::cout << "+" << modAgl << ")" << std::endl;
	else std::cout << modAgl << ")" << std::endl;

	std::cout << "\tVIT: " << vtl << " (";
	if (modVtl > 0) std::cout << "+" << modVtl << ")" << std::endl;
	else std::cout << modVtl << ")" << std::endl;

	std::cout << "\tLUK: " << luk << " (";
	if (modLuk > 0) std::cout << "+" << modLuk << ")" << std::endl;
	else std::cout << modLuk << ")\n" << std::endl;
}

void Player::CreateCharacter()
{
	DiceRoller dice;
	int choice;
	system("cls");
	theMap.Draw();

	std::cout << "\n\tPlease enter a name for your character: \n\t";
	std::getline(std::cin, thePlayer.name);

	std::this_thread::sleep_for(500ms);
	system("cls");
	theMap.Draw();

	std::cout << "\n\tHow do you wish to set your characteristics?" << std::endl;
	std::cout << "\tPlease enter the # of your choice:" << std::endl;
	std::cout << "\t\t1) Roll 6D3" << std::endl;
	std::cout << "\t\t2) Roll 3D6" << std::endl;
	std::cout << "\t\t3) Roll 4D6 and drop the lowest" << std::endl;
	std::cout << "\t\t4) Roll 1D18\n\t";
	do {
		std::cin >> choice;
		switch (choice) {
		case 1: {
			//            TODO: Consider moving assigning values to function
			thePlayer.str = dice.Roll6D3();
			thePlayer.def = dice.Roll6D3() / 3;
			thePlayer.agl = dice.Roll6D3();
			thePlayer.vtl = dice.Roll6D3();
			thePlayer.luk = dice.Roll6D3() / 6;
		}
			  break;
		case 2: {
			thePlayer.str = dice.Roll3D6();
			thePlayer.def = dice.Roll3D6() / 3;
			thePlayer.agl = dice.Roll3D6();
			thePlayer.vtl = dice.Roll3D6();
			thePlayer.luk = dice.Roll3D6() / 3;
		}
			  break;
		case 3: {
			thePlayer.str = dice.Roll4D6DropLowest();
			thePlayer.def = dice.Roll4D6DropLowest() / 3;
			thePlayer.agl = dice.Roll4D6DropLowest();
			thePlayer.vtl = dice.Roll4D6DropLowest();
			thePlayer.luk = dice.Roll4D6DropLowest() / 3;
		}
			  break;
		case 4: {
			thePlayer.str = dice.Roll1DN(18);
			thePlayer.def = dice.Roll1DN(18);
			thePlayer.agl = dice.Roll1DN(18);
			thePlayer.vtl = dice.Roll1DN(18);
			thePlayer.luk = dice.Roll1DN(18);
		}
			  break;
		default: {
			std::cout << "That was an invalid choice! Please choose again\n\t";
		}
		}
	} while ((choice < 1) || (choice > 6));
	std::this_thread::sleep_for(1s);

	system("cls");

	thePlayer.vtl *= 10;
	theMap.Draw();
	thePlayer.Print();

	system("pause");
}
