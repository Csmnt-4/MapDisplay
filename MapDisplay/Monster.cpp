#include "Monster.h"

#include <iostream>
#include <string>
#include "DiceRoller.h"

void Monster::Print() {
	system("cls");
	std::cout << "Modificator: ";
	switch (mod) {
	case ModificatorEnum::WEAK:
		std::cout << "Weak" << std::endl;
		break;
	case ModificatorEnum::TOUGH:
		std::cout << "Tough" << std::endl;
		break;
	case ModificatorEnum::ORDINARY:
		std::cout << "Ordinary" << std::endl;
		break;
	case ModificatorEnum::HUNGRY:
		std::cout << "Hungry" << std::endl;
		break;
	case ModificatorEnum::WOUNDED:
		std::cout << "Wounded" << std::endl;
		break;
	case ModificatorEnum::TRICKY:
		std::cout << "Tricky" << std::endl;
		break;
	case ModificatorEnum::BLIND:
		std::cout << "Blinded" << std::endl;
		break;
	case ModificatorEnum::FAST:
		std::cout << "Fast" << std::endl;
		break;
	case ModificatorEnum::SLOW:
		std::cout << "Slow" << std::endl;
		break;
	case ModificatorEnum::HALFDEAD:
		std::cout << "Halfdead" << std::endl;
		break;
	default:
		std::cout << " -" << std::endl;
	}


	std::cout << "Race: ";
	switch (race) {
	case MonsterRaceEnum::BANSHEE:
		std::cout << "Banshee" << std::endl;
		break;
	case MonsterRaceEnum::GOBLIN:
		std::cout << "Goblin" << std::endl;
		break;
	case MonsterRaceEnum::IMP:
		std::cout << "Imp" << std::endl;
		break;
	case MonsterRaceEnum::SIREN:
		std::cout << "Siren" << std::endl;
		break;
	case MonsterRaceEnum::UNDEAD:
		std::cout << "Undead" << std::endl;
		break;
	case MonsterRaceEnum::WYVERN:
		std::cout << "Wyvern" << std::endl;
		break;
	default:
		std::cout << "Uknown character race" << std::endl;
	}

	std::cout << "Type: ";
	switch (type) {
	case TypeEnum::UNDEAD:
		std::cout << "Undead" << std::endl;
		break;
	case TypeEnum::MONSTER:
		std::cout << "Monster" << std::endl;
		break;
	case TypeEnum::SPIRIT:
		std::cout << "Spirit" << std::endl;
		break;
	default:
		std::cout << "Uknown type" << std::endl;
	}

	std::cout << "PHYS ATK: " << str << " (";
	if (modStr > 0) std::cout << "+" << modStr << ")" << std::endl;
	else std::cout << modStr << ")" << std::endl;

	std::cout << "AGL: " << agl << " (";
	if (modAgl > 0) std::cout << "+" << modAgl << ")" << std::endl;
	else std::cout << modAgl << ")" << std::endl;

	std::cout << "VIT: " << vtl << " (";
	if (modVtl > 0) std::cout << "+" << modVtl << ")" << std::endl;
	else std::cout << modVtl << ")" << std::endl;

	std::cout << "LUK: " << luk << " (";
	if (modLuk > 0) std::cout << "+" << modLuk << ")" << std::endl;
	else std::cout << modLuk << ")\n" << std::endl;

}

