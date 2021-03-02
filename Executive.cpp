/**
*	@author
*	@date
*	@file
*	@brief
*/
#include "Board.h"
#include "Executive.h"
#include "Ships.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
Executive::Executive()
{
	p1Carrier.buildShip(6);
	p2Carrier.buildShip(6);
	p1BattleShip.buildShip(5);
	p2BattleShip.buildShip(5);
	p1Destroyer.buildShip(4);
	p2Destroyer.buildShip(4);
	p1Cruiser.buildShip(3);
	p2Cruiser.buildShip(3);
	p1Patrol.buildShip(2);
	p2Patrol.buildShip(2);
	p1Sub.buildShip(1);
	p2Sub.buildShip(1);
}

void Executive::run()
{
	PrintMenu();
	Game();
}





void Executive::PrintMenu()
{
	bool loop = true;
	int selection = 0;
	cout << "  WELCOME TO" << endl;
	cout << " //BATTLESHIP//" << endl << endl << endl;
	while (loop)
	{
		cout << endl << "Enter in number to navigate menu" << endl;
		cout << "1: Play a Friend" << endl;
		cout << "2: Play Against Computer" << endl;
		cout << "3: How to Play" << endl;
		cin >> selection;

		//handles bad input
		while (cin.fail() || selection < 1 || selection > 3)
		{
			cout << "Not a valid choice, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> selection;
		}

		switch (selection)
		{
		case 1:
			loop = false;
			break;
		case 2:
			selectDifficulty();
			loop = false;
			break;
		case 3:
			cout << "BASIC RULES" << endl << endl;
			cout << "The goal of the game is to eliminate all of your opponent's ships ";
			cout << "by selecting spots on the game board to see if you hit or miss." << endl;
			cout << "The game is over when one player loses all of their ships." << endl << endl;
			cout << "At the beginning of the game, each player will set up their boats on a 10x10 grid simulating a board." << endl;
			cout << "Do NOT HIT the same coordinates more than one time when picking where to hit an enemy boat." << endl;
			cout << "You will have the choice between playing with 1 to 6 ships that you will place on the board:" << endl << endl;
			cout << "Games with 1 ship: " << endl << "Sub: (1x1)" << endl << endl;
			cout << "2 ships: " << endl << "Sub: (1x1), Patrol Boat: (1x2)" << endl << endl;
			cout << "3 ships: " << endl << "Sub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3)" << endl << endl;
			cout << "4 ships: " << endl << "Sub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4)" << endl << endl;
			cout << "5 ships: " << endl << "Sub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4), Battleship: (1x5)" << endl << endl;
			cout << "6 ships: " << endl << "Sub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4), ";
			cout << "Battleship: (1x5), Carrier: (1x6)" << endl << endl;
			cout << "On the board, there is a few symbols that represent ships, hits, misses, and the board itself:" << endl << endl;
			cout << "'.' = PORTION OF BOARD NOT INTERACTED WITH, 'H'= HIT, 'M' = MISS" << endl;
			cout << "'S' = SUB, 'P' = PATROL BOAT, 'c' = CRUISER, 'D' = DESTROYER, 'B' = BATTLESHIP, 'C' = CARRIER" << endl << endl;


			break;
		default:
			cout << selection << "Not a valid choice, try again." << endl;
		}
	}
}

