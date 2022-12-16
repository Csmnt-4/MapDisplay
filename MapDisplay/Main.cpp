#include <iostream>
#include <conio.h> //for kbhit
#include <chrono>
#include <thread>

#include "Globals.h"
#include "Player.h"
#include "Seller.h"

using namespace std::literals::chrono_literals;

int main()
{
	Seller seller;
	bool done = false;
	bool update = true;

	bool creation = true;
	bool fight = false;
	bool shop = false;
	bool quest = false;
	bool stats = false;

	while (!done)
	{
		if (creation)
		{
			thePlayer.CreateCharacter();
			creation = false;
		}

		if (fight)
		{
			if (fightObj.FightLoop() == false)
			{
				done = true; //Game over
				break;
			}
			fight = false;
		}

		if (shop)
		{
			seller.Talk();

			std::this_thread::sleep_for(1s);
			shop = false;
			update = true;
		}

		if (update)
		{
			system("cls");
			theMap.Draw();
			update = false;
		}

		if (stats)
		{
			thePlayer.Print();
			stats = false;
		}

		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case 27:               // press ESC to exit
				done = true;
				break;
			case 'w':				//move the player UP
				//is the tile above us on the map
				if (thePlayer.y > 0)
				{
					//is the tile above us floor?
					if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y - 1] == 0)
					{
						thePlayer.y -= 1;
						update = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y - 1] == 4)
					{
						thePlayer.y -= 1;
						update = true;
						theMap.currentFloorNumber++;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y - 1] == 5)
					{
						thePlayer.y -= 1;
						update = true;
						theMap.currentFloorNumber--;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y - 1] == 8)
					{
						thePlayer.y -= 1;
						fight = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y - 1] == 6)
					{
						shop = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y - 1] == 7)
					{
						if (thePlayer.kills >= 5)
						{
							thePlayer.y -= 1;
							std::cout << "\n\tYou notice that something.... happened.\n\t" << thePlayer.name << " stops and listens to the suuroundings..";
							theMap.NextMap();
							seller.Refill();
							std::this_thread::sleep_for(4s);
							update = true;
						}
						else {
							std::cout << "\t\nThe monster on the other levels are screaming too loud for anything to happen";
						}
					}
				}
				break;
			case 's':				//move the player DOWN
				//is the tile below us on the map
				if (thePlayer.y < theMap.height - 1)
				{
					//is the tile below us floor?
					if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y + 1] == 0)
					{
						thePlayer.y += 1;
						update = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y + 1] == 4)
					{
						thePlayer.y += 1;
						update = true;
						theMap.currentFloorNumber++;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y + 1] == 5)
					{
						thePlayer.y += 1;
						update = true;
						theMap.currentFloorNumber--;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y + 1] == 8)
					{
						thePlayer.y += 1;
						fight = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y + 1] == 6)
					{
						shop = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x][thePlayer.y + 1] == 7)
					{
						if (thePlayer.kills >= 5)
						{
							thePlayer.y += 1;
							std::cout << "\n\tYou notice that something.... happened.\n\t" << thePlayer.name << " stops and listens to the suuroundings..";
							theMap.NextMap();
							seller.Refill();
							std::this_thread::sleep_for(4s);
							update = true;
						}
						else {
							std::cout << "\t\nThe monsters on the other levels are screaming too loud for anything to happen";
						}
					}
				}
				break;
			case 'a':				//move the player LEFT
				//is the tile beside us on the map
				if (thePlayer.x > 0)
				{
					//is the tile bside us floor?
					if (theMap.map[theMap.currentFloorNumber][thePlayer.x - 1][thePlayer.y] == 0)
					{
						thePlayer.x -= 1;
						update = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x - 1][thePlayer.y] == 4)
					{
						thePlayer.x -= 1;
						update = true;
						theMap.currentFloorNumber++;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x - 1][thePlayer.y] == 5)
					{
						thePlayer.x -= 1;
						update = true;
						theMap.currentFloorNumber--;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x - 1][thePlayer.y] == 8)
					{
						thePlayer.x -= 1;
						fight = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x - 1][thePlayer.y] == 6)
					{
						shop = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x - 1][thePlayer.y] == 7)
					{
						if (thePlayer.kills >= 5)
						{
							thePlayer.x -= 1;
							std::cout << "\n\tYou notice that something.... happened.\n\t" << thePlayer.name << " stops and listens to the suuroundings..";
							theMap.NextMap();
							seller.Refill();
							std::this_thread::sleep_for(4s);
							update = true;
						}
						else {
							std::cout << "\t\nThe monsters on the other levels are screaming too loud for anything to happen";
						}
					}
				}
				break;
			case 'd':				//move the player RIGHT
				//is the tile beside us on the map
				if (thePlayer.x < theMap.width - 1)
				{
					//is the tile beside us floor?
					if (theMap.map[theMap.currentFloorNumber][thePlayer.x + 1][thePlayer.y] == 0)
					{
						thePlayer.x += 1;
						update = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x + 1][thePlayer.y] == 4)
					{
						thePlayer.x += 1;
						update = true;
						theMap.currentFloorNumber++;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x + 1][thePlayer.y] == 5)
					{
						thePlayer.x += 1;
						update = true;
						theMap.currentFloorNumber--;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x + 1][thePlayer.y] == 8)
					{
						thePlayer.x += 1;
						fight = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x + 1][thePlayer.y] == 6)
					{
						shop = true;
					}
					else if (theMap.map[theMap.currentFloorNumber][thePlayer.x + 1][thePlayer.y] == 7)
					{
						if (thePlayer.kills >= 5)
						{
							thePlayer.x += 1;
							std::cout << "\n\tYou notice that something.... happened.\n\t" << thePlayer.name << " stops and listens to the suuroundings..";
							theMap.NextMap();
							seller.Refill();
							std::this_thread::sleep_for(4s);
							update = true;
						}
						else {
							std::cout << "\t\nThe monsters on the other levels are screaming too loud for anything to happen";
						}
					}
				}
				break;
			case 'i':
			{
				update = true;
				stats = true;
			}
			}
		}
	}
	return 0;
}

