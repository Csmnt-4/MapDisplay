#pragma once
#include <string>

class Player
{
public:
	std::string name = "";
	int str;            // physical attack
	int def;
	int agl;
	int vtl;
	int luk;

	int modStr;
	int modDef;
	int modAgl;
	int modVtl;
	int modLuk;

	int x, y; //player's coordinates on the map
	char sprite;

	int coins;
	int monsterHead;

	Player();
	void Draw();
	void Print();
	void CreateCharacter();
};