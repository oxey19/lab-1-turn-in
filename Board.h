

/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				board.h
*/
#define MINE 'm'

#include "Array2D.h"
#include "Cell.h"


/************************************************************************
* Class: Board
*
* Constructors:
*	Board()
*		Allows boards to be constructed
	Board(int xSize, int ySize)
		allows a board to be created with an sSize and Ysize
*
* Mutators:
*	void setSize(int xSize, int ySize);
		allows the size of the board to be changed

	void setPosition(int row , int col, char theCharacter);
		Allows the user to set a value to a certin character to the given cordinates

	void setDisplayChar(int row, int col, char theCharacter);
		Allows the user to change the display character of the cell specified

	void updateAdjacentMines();
		Updates the Adjaecent cells to have the correct numbers as values

	bool select(int row, int col);
		selects a square, returns true if your live, returns false if your dead,
		if you live it updates the board as well
*
* Methods:
*	Cell getPosition(int row, int col);
		returns the value in cell at the given position 

	void checkAndUpdateNumOfAdjacentMines(int xCordinate, int yCordinate);
		checks all the cells that touch this cell and update this cell's value for
		the number of mines that it touches

*************************************************************************/

class Board
{
public:
	Board();
	Board(int xSize, int ySize);

	void setSize(int xSize, int ySize);

	void setPosition(int row , int col, char theCharacter);

	void setDisplayChar(int row, int col, char theCharacter);

	Cell getPosition(int row, int col);

	void updateAdjacentMines();

	bool select(int row, int col);

	

private:

	void checkAndUpdateNumOfAdjacentMines(int xCordinate, int yCordinate);

	Array2D<Cell> m_board;
	int m_xSize;
	int m_ySize;
};