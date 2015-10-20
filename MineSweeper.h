

/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				MineSweeper.h
*/
#include "Board.h"

#include <iostream>

using namespace std;


/************************************************************************
* Class: MineSweeper
*
* Constructors:
*	MineSweeper();
		Allows the user to create minesweeper objects

	MineSweeper(char dificulty);
		Allows the user to create minesweeper objects with a dificulty set

* Mutators:
*	void resetBoard(char dificulty);
		sets the size, and number of mines for the coresponding dificulty inputed

	
	void markMine(int row, int col);
		changes the display character of a mine to either ! or ?


	void setMines();
		sets all the mines to cells

	void setAlltoVisible();
		changes all the cell's to visible

	bool select(int row, int col);
		slectes the square, and then updates the surounding squares if needed
*
* Methods:
	void displayBoard(void);
		Displays the entire board to the screen

*	bool isGameWon();
		returns true if the game is won, false if it isn't

*************************************************************************/
class MineSweeper
{
public:
	MineSweeper();

	MineSweeper(char dificulty);

	void resetBoard(char dificulty);

	void displayBoard(void);

	void markMine(int row, int col);


	void setMines();

	void setAlltoVisible();

	bool select(int row, int col);

	bool isGameWon();

private:
	Board m_board;
	int m_xSize;
	int m_ySize;
	int m_totalNumofMines;

	char m_dificulty;

};