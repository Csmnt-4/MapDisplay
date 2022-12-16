#pragma once

#include <string>

class Map
{
public:
	int map[3][256][256];
	int currentFloorNumber = 0;
	int width, height;
	int currentMapNumber = 1;

	Map(std::string filename); //pass "random" to create a random map
	void Draw();  //draw the map and the player
	void NextMap();
};
