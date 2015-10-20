
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/19/2015
* Last Modification Date:	10/19/2015
* Lab Number:			CST 211 Lab 1
* Filename:				Cell.h
*
*/



#include <iostream>
using namespace std;



/************************************************************************
* Class: Cell
*
* Constructors:
*	Cell()
*		Allows cells to be constructed
	Cell(char value, char displayChar, int numOfAdjacentMines = 0, bool isCovered = true);
		Allows the user to create a cell specifying a value, displaychar a numOfAdjacentMines, and if it is covered or not
* Mutators:
*	void changeNumOfAdjacentMines(int numOfAdjacentMines);
		Allows the user to change the number of adjacent mines

	void changeIsCovered(bool isCovered);
		Allows the user to change weather the cell is covered or not

	void changeDisplayChar(char newDisplayChar);
		ALlows the user to change the character that is displayed
	
	void changeValue(char newValue);
		Allows the user to change the value of the cell
	
	void changeToVisible();
		Allows the user to make the cell visible
*
* Methods:
*	char getDisplayChar(void);
		Returns the value in display character

	char getValue();
		returns the value of the cell
	int getNumOfAdjacentMines();
		returns the number of adjacent mines to the cell
	

	friend ostream& operator<<(ostream& os, const Cell& theCell);
		allows a cell to be outputed with the << operators

*************************************************************************/
class Cell
{
public:
	Cell();
	Cell(char value, char displayChar, int numOfAdjacentMines = 0, bool isCovered = true);

	void changeNumOfAdjacentMines(int numOfAdjacentMines);
	void changeIsCovered(bool isCovered);
	void changeDisplayChar(char newDisplayChar);
	
	void changeValue(char newValue);
	void changeToVisible();

	
	
	char getDisplayChar(void);
	char getValue();
	int getNumOfAdjacentMines();
	

	friend ostream& operator<<(ostream& os, const Cell& theCell);

private:



	bool m_isCovered;
	int m_numOfAdjacentMines;
	char m_displayChar; //to display a number, or a blank space, or a mine, or a marked mine
	char m_value; //what the cell actualy is (mine, empty, or a number of adjacent mines



};