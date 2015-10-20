
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/11/2015
* Last Modification Date:	10/11/2015
* Lab Number:			CST 211 Assignment 2
* Filename:				Row.inc
*/


/*


Row(Array2D<Type>& theArray, int row);
Purpose: To all the user to create a Row object

Entry: An array class which will store the data at the points, a row telling the class
which row it is
Exit: none

Row(const Array2D<Type> &theArray, int row);
Purpose: An array class which will store the data at the points, a row telling the class
which row it is from a const object

Entry: An array class which will store the data at the points, a row telling the class
which row it is
Exit: none

Type &operator[](int column);
Purpose: To allow the user to get accses to the index at the given column

Entry:The column of the index to get
Exit: The data at the given point

Type &operator[](int column) const;
Purpose: To allow the user to get accses to the index at the given column from a const object

Entry:The column of the index to get
Exit: The data at the given point

*/


/*Purpose: To all the user to create a Row object

Entry: An array class which will store the data at the points, a row telling the class
which row it is
Exit: none
*/
template<class Type> Row<Type>::Row(Array2D<Type>& theArray, int row) :
m_row(row),
m_data(theArray)
{
}


/*Purpose: An array class which will store the data at the points, a row telling the class
which row it is from a const object

Entry: An array class which will store the data at the points, a row telling the class
which row it is
Exit: none
*/
template<class Type> Row<Type>::Row(const Array2D<Type> &theArray, int row) :
m_row(row),
m_data(theArray)
{
}

/*Purpose: To allow the user to get accses to the index at the given column

Entry : The column of the index to get
	Exit : The data at the given point
*/
template<class Type> Type& Row<Type>::operator[](int column)
{
	//m_data.select(row, column);
	if (column < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (column >= m_data.getColumn())
	{
		throw Exception("row specified is above maximum row");
	}
	return m_data.Select(m_row, column);
}


/*Purpose: To allow the user to get accses to the index at the given column from a const object

Entry:The column of the index to get
Exit: The data at the given point
*/
template<class Type> Type& Row<Type>::operator[](int column) const
{
	//m_data.select(row, column);
	if (column < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (column >= m_data.getColumn())
	{
		throw Exception("row specified is above maximum row");
	}
	return m_data.Select(m_row, column);
}
