

/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				MineSweeper.cpp
*/
#include <stdlib.h>
#include "MineSweeper.h"

#define BEGINER_DIFICULTY 10
#define INTERMIDIATE_DIFICULTY 16
#define EXPERT_DIFICULTY 30

#define BEGINER_DIFICULTY_NUM_MINES 10
#define INTERMEDIATE_DIFICULTY_NUM_MINES 40
#define EXPERT_DIFICULTY_NUM_MINES 100


/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: Allows the user to create minesweeper objects
**************************************************************/
MineSweeper::MineSweeper()
{
}

/**************************************************************
*   Entry:  the dificulty
*
*    Exit:  none
*
* Purpose: Allows the user to create minesweeper objects with a dificulty set
**************************************************************/
MineSweeper::MineSweeper(char dificulty) :
m_dificulty(dificulty)
{
	resetBoard(dificulty);
}

/**************************************************************
*   Entry:  the dificulty
*
*    Exit:  none
*
* Purpose: sets the size, and number of mines for the coresponding dificulty inputed
**************************************************************/
void MineSweeper::resetBoard(char dificlty)
{

	m_xSize = 0;
	m_ySize = 0;

	if (dificlty == 'b')
	{
		m_xSize = BEGINER_DIFICULTY;
		m_ySize = m_xSize;
		m_totalNumofMines = BEGINER_DIFICULTY_NUM_MINES;
	}

	else if (dificlty == 'i')
	{
		m_xSize = INTERMIDIATE_DIFICULTY;
		m_ySize = m_xSize;
		m_totalNumofMines = INTERMEDIATE_DIFICULTY_NUM_MINES;
	}

	else if (dificlty == 'e')
	{
		m_xSize = INTERMIDIATE_DIFICULTY;
		m_ySize = EXPERT_DIFICULTY;
		m_totalNumofMines = EXPERT_DIFICULTY_NUM_MINES;
	}

	m_board.setSize(m_xSize, m_ySize);
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:Displays the entire board to the screen

**************************************************************/
void MineSweeper::displayBoard(void)
{
	
	for (int i = 0; i < m_xSize; i++)
	{
		for (int idx = 0; idx < m_ySize; idx++)
		{
			cout << m_board.getPosition(i,idx) << " ";
		}
		cout << endl;
	}
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:sets all the mines to cells

**************************************************************/
void MineSweeper::setMines()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < m_totalNumofMines; i++)
	{
		x = rand() % m_xSize; 
		y = rand() % m_xSize;
		if (m_board.getPosition(x, y).getValue() != 'm')
		{
			m_board.setPosition(x, y, 'm');
		}
		else
		{
			i--;
		}

	}

	m_board.updateAdjacentMines();
}


/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose:changes all the cell's to visible
**************************************************************/
void MineSweeper::setAlltoVisible()
{
	Cell temp;

	for (int i = 0; i < m_xSize; i++)
	{
		for (int idx = 0; idx < m_ySize; idx++)
		{
			 m_board.setDisplayChar(i, idx, m_board.getPosition(i, idx).getValue());
		}
	}
}

/**************************************************************
*   Entry:  the row, the col
*
*    Exit:  true or false (true - survive) (false - dead)
*
* Purpose: slectes the square, and then updates the surounding squares if needed
**************************************************************/
bool MineSweeper::select(int row, int col)
{
	bool returnValue; //true = you live, false = your dead
	returnValue =  m_board.select(row, col);

	if (returnValue == false) 
	{
		m_board.setDisplayChar(row, col, m_board.getPosition(row, col).getValue());
	}

	return returnValue;
}

/**************************************************************
*   Entry:  the row, the col
*
*    Exit:  none
*
* Purpose: changes the display character of a mine to either ! or ?
**************************************************************/
void MineSweeper::markMine(int row, int col)
{
	if (m_board.getPosition(row, col).getDisplayChar() == '!')
	{
		m_board.setDisplayChar(row, col, '?');
	}
	else
	{
		if (m_board.getPosition(row, col).getDisplayChar() == '?')
		{
			m_board.setDisplayChar(row, col, '!');
		}
	}
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: returns true if the game is won, false if it isn't
**************************************************************/
bool MineSweeper::isGameWon()
{
	int uncovered = 0;

	for (int i = 0; i < m_xSize; i++)
	{
		for (int idx = 0; idx < m_ySize; idx++)
		{
			if (m_board.getPosition(i, idx).getDisplayChar() == '?' || m_board.getPosition(i, idx).getDisplayChar() == '!')
			{
				uncovered++;
			}
		}
	}

	if (uncovered == m_totalNumofMines)
	{
		return true;
	}
	return false;
}