void Executive::Game()
{
	int row;
	char column;
	int vert;
	bool destroyedbeforesub1 = false;
	bool destroyedbeforesub2 = false;
	bool destroyedbeforepatrol1 = false;
	bool destroyedbeforepatrol2 = false;
	bool destroyedbeforecruiser1 = false;
	bool destroyedbeforecruiser2 = false;
	bool destroyedbeforedestroyer1 = false;
	bool destroyedbeforedestroyer2 = false;
	bool destroyedbeforebattleship1 = false;
	bool destroyedbeforebattleship2 = false;
	bool destroyedbeforecarrier1 = false;
	bool destroyedbeforecarrier2 = false;


	cout << "Enter the number of ships you would like to play with, up to a total of 6." << endl;
	cin >> numberOfShips;
	cout << "IF PLAYING AGAINST A HUMAN, HIDE THE SCREEN SO ONLY ONE PLAYER CAN SEE IT" << endl;
	cout << "PLAYER 1" << endl;
	//placeships
	placeShips(1);
	cout << "SWITCH PLAYERS" << endl;
	placeShips(2);




	cout << "Great, both players' boats have now been placed on the board. Now, it is time to attack the enemy!";
	cout << endl << endl;

	bool winner = false;
	int turn = 1;
	int totalDestroyed1 = 0;
	int totalDestroyed2 = 0;

	std::string ready = "";
	do
	{
		cout << "Are you ready to begin the game? (y/n)";
		cout << endl;
		cin >> ready;

	} while (ready != "yes" && ready != "y");

	cout << endl << endl;

	while (winner == false)
	{
		cout << "PLAYER 1 TURN [" << turn << "]";
		cout << endl << endl;

		cout << "YOUR SHIPS:";
		cout << endl << endl;

		p1Ships.Display();

		cout << endl << endl;

		cout << "ENEMY SHIPS:";
		cout << endl << endl;

		p1HitOrMiss.Display();
		cout << endl << endl;
		cout << "Enter in the position of where you would like to attack." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		string spot = p2Ships.checkHit(row, trueColumn);
		if (spot != ".")
		{
			cout << "HIT!";
			cout << endl;
			if (spot == "S")
			{
				p2Sub.hit();
				if (p2Sub.isDestroyed() == true)
				{
					if (destroyedbeforesub2 == false)
					{
						destroyedbeforesub2 = true;
						totalDestroyed1++;
						cout << "YOU SUNK A SUBMARINE!";
						cout << endl;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}
				}
			}
			if (spot == "P")
			{
				p2Patrol.hit();
				if (p2Patrol.isDestroyed() == true)
				{
					if (destroyedbeforepatrol2 == false)
					{
						destroyedbeforepatrol2 = true;
						totalDestroyed1++;
						cout << "YOU SUNK A PATROL BOAT!";
						cout << endl;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}
				}
			}
			if (spot == "c")
			{
				p2Cruiser.hit();
				if (p2Cruiser.isDestroyed() == true)
				{
					if (destroyedbeforecruiser2 == false)
					{

						totalDestroyed1++;
						cout << "YOU SUNK A CRUISER!";
						cout << endl;
						destroyedbeforecruiser2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "D")
			{
				p2Destroyer.hit();
				if (p2Destroyer.isDestroyed() == true)
				{
					if (destroyedbeforedestroyer2 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A DESTROYER!";
						cout << endl;
						destroyedbeforedestroyer2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "B")
			{
				p2BattleShip.hit();
				if (p2BattleShip.isDestroyed() == true)
				{
					if (destroyedbeforebattleship2 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A BATTLESHIP!";
						cout << endl;
						destroyedbeforebattleship2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}
				}
			}
			if (spot == "C")
			{
				p2Carrier.hit();
				if (p2Carrier.isDestroyed() == true)
				{
					if (destroyedbeforecarrier2 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A CARRIER!";
						cout << endl;
						destroyedbeforecarrier2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			p1HitOrMiss.update(row, trueColumn, "H");
		}
		else
		{
			cout << "MISS!";
			cout << endl;
			p1HitOrMiss.update(row, trueColumn, "M");
		}

		if (totalDestroyed1 == numberOfShips)
		{
			winner = true;
			break;
		}

		cout << "PLAYER 2 TURN [" << turn << "]";
		cout << endl;
		//std::this_thread::sleep_for(7s);

		cout << "YOUR SHIPS:";
		cout << endl << endl;

		p2Ships.Display();

		cout << endl << endl;

		cout << "ENEMY SHIPS:";
		cout << endl << endl;

		p2HitOrMiss.Display();
		cout << endl << endl;
		cout << "Enter in the position of where you would like to attack." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
		trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		spot = p1Ships.checkHit(row, trueColumn);
		if (spot != ".")
		{
			cout << "HIT!";
			cout << endl;
			if (spot == "S")
			{
				p1Sub.hit();
				if (p1Sub.isDestroyed() == true)
				{
					if (destroyedbeforesub1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A SUBMARINE!";
						cout << endl;
						destroyedbeforesub1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "P")
			{
				p1Patrol.hit();
				if (p1Patrol.isDestroyed() == true)
				{
					if (destroyedbeforepatrol1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A PATROL BOAT!";
						cout << endl;
						destroyedbeforepatrol1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "c")
			{
				p1Cruiser.hit();
				if (p1Cruiser.isDestroyed() == true)
				{
					if (destroyedbeforecruiser1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A CRUISER!";
						cout << endl;
						destroyedbeforecruiser1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "D")
			{
				p1Destroyer.hit();
				if (p1Destroyer.isDestroyed() == true)
				{
					if (destroyedbeforedestroyer1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A DESTROYER!";
						cout << endl;
						destroyedbeforedestroyer1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "B")
			{
				p1BattleShip.hit();
				if (p1BattleShip.isDestroyed() == true)
				{
					if (destroyedbeforebattleship1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A BATTLESHIP!";
						cout << endl;
						destroyedbeforebattleship1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "C")
			{
				p1Carrier.hit();
				if (p1Carrier.isDestroyed() == true)
				{
					if (destroyedbeforecarrier1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A CARRIER!";
						cout << endl;
						destroyedbeforecarrier1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			p2HitOrMiss.update(row, trueColumn, "H");
		}
		else
		{
			cout << "MISS!";
			cout << endl;
			p2HitOrMiss.update(row, trueColumn, "M");
		}

		if (totalDestroyed2 == numberOfShips)
		{
			winner = true;
			break;
		}
		//std::this_thread::sleep_for(7s);
		turn++;
	}

	if (totalDestroyed1 == numberOfShips)
	{
		cout << "PLAYER 2 LOST!";
		cout << endl;

		cout << "PLAYER 1 WON!";
		cout << endl;
	}
	else
	{
		cout << "PLAYER 1 LOST!";
		cout << endl;

		cout << "PLAYER 2 WON!";
		cout << endl;
	}
}



void Executive::placeShips(int player){//wasn't able to get pointers to work for the playerBoards
	int row;
	char column;
	int vert;
	for (int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place your 1x" << i + 1 << " ship." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		cout << "Enter a 1 if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;
		while (cin.fail() || vert > 1 || vert < 0)
		{
			cout << "Not a valid orientation, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> vert;
		}
		if(player==1){
			if ((p1Ships.addShip(row, trueColumn, vert, i + 1, i)) == false)
			{
				cout << "SHIP WAS UNABLE TO BE ADDED, TRY AGAIN." << endl;
				i--;
			}
			p1Ships.Display();
		}else if(player==2){
			if ((p2Ships.addShip(row, trueColumn, vert, i + 1, i)) == false)
			{
				cout << "SHIP WAS UNABLE TO BE ADDED, TRY AGAIN." << endl;
				i--;
			}
			p2Ships.Display();
		}
		//std::this_thread::sleep_for(7s);
	}
	p1Ships.clearScreen();//doesn't matter what ship this is called from
}

void Executive::selectDifficulty(){
	cout << "Select a difficulty for the computer player:" << endl;
	cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hard" << endl;
	int difficulty = 0;
	cin >> difficulty;
	//handles bad input
	while (cin.fail() || difficulty < 1 || difficulty > 3)
	{
		cout << "Not a valid choice, try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> difficulty;
	}
	switch(difficulty){
		case 1:
			cout << "Playing easy" << endl;
			break;
		case 2:
			cout << "Playing medium" << endl;
			break;
		case 3:
			break;
			cout << "Playing Hard" << endl;
		default:
			cout << "Not a valid choice, try again." << endl;
	}
}

Executive::~Executive()
{

}
