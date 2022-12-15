#pragma once

#include "Monster.h"

class Fight {
public:

	Fight();
	bool AutomatedFight(Monster& monster);
	bool FightLoop();
};