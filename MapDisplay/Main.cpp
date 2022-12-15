#pragma once
#include <iostream>
#include <conio.h> //for kbhit

#include "Globals.h"
#include "Player.h"

#pragma once

int main()
{
	bool done = false;
	bool update = true;

	bool creation = true;
	bool fight = false;
	bool shop = false;
	bool quest = false;

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
			update = false;
			fight = false;
		}

		if (update)
		{
			system("cls");
			theMap.Draw();
			update = false;
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
						update = true;
						fight = true;
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
						update = true;
						fight = true;
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
						update = true;
						fight = true;
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
						update = true;
						fight = true;
					}
				}
				break;
			}
		}
	}
	return 0;
}

