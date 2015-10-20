/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/7/2015
* Last Modification Date:	10/11/2015
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.h
*/



/************************************************************************
* Class: Array2D
*

Description: This is a template 2Darray class, that allows the user to input
a row and a column size. This creates the size of the array. 



* Constructors:
*	Array2D()
*		length initialized to 0
*		msg initizlized to an array of 1

	Array2D(int row, int col = 0);
		row set to peramerter passed in
		col set to perameter passed in
		m_array initizlized


Array2D(const Array& originalArray)
originalArray the array that is going to be coppied
*
* Mutators:
Array2D &operator=(const Array2D &rhs);
	sets the left hand side equal to the rhs

//overloaded subscript operator
Row<Type> operator[](int index);
	Allows the user to use the subscript operator
	returns a row object

//const subscript operator

Row<Type> operator[](int index) const;
	Allows the user to use the sbuscipt operator
	returns a row object
	can be called from a const object

//sets the row and column
void setRow(int rows);
	Sets the row to the value passed in

void setColumn(int columns);
	Sets the column to the balue passed in


Inspectors:
//Getting rows and collomns
int getRow();
	returns the # of rows

int getColumn();
	Returns the number of columns

//const version of get
int getColumn() const;
	returns the number of columns from a const object

int getRow() const;
	returns the number of rows from a const object

//selects a row and column
Type& Select(int row, int column);
	returns the data at the row and column cordinate

Type& Select(int row, int column) const;
	returns the data at the row and column cordinate form a const object


*************************************************************************/

#include "Exception.h"
#include "Row.h"


template <class  Type> class Array2D
{
public:
	//constructor
	Array2D();

	//constructor
	Array2D(int row, int col = 0);

	//copy contructor
	Array2D(const Array2D& originalArray);

	//destructor
	~Array2D();

	//operator overloading
	Array2D &operator=(const Array2D &rhs);

	//overloaded subscript operator
	Row<Type> operator[](int index);

	//const subscript operator

	Row<Type> operator[](int index) const;

	//Getting rows and collomns
	int getRow();
	int getColumn();

	//const version of get
	int getColumn() const;

	int getRow() const;

	//sets the row and column
	void setRow(int rows);
	void setColumn(int columns);

	//selects a row and column
	Type& Select(int row, int column);

	Type& Select(int row, int column) const;

private:
	Type **m_array;
	int m_row;
	int m_col;
};

#include "Array2D.inc"