void GenerateMonsterRandom(Monster& theMonster) {
	DiceRoller dice;
	int choice = dice.Roll1DN(6);

	switch (choice) {
	case 1: {
		theMonster.race = MonsterRaceEnum::BANSHEE;
		theMonster.type = TypeEnum::SPIRIT;
		theMonster.str = 1;
		theMonster.agl = 8;
		theMonster.vtl = 8;
		theMonster.luk = 5;
	}
		  break;
	case 2: {
		theMonster.race = MonsterRaceEnum::GOBLIN;
		theMonster.type = TypeEnum::MONSTER;
		theMonster.str = 4;
		theMonster.agl = 12;
		theMonster.vtl = 5;
		theMonster.luk = 5;
	}
		  break;
	case 3: {
		theMonster.race = MonsterRaceEnum::IMP;
		theMonster.type = TypeEnum::SPIRIT;
		theMonster.str = 1;
		theMonster.agl = 10;
		theMonster.vtl = 5;
		theMonster.luk = 5;
	}
		  break;
	case 4: {
		theMonster.race = MonsterRaceEnum::SIREN;
		theMonster.type = TypeEnum::MONSTER;
		theMonster.str = 2;
		theMonster.agl = 8;
		theMonster.vtl = 9;
		theMonster.luk = 4;
	}
		  break;
	case 5: {
		theMonster.race = MonsterRaceEnum::UNDEAD;
		theMonster.type = TypeEnum::UNDEAD;
		theMonster.str = 5;
		theMonster.agl = 5;
		theMonster.vtl = 12;
		theMonster.luk = 0;
	}
		  break;
	case 6: {
		theMonster.race = MonsterRaceEnum::WYVERN;
		theMonster.type = TypeEnum::MONSTER;
		theMonster.str = 10;
		theMonster.agl = 9;
		theMonster.vtl = 11;
		theMonster.luk = 6;
	}
		  break;
	default:
		std::cout << "Invalid input at type choice." << std::endl;
	}

	choice = dice.Roll1DN(3);
	switch (choice) {
	case 1: {
		theMonster.str += dice.Roll1DN(3);
		theMonster.agl += dice.Roll1DN(3);
		theMonster.vtl += dice.Roll1DN(3);
	}
		  break;
	case 2: {
		theMonster.str += dice.Roll1DN(4);
		theMonster.agl += dice.Roll1DN(4);
		theMonster.vtl += dice.Roll1DN(4);
	}
		  break;
	case 3: {
		theMonster.str += dice.Roll1DN(3) - dice.Roll1DN(3);
		theMonster.agl += dice.Roll1DN(3) - dice.Roll1DN(3);
		theMonster.vtl += dice.Roll1DN(3) - dice.Roll1DN(3);
	}
		  break;
	default: {
		std::cout << "Invalid input at difficulty choice." << std::endl;
	}
	}

	choice = dice.Roll1DN(10);

	switch (choice) {
	case 1: {
		theMonster.mod = ModificatorEnum::ORDINARY;
	}
		  break;
	case 2: {
		theMonster.mod = ModificatorEnum::WEAK;
		theMonster.modAgl = -dice.Roll1DN(3);
		theMonster.modStr = -dice.Roll1DN(3);
	}
		  break;
	case 3: {
		theMonster.mod = ModificatorEnum::TOUGH;
		theMonster.modVtl = dice.Roll1DN(3);
		theMonster.modAgl = -dice.Roll1DN(3);
	}
		  break;
	case 4: {
		theMonster.mod = ModificatorEnum::HUNGRY;
		theMonster.modStr = dice.Roll1DN(3);
		theMonster.modAgl = dice.Roll1DN(3);
		theMonster.modVtl = -dice.Roll1DN(3);
	}
		  break;
	case 5: {
		theMonster.mod = ModificatorEnum::WOUNDED;
		theMonster.modStr = -dice.Roll1DN(2);
		theMonster.modAgl = -dice.Roll1DN(3);
		theMonster.modVtl = -theMonster.vtl / 4;
	}
		  break;
	case 6: {
		theMonster.mod = ModificatorEnum::TRICKY;
		theMonster.modLuk = dice.Roll1DN(3);
		theMonster.modAgl = dice.Roll1DN(4);
		theMonster.modVtl = -dice.Roll1DN(2);
	}
		  break;
	case 7: {
		theMonster.mod = ModificatorEnum::BLIND;
		theMonster.modLuk = dice.Roll1DN(2);
		theMonster.modVtl = theMonster.modVtl * 3 / 4;
	}
		  break;
	case 8: {
		theMonster.mod = ModificatorEnum::FAST;
		theMonster.modLuk = dice.Roll1DN(3);
		theMonster.modAgl = dice.Roll1DN(8) - dice.Roll1DN(4);
	}
		  break;
	case 9: {
		theMonster.mod = ModificatorEnum::SLOW;
		theMonster.modLuk = -dice.Roll1DN(2);
		theMonster.modAgl = -dice.Roll1DN(4);
	}
		  break;
	case 10: {
		theMonster.mod = ModificatorEnum::HALFDEAD;
		theMonster.modLuk = dice.Roll1DN(3);
		theMonster.modAgl = -dice.Roll1DN(4);
		theMonster.modVtl = -theMonster.vtl / 2;
	}
		   break;
	default: {
		theMonster.mod = ModificatorEnum::BLIND;
		theMonster.modLuk = dice.Roll1DN(3) + dice.Roll1DN(3);
		theMonster.modVtl = -dice.Roll1DN(3);
	}
	}
}

