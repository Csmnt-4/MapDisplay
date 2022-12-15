#pragma once

#include <string>

enum class ModificatorEnum {
    WEAK, TOUGH, ORDINARY, HUNGRY, WOUNDED, TRICKY, BLIND, FAST, SLOW, HALFDEAD,
};
enum class MonsterRaceEnum {
    UNDEAD, SIREN, BANSHEE, GOBLIN, IMP, WYVERN,
};
enum class TypeEnum {
    UNDEAD, MONSTER, SPIRIT,
};

class Monster {
public:
    MonsterRaceEnum race;
    TypeEnum type;
    int str;            // physical attack
    int agl;            // agility/evasion/chances to not get hit/speed
    int vtl;            // vitality
    int luk;            // luck

    ModificatorEnum mod; // modifications for creature/characteristics
    int modStr = 0;
    int modAgl = 0;
    int modVtl = 0;
    int modLuk = 0;

    void Print(); //displays the monster information
};

void GenerateMonsterManually(Monster& theMonster); //assigns theMonster random stats while you get to choose the output
void GenerateMonsterRandom(Monster& theMonster); //assigns theMonster random type, re-rolls its difficulty and stats

std::string RaceToString(MonsterRaceEnum race);
std::string ModToString(ModificatorEnum mod);