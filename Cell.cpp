

/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				Cell.cpp
*
*/
#include <iostream>

using namespace std;

#include "Cell.h"

/**************************************************************
*   Entry:  a value, a display character, a number of adjacent mines, if it is covered or not
*
*    Exit:  none
*
* Purpose: Allows the user to create a cell specifying a value, display hcaracter, a number 
of adjacent mines, and ifit is covered or not
**************************************************************/
Cell::Cell(char value, char displayChar, int numOfAdjacentMines, bool isCovered):
m_isCovered(isCovered),
m_numOfAdjacentMines(numOfAdjacentMines),
m_value(value),
m_displayChar(displayChar)
{
}

/**************************************************************
*   Entry:  none
*
*    Exit:  none
*
* Purpose: Allows cells to be constructed
**************************************************************/
Cell::Cell():
m_isCovered(true),
m_numOfAdjacentMines(0),
m_displayChar('?'),
m_value ( '0')
{
}

/**************************************************************
*   Entry:  number of adjacent mines
*
*    Exit:  none
*
* Purpose: llows the user to change the number of adjacent mines
**************************************************************/
void Cell::changeNumOfAdjacentMines(int numOfAdjacentMines)
{
	m_numOfAdjacentMines = numOfAdjacentMines;
}

/**************************************************************
*   Entry:  the new value for it being covered
*
*    Exit:  none
*
* Purpose: Allows the user to change weather the cell is covered or not
**************************************************************/
void Cell::changeIsCovered(bool isCovered)
{
	m_isCovered = isCovered;
}

/**************************************************************
*   Entry:  the new value
*
*    Exit:  none
*
* Purpose: Allows the user to change the value of the cell
**************************************************************/
void Cell::changeValue(char value)
{
	m_value = value;
}

/**************************************************************
*   Entry:  the new display character
*
*    Exit:  none
*
* Purpose: ALlows the user to change the character that is displayed
**************************************************************/
void Cell::changeDisplayChar(char newDisplayChar)
{
	m_displayChar = newDisplayChar;
}

/**************************************************************
*   Entry: none
*
*    Exit:  the value of the cell
*
* Purpose: returns the value of the cell
**************************************************************/
char Cell::getValue()
{
	return m_value;
}

/**************************************************************
*   Entry: an ostream, and the cell to be displayed
*
*    Exit:  the value of the cell
*
* Purpose: allows a cell to be outputed with the << operators
**************************************************************/
ostream &operator<<(ostream& os, const Cell& theCell)
{
	return os << theCell.m_displayChar;
}

/**************************************************************
*   Entry: none
*
*    Exit: the number of adjacent mines to this cell
*
* Purpose: returns the number of adjacent mines to the cell
**************************************************************/
int Cell::getNumOfAdjacentMines()
{
	return m_numOfAdjacentMines;
}

/**************************************************************
*   Entry: none
*
*    Exit: none
*
* Purpose: Allows the user to make the cell visible
**************************************************************/
void Cell::changeToVisible()
{
	m_isCovered = false;
}

/**************************************************************
*   Entry: none
*
*    Exit: the display character of the cell
*
* Purpose: Returns the value in display character
**************************************************************/
char Cell::getDisplayChar()
{
	return m_displayChar;
}