void GenerateMonsterManually(Monster& theMonster) {
	DiceRoller dice;

	int choice;
	std::string input;
	system("cls");
	std::cout << "What creature do thee wish to summon?" << std::endl;
	std::cout << "Please enter the # of your choice:" << std::endl;
	std::cout << "1) Banshee" << std::endl;
	std::cout << "2) Goblin" << std::endl;
	std::cout << "3) Imp" << std::endl;
	std::cout << "4) Syren" << std::endl;
	std::cout << "5) Undead" << std::endl;
	std::cout << "6) Wyvern" << std::endl;

	do {
		std::cin >> choice;
		switch (choice) {
		case 1: {
			theMonster.race = MonsterRaceEnum::BANSHEE;
			theMonster.type = TypeEnum::SPIRIT;
			theMonster.str = 1;
			theMonster.agl = 8;
			theMonster.vtl = 8;
			theMonster.luk = 5;
		}
			  break;
		case 2: {
			theMonster.race = MonsterRaceEnum::GOBLIN;
			theMonster.type = TypeEnum::MONSTER;
			theMonster.str = 4;
			theMonster.agl = 12;
			theMonster.vtl = 5;
			theMonster.luk = 5;
		}
			  break;
		case 3: {
			theMonster.race = MonsterRaceEnum::IMP;
			theMonster.type = TypeEnum::SPIRIT;
			theMonster.str = 1;
			theMonster.agl = 10;
			theMonster.vtl = 5;
			theMonster.luk = 5;
		}
			  break;
		case 4: {
			theMonster.race = MonsterRaceEnum::SIREN;
			theMonster.type = TypeEnum::MONSTER;
			theMonster.str = 2;
			theMonster.agl = 8;
			theMonster.vtl = 9;
			theMonster.luk = 4;
		}
			  break;
		case 5: {
			theMonster.race = MonsterRaceEnum::UNDEAD;
			theMonster.type = TypeEnum::UNDEAD;
			theMonster.str = 5;
			theMonster.agl = 5;
			theMonster.vtl = 12;
			theMonster.luk = 0;
		}
			  break;
		case 6: {
			theMonster.race = MonsterRaceEnum::WYVERN;
			theMonster.type = TypeEnum::MONSTER;
			theMonster.str = 10;
			theMonster.agl = 9;
			theMonster.vtl = 11;
			theMonster.luk = 6;
		}
			  break;
		default:
			std::cout << "That was an invalid choice! Repeat the input." << std::endl;
		}
	} while ((choice < 1) || (choice > 6));

	std::cout << "\nDo you wish to enhance your creature?" << std::endl;
	std::cout << "Please enter the # of your choice:" << std::endl;
	std::cout << "1) Make it a little stronger\t\t\t- add 1D3" << std::endl;
	std::cout << "2) I want a challange\t\t\t\t- add 1D4" << std::endl;
	std::cout << "3) Make it... different, but normal\t\t- add 1D3 and substract 1D3" << std::endl;
	std::cout << "4) Leave it as it is" << std::endl;

	std::cin >> choice;
	switch (choice) {
	case 1: {
		theMonster.str += dice.Roll1DN(3);
		theMonster.agl += dice.Roll1DN(3);
		theMonster.vtl += dice.Roll1DN(3);
	}
		  break;
	case 2: {
		theMonster.str += dice.Roll1DN(4);
		theMonster.agl += dice.Roll1DN(4);
		theMonster.vtl += dice.Roll1DN(4);
	}
		  break;
	case 3: {
		theMonster.str += dice.Roll1DN(3) - dice.Roll1DN(3);
		theMonster.agl += dice.Roll1DN(3) - dice.Roll1DN(3);
		theMonster.vtl += dice.Roll1DN(3) - dice.Roll1DN(3);
	}
		  break;
	default: {
		std::cout << "That was an invalid choice! The stats are left \"as is\"" << std::endl;
	}
	}

	std::getline(std::cin, input); // either of those lines can prevent the program from accepting the
	//	std::cin.ignore(INT_MAX, '\n');	 // previous input as a new one and thus "skipping" over the next 'getLine'

	std::cout << "\nDo you wish to set modification manually (Y/N)?" << std::endl;
	std::getline(std::cin, input);
	if ((input == "Y") || (input == "y") || (input == "Yes") || (input == "yes")) {
		std::cout << "\nPlease enter the # of your choice:" << std::endl;
		std::cout << "1) Ordinary" << std::endl;
		std::cout << "2) Weak" << std::endl;
		std::cout << "3) Tough" << std::endl;
		std::cout << "4) Hungry" << std::endl;
		std::cout << "5) Wounded" << std::endl;
		std::cout << "6) Tricky" << std::endl;
		std::cout << "7) Blind" << std::endl;
		std::cout << "8) Fast" << std::endl;
		std::cout << "9) Slow" << std::endl;
		std::cout << "10) Halfdead" << std::endl;
		std::cin >> choice;
	}
	else {
		choice = dice.Roll1DN(10);
	}
	switch (choice) {
	case 1: {
		theMonster.mod = ModificatorEnum::ORDINARY;
	}
		  break;
	case 2: {
		theMonster.mod = ModificatorEnum::WEAK;
		theMonster.modAgl = -dice.Roll1DN(3);
		theMonster.modStr = -dice.Roll1DN(3);
	}
		  break;
	case 3: {
		theMonster.mod = ModificatorEnum::TOUGH;
		theMonster.modVtl = dice.Roll1DN(3);
		theMonster.modAgl = -dice.Roll1DN(3);
	}
		  break;
	case 4: {
		theMonster.mod = ModificatorEnum::HUNGRY;
		theMonster.modStr = dice.Roll1DN(3);
		theMonster.modAgl = dice.Roll1DN(3);
		theMonster.modVtl = -dice.Roll1DN(3);
	}
		  break;
	case 5: {
		theMonster.mod = ModificatorEnum::WOUNDED;
		theMonster.modStr = -dice.Roll1DN(2);
		theMonster.modAgl = -dice.Roll1DN(3);
		theMonster.modVtl = -theMonster.vtl / 4;
	}
		  break;
	case 6: {
		theMonster.mod = ModificatorEnum::TRICKY;
		theMonster.modLuk = dice.Roll1DN(3);
		theMonster.modAgl = dice.Roll1DN(4);
		theMonster.modVtl = -dice.Roll1DN(2);
	}
		  break;
	case 7: {
		theMonster.mod = ModificatorEnum::BLIND;
		theMonster.modLuk = dice.Roll1DN(2);
		theMonster.modVtl = theMonster.modVtl * 3 / 4;
	}
		  break;
	case 8: {
		theMonster.mod = ModificatorEnum::FAST;
		theMonster.modLuk = dice.Roll1DN(3);
		theMonster.modAgl = dice.Roll1DN(8) - dice.Roll1DN(4);
	}
		  break;
	case 9: {
		theMonster.mod = ModificatorEnum::SLOW;
		theMonster.modLuk = -dice.Roll1DN(2);
		theMonster.modAgl = -dice.Roll1DN(4);
	}
		  break;
	case 10: {
		theMonster.mod = ModificatorEnum::HALFDEAD;
		theMonster.modLuk = dice.Roll1DN(3);
		theMonster.modAgl = -dice.Roll1DN(4);
		theMonster.modVtl = -theMonster.vtl / 2;
	}
		   break;
	default: {
		std::cout << "That was an invalid choice! You are now a khajiit. May the spirits guide you!" << std::endl;
		theMonster.mod = ModificatorEnum::BLIND;
		theMonster.modLuk = dice.Roll1DN(3) + dice.Roll1DN(3);
		theMonster.modVtl = -dice.Roll1DN(3);
	}
	}
}

