
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/7/2015
* Last Modification Date:	10/7/2015
* Lab Number:			CST 211 Assignment 2
* Filename:				Row.h
*/

//Declaring Array2D class exsistes so Array2D.h dosn't need to be included
template <class  Type> class Array2D;

/************************************************************************
* Class: Row
*

Description: This is a template class that keeps the data for the 2Darray

* Constructors:
*	Row(Array2D<Type>& theArray, int row)
*		stores the 2Darray
stores the row number for the 2Darray

Row(const Array2D<Type> &theArray, int row);
stores the 2Darray for a const object
stores the row number for the 2Darray for a const object


Mutators:
template<class Type> Type& Row<Type>::operator[](int column):
Allows the user to get at the data at the specified colum, from the row
It data can be changed and sotred

Inspectors:
template<class Type> Type& Row<Type>::operator[](int column) const:
Allows the user to get the data at the specified collumn from const objects


*/

template <class Type> class Row
{
public:

	Row(Array2D<Type>& theArray, int row);

	Row(const Array2D<Type> &theArray, int row);
	
	Type &operator[](int column);

	Type &operator[](int column) const;


private:
	int m_row;
	//mutable Array2D<Type>& m_data;
	mutable const Array2D<Type>& m_data;
};

#include "Row.inc"