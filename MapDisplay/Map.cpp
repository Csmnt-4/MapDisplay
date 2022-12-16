#include "Globals.h"
#include "Map.h"

#include <iostream>
#include <random>
#include <fstream>


Map::Map(std::string filename)
{
	//if filename is "random", generate a random map
	if (filename == "random")
	{
		std::mt19937 rng;
		std::random_device rd;
		rng.seed(rd());
		std::uniform_int_distribution<int> randomMapDist(0, 100);
		width = 40;
		height = 20;

		for (int x = 0; x < width; ++x)
		{
			for (int y = 0; y < height; ++y)
			{
				if (randomMapDist(rng) < 10)
					map[0][x][y] = 1; //wall;
				else
					map[0][x][y] = 0;
			}
		}
	}
	else
	{//...else load filename as a map file		

		//create our file stream
		std::ifstream mapfile(filename);

		if (!mapfile.is_open())
		{
			std::cout << "Can't open map file: " << filename << std::endl;
			return;
		}

		mapfile >> width;
		mapfile >> height;

		if (width > 256 || height > 256)
		{
			std::cout << "You map file is too big, can only handle maps up to 256 x 256!" << std::endl;
			return;
		}

		for (int floor = 0; floor < 3; ++floor)
		{
			for (int y = 0; y < height; ++y)
			{
				for (int x = 0; x < width; ++x)
				{
					mapfile >> map[floor][x][y];
				}
			}
		}

	}

}

void Map::Draw()
{
	//loop over map and draw it and the player
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (x == thePlayer.x && y == thePlayer.y) thePlayer.Draw();
			else
			{
				switch (map[currentFloorNumber][x][y])
				{
				case 0: //floor
					std::cout << " ";
					break;
				case 1: //corner of a wall
					std::cout << "+";
					break;
				case 2: //vertical wall
					std::cout << "|";
					break;
				case 3: //horizontal wall
					std::cout << "-";
					break;
				case 4: //stairs going down
					std::cout << "v";
					break;
				case 5: //stairs going up
					std::cout << "^";
					break;

				case 6: //seller
					std::cout << "$";
					break;
				case 7: //quest-giver
					std::cout << "!";
					break;
				case 8: //monster 	
					std::cout << "@";
					break;
				default:
					std::cout << "?";
				}//end of switch
			}
		}
		std::cout << std::endl;
	}
}

void Map::NextMap() {
	currentMapNumber++;
	Map map("map" + std::to_string(currentMapNumber) + ".txt");
	theMap = map;
}