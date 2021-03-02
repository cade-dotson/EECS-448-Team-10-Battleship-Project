#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Board.h"
#include "Ships.h"

class Executive
{
public:

	/// Main function that executes the PRINTMENU and GAME function
	void run();

	/// Constructor for Executive class
	/** Constructor that initializes instances for ships, for two platyers.
	 */
    Executive();

	/// Destructor for Executive class
	/// Deallocates the memory previously reserved.
    ~Executive();

private:



/// Outputs a choice for instructions for the game
/** Main Menu fuction for the Game, Show a intro screen and how to play with the rules.
	Has a loop built into it that shows the rules.
	*/
    void PrintMenu();

		//allows the player to select the difficulty of the ai, has 3 options: easy medium and hard
		void selectDifficulty();

		/*
		prompts the player1 to place their ships and adds the ships to their Board
		*/
		void placeShips(int player);



/// Main function that runs initializes the multidimensional array and guides the user through the game
/**  Function initializes integers numberOfShips, row, vert amd character column.
 *   then prompts player 1 to enter integers to first get the amount of ships max 6.
 *   then prompts player 1 to place the ship in the grid.
 * 	 then prompts player 1 to see if they want a vertical alignment for the chosen ship
 *   then loops for the amount of ships chosen and then shows the placement of ships before clearing the screen.
 *
 *   Do the same thing on loop for player 2.
 *
 *   Initializes a win counter, then uses the Board instances to execute the game where the players static
 *   ships locations are found. loops between player 1 and 2 until all ships instances of either player 1 or 2
 *   are Hit.
 */
    void Game();
	Board p1HitOrMiss;	/// Instance of board that
	Board p1Ships;
	Board p2HitOrMiss;
	Board p2Ships;


	int numberOfShips;
/** Instantiating 5 instances of ship class for each "player" Carrier,
 * Battleship, Destroyer, Cruiser, Patrol, Sub
 */

	Ships p1Carrier;
	Ships p2Carrier;
	Ships p1BattleShip;
	Ships p2BattleShip;
	Ships p1Destroyer;
	Ships p2Destroyer;
	Ships p1Cruiser;
	Ships p2Cruiser;
	Ships p1Patrol;
	Ships p2Patrol;
	Ships p1Sub;
	Ships p2Sub;
};
#endif
