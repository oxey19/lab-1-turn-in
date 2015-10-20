
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				main.cpp
*/

/* Overview:
*This program will execute the game Minesweeper,
it ask for a dificulty, and 
*/

#include <iostream>
#include "MineSweeper.h"

#include <stdlib.h>
#include <time.h>

using namespace std;


//Displays the menu
void disPlayMenu()
{
	cout << "1   makes a guess" << endl
		<< "2   mark a mine" << endl;

}

int main()
{
	srand(time(NULL));

	char theDificulty;
	//loop for the the entire game
	//(so the only way to quit is typing q )
	while (true)
	{
		//displays the menu until they chose a valid option
		while (true)
		{
			//outpus the menu options
			cout << "What dificulty do you want to play? " << endl;
			cout << "b ------- beginer" << endl;
			cout << "i ------- intermidiate" << endl;
			cout << "e ------- expert" << endl;
			cout << "q --------QUIT " << endl;

			cin >> theDificulty;

			if (theDificulty == 'b' || theDificulty == 'i' || theDificulty == 'e' || 'q')
			{
				break;
			}

			cout << "You inputed an invalid number, try again" << endl;
		}

		if (theDificulty == 'q')
		{
			break;
		}

		MineSweeper game(theDificulty); //declaring game existest	
		game.displayBoard();
		cout << endl;
		game.setMines();

		//game.setAlltoVisible();
		int userXguess = 0;
		int userYguess = 0;
		char dummey;
		int choice = 0;

		//runs the game asking for guesses
		while (true)
		{
			disPlayMenu();
			cin >> choice;

			//make a guess
			if (choice == 1)
			{
				cin >> userXguess >> dummey >> userYguess;
				cout << endl;
				try
				{
					if (!game.select(userYguess, userXguess))
					{
						cout << "You lose..." << endl;
						break;
					}
				}
				catch (Exception boundException)
				{
					cout << "The cordinate entered is out of bounds" << endl;
				}
				cout << endl;
				game.displayBoard();
			}

			//mark a mine
			else if (choice == 2)
			{
				//call mark mine
				cin >> userXguess >> dummey >> userYguess;
				cout << endl;

				//swaps the guess around
				game.markMine(userYguess, userXguess);

				cout << endl;
				game.displayBoard();
			}
			else
			{
				cout << "Invalid choice" << endl;
			}

			if (game.isGameWon())
			{
				cout << "YOU WON" << endl;
				break;
			}
		}

		game.displayBoard();
	}
	return 0;
}