std::string RaceToString(MonsterRaceEnum race) {
	switch (race) {
	case MonsterRaceEnum::UNDEAD: {
		return "Undead";
		break;
	}
	case MonsterRaceEnum::SIREN: {
		return "Siren";
		break;
	}
	case MonsterRaceEnum::BANSHEE: {
		return "Banshee";
		break;
	}
	case MonsterRaceEnum::GOBLIN: {
		return "Goblin";
		break;
	}
	case MonsterRaceEnum::IMP: {
		return "Imp";
		break;
	}
	case MonsterRaceEnum::WYVERN: {
		return "Wyvern";
		break;
	}
	default: {
		throw std::invalid_argument("Unknown Monster");
		break;
	}
	}
}

std::string ModToString(ModificatorEnum mod) {
	switch (mod) {
	case ModificatorEnum::BLIND: {
		return "Undead";
		break;
	}
	case ModificatorEnum::FAST: {
		return "Fast";
		break;
	}
	case ModificatorEnum::HALFDEAD: {
		return "Half-dead";
		break;
	}
	case ModificatorEnum::HUNGRY: {
		return "Hungry";
		break;
	}
	case ModificatorEnum::ORDINARY: {
		return "Ordinary";
		break;
	}
	case ModificatorEnum::SLOW: {
		return "Slow";
		break;
	}
	case ModificatorEnum::TOUGH: {
		return "Tough";
		break;
	}
	case ModificatorEnum::TRICKY: {
		return "Tricky";
		break;
	}
	case ModificatorEnum::WEAK: {
		return "Weak";
		break;
	}
	case ModificatorEnum::WOUNDED: {
		return "Wounded";
		break;
	}
	default: {
		throw std::invalid_argument("Unknown Modification");
		break;
	}
	}
}