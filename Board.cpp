

/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				board.cpp
*/
#include "Board.h"

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: Allows boards to be constructed
**************************************************************/
Board::Board():
m_xSize(0),
m_ySize(0)
{
	
	for (int rowNum = 0; rowNum < m_xSize; rowNum++)
	{
		for (int colNum = 0; colNum < m_ySize; colNum++)
		{
			Cell tempCell('0','?', 0, true);
			m_board[rowNum][colNum] = tempCell;

		}
	}
}

/**************************************************************
*   Entry:  xSize, ySize
*
*    Exit:  none
*
* Purpose: allows a board to be created with an sSize and Ysize
**************************************************************/
Board::Board(int xSize, int ySize):
m_xSize(xSize),
m_ySize(ySize),
m_board(xSize, ySize)
{
	m_board.setRow(xSize);
	m_board.setColumn(ySize);

	//populates the board with default cells
	for (int rowNum = 0; rowNum < xSize; rowNum++)
	{
		for (int colNum = 0; colNum < ySize; colNum++)
		{
			Cell tempCell('0','?', 0, true);
			m_board[rowNum][colNum] = tempCell;

		}
	}

}

//sets the size of the board
/**************************************************************
*   Entry:  xSize, ySize
*
*    Exit:  none
*
* Purpose: allows the size of the board to be changed
**************************************************************/
void Board::setSize(int xSize, int ySize)
{
		m_xSize = xSize;
		m_ySize = ySize;

		m_board.setRow(xSize);
		m_board.setColumn(ySize);

		//populates the board with default cells
		for (int rowNum = 0; rowNum < xSize; rowNum++)
		{
			for (int colNum = 0; colNum < ySize; colNum++)
			{
				Cell tempCell('0', '?', 0, true);
				m_board[rowNum][colNum] = tempCell;

			}
		}
}

/**************************************************************
*   Entry:  row, col, the new value
*
*    Exit:  none
*
* Purpose: Allows the user to set a value to a certin character to the given cordinates
**************************************************************/
void Board::setPosition(int row, int col, char theValue)
{
	if (theValue == 'm')
	{
		m_board[row][col].changeValue('m');
	}
	else
	{
		m_board[row][col].changeValue(theValue);//may need to subtract 48
	}
}

/**************************************************************
*   Entry:  row, col

*    Exit:  a cell
*
* Purpose: returns the value in cell at the given position 
**************************************************************/
Cell Board::getPosition(int row, int col)
{
	return m_board[row][col];
}

//called after mines are placed
void Board::updateAdjacentMines()
{
	
	for (int rowNum = 0; rowNum < m_xSize; rowNum++)
	{
		for (int colNum = 0; colNum < m_ySize; colNum++)
		{
			//Cell tempCell('?', 0, true);
			if (m_board[rowNum][colNum].getValue() == MINE)
			{

				checkAndUpdateNumOfAdjacentMines(rowNum, colNum);
				//add 1 to adjacent mine value to all sques next to this one that are not mine
			}
		}
	}
}

/**************************************************************
*   Entry:  the x cordiante, y cordinate

*    Exit:  none
*
* Purpose: checks all the cells that touch this cell and update this cell's value for
		the number of mines that it touches
**************************************************************/
void Board::checkAndUpdateNumOfAdjacentMines(int xCordinate, int yCordinate)//the x y cordinate of the mine
{
	//steps through all the locationg adjacent to the origin (including diaginals) and if that spot isn't a mine
	//then it gets 1 added to its 
	for (int y = 1; y >= -1; y--)
	{
		for (int x = -1; x <= 1; x++)
		{

			if (xCordinate + x < 0 || yCordinate + y < 0 || yCordinate + y > m_ySize - 1 || xCordinate + x >= m_xSize)
			{

			}
			else
			{
				if (m_board[xCordinate + x][yCordinate + y].getValue() != MINE)
				{
					
						m_board[xCordinate + x][yCordinate + y].changeNumOfAdjacentMines(m_board[xCordinate + x][yCordinate + y].getNumOfAdjacentMines() + 1);

						m_board[xCordinate + x][yCordinate + y].changeValue(m_board[xCordinate + x][yCordinate + y].getNumOfAdjacentMines() + 48);
				}
			}
		}
	}
}


/**************************************************************
*   Entry: the row, the col, the new display character

*    Exit:  none
*
* Purpose: Allows the user to change the display character of the cell specified
**************************************************************/
void Board::setDisplayChar(int row, int col, char theCharacter)
{
	m_board[row][col].changeDisplayChar(theCharacter);
}


/**************************************************************
*   Entry: the row, the col

*    Exit:  true or false (true = good), (false = dead)
*
* Purpose: selects a square, returns true if your live, returns false if your dead,
		if you live it updates the board as well
**************************************************************/
bool Board::select(int row, int col)
{
	//checks to see if the guess is a mine
	if (m_board[row][col].getValue() == 'm')
	{
		return false; //false means your dead
	}
	else
	{
		m_board[row][col].changeDisplayChar(	m_board[row][col].getValue()	);

		//loop that checks all the surounding squares
		for (int y = 1; y >= -1; y--)
		{
			for (int x = -1; x <= 1; x++)
			{
				//makes sure it dosn't check itself
				if (row + x < 0 || col + y < 0 || col + y > m_ySize - 1 || row + x >= m_xSize)
				{
					//return true;
				}
				else
				{
					//checks if this square has no mines touching it and adjacent mines are 
					if (m_board[row][col].getValue() == '0' && m_board[row + x][col + y].getDisplayChar() == '?')
					{
						m_board[row + x][col + y].changeDisplayChar(m_board[row + x][col + y].getValue());
						select(row + x, col + y);
					}
				}
			}
		}
	}
	return true;
}