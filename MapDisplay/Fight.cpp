#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>

#include "Globals.h"
#include "Player.h"

#include "DiceRoller.h"

using namespace std::literals::chrono_literals;

Fight::Fight()
{}

bool Fight::AutomatedFight(Monster& monster) {
	DiceRoller dice;

	int playerHealth = thePlayer.vtl;
	int monsterHealth = monster.vtl * 10;

	int playerAttackDamage;
	int monsterAttackDamage;
	int playerChances;
	int monsterChances;

	std::cout << "\n" << ModToString(monster.mod) << " " << RaceToString(monster.race) << " appears in front of you!\n";
	std::cout << thePlayer.name << " begins their attack on " << ModToString(monster.mod) << " "
		<< RaceToString(monster.race) << "\n";

	while (monsterHealth > 0 && playerHealth > 0) {
		playerAttackDamage =
			2 * dice.Roll1DN(thePlayer.str) + dice.Roll1DN(thePlayer.modStr) + dice.Roll1DN(thePlayer.luk) + dice.Roll1DN(thePlayer.modLuk);
		monsterAttackDamage =
			2 * dice.Roll1DN(monster.str) + dice.Roll1DN(monster.modStr) + dice.Roll1DN(monster.luk) + dice.Roll1DN(monster.modLuk);

		playerChances =
			70 - (monster.agl + dice.Roll1DN(monster.modAgl) - thePlayer.agl + dice.Roll1DN(thePlayer.modAgl)) *
			(dice.Roll1DN(3) + dice.Roll1DN(3)) + dice.Roll1DN(thePlayer.luk) + dice.Roll1DN(thePlayer.modLuk);
		monsterChances =
			70 - thePlayer.agl + dice.Roll1DN(thePlayer.modAgl) - monster.agl + dice.Roll1DN(monster.modAgl) +
			dice.Roll1DN(monster.luk) + dice.Roll1DN(monster.modLuk);


		if (dice.Roll1DN(100) <= playerChances) {
			std::cout << thePlayer.name << " hits " << ModToString(monster.mod) << " "
				<< RaceToString(monster.race) << " for " << playerAttackDamage << " damage!" << std::endl;
			if (playerAttackDamage > 20)
				std::cout << "Critical hit!" << std::endl;
			monsterHealth -= playerAttackDamage;
		}
		else {
			std::cout << thePlayer.name << " misses the" << " " << RaceToString(monster.race) << std::endl;
			std::cout << "  Your chance to hit was " << playerChances << "%" << std::endl;
		}

		std::this_thread::sleep_for(1s);

		if (monsterHealth > 0) {
			if (dice.Roll1DN(100) <= monsterChances) {
				std::cout << ModToString(monster.mod) << " " << RaceToString(monster.race) << " hits " << "Player "
					<< thePlayer.name << " for " << monsterAttackDamage << " damage!" << std::endl;
				if (monsterAttackDamage > 20)
					std::cout << "Critical hit!" << std::endl;
				playerHealth -= monsterAttackDamage;
				std::cout << "  HP left: " << playerHealth << std::endl;
			}
			else {
				std::cout << ModToString(monster.mod) << " " << RaceToString(monster.race) << " misses player "
					<< thePlayer.name << std::endl;
				if (monsterChances > 0)
					std::cout << "  Their chance to hit was " << monsterChances << "%" << std::endl;
			}
		}

		std::this_thread::sleep_for(1s);
	}

	thePlayer.vtl = playerHealth;

	if (playerHealth > 0) {
		return true;
	}
	else {
		if (monsterHealth == monster.vtl * 10)
			std::cout
			<< "That was a very unlucky fight. Come have another later, when you have more agility! Or luck..."
			<< std::endl;

		return false;
	}
}

bool Fight::FightLoop()
{
	Monster creature;
	GenerateMonsterRandom(creature);

	if (AutomatedFight(creature)) {
		DiceRoller dice;
		int coins = 5 * dice.Roll1DN(creature.vtl * 2);
		thePlayer.coins += coins;

		system("cls");
		theMap.Draw();
		std::cout << "\n\t" << thePlayer.name << " won!" << std::endl;
		std::this_thread::sleep_for(250ms);

		std::cout << "\tYou find a few coins on the floor. Now you have " << thePlayer.coins << " of them!" << std::endl;
		std::this_thread::sleep_for(500ms);

		std::cout << "\tYou have " << thePlayer.vtl << " HP left." << std::endl;
		std::cout << "\tThe monster had " << creature.vtl * 10 << " HP." << std::endl;

		theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y] = 0;
		std::this_thread::sleep_for(1s);
		return true;
	}
	else {
		system("cls");
		theMap.Draw();
		std::cout << "\n\t" << ModToString(creature.mod) << " "
			<< RaceToString(creature.race) << " wins." << std::endl;
		std::this_thread::sleep_for(500ms);

		std::cout << "  They have slain " << thePlayer.name << "." << std::endl;
		std::cout << "  The monster had " << creature.vtl * 10 << " HP." << std::endl;
		std::this_thread::sleep_for(1s);
		return false;
	}
}
