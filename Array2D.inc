
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/11/2015
* Last Modification Date:	10/11/2015
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.inc
*/




/**********************************************************************
*  Array2D();
*
*	Purpose: This function constructs the Array2D object and sets 
*	m_col, and m_row to 0, and initalizes m_array
*
*  	   Entry:  none
*
*  	   Exit: none
*
*
* Array2D(int row, int col = 0);

	
	Purpose: This function constructs an Array2D object, and sets the row
	and column to the values passed in. Also allocates memory for m_array
	to the size the row and colum making a 2D array

	Entry: row, which is the size of the row
		   col, which is the size for the collumns in the 2d array


	Exit: none


   Array2D(const Array2D& originalArray);

   Purpose: Allows the user to create copys of 2D array classes

   Entry: originalArray is a constant Array2D reference, it is the array that
   gets coppied.

   Exit: none


   ~Array2D();

   Purpose: To clean up all the alocated memory

   Entry: none

   Exit: none


   Array2D &operator=(const Array2D &rhs)

   Purpose: To all the user to assing a Array2d to another with the = operator

   Entry: rhs, whihc is the Array2D that will be coppied

   Exit: none



   Row<Type> operator[](int index);

   Purpose: To allow the user to modify data and accsess data in the 2DArray by
   using the subscript operator

   Entry: index which is the row size

   Exit: a Row object this row object will contain the data for the row


   Row<Type> operator[](int index) const;

   Purpose: To allow the user to modify data and accsess data in the 2DArray by
   using the subscript operator from a constant object

   Entry: index which is the row size

   Exit: a Row object this row object will contain the data for the row


   int getRow();
   Purpose: To allow the user to get the number of rows

   Entry: none

   Exit: the number of rows


   int getColumn();
   Purpose: To allow the user to get the number of columns

   Entry: none
   Exit: the number of columns


   int getColumn() const;
   Purpose: To allow the user to get the number of columns from a const object

   Entry: none
   Exit: the number of columns


   int getRow() const;
   Purpose: To allow the user to get the number of rows from a const object

   Entry: none
   Exit: number of rows


   void setRow(int rows);
   Purpose: Allows the user to set the number of rows the 2Daray should have

   Entry: rows, the new number of rows the 2Darray should have
   Exit: none


   void setColumn(int columns);
   Purpose: Allows the user to set the number of columns the 2Daray should have

   Entry: columns, the new number of columns the 2Darray should have
   Exit: none


   Type& Select(int row, int column);
   Purpose: Allows the user to get data at the point specified, at row, column

   Entry: row, the row in which the data is in, 
   column, the column which the data is in

   Exit: of Type the data that is at the cordinate

   Type& Select(int row, int column) const;
   Purpose: Allows the user to get data at the point specified, at row, column
   from a const object

   Entry: row, the row in which the data is in,
   column, the column which the data is in

   Exit: of Type the data that is at the cordinate

*
*
************************************************************************/


/*
Purpose: This function constructs an Array2D object, and sets the row
	and column to the values passed in.Also allocates memory for m_array
	to the size the row and colum making a 2D array

Entry : row, which is the size of the row
		col, which is the size for the collumns in the 2d array


	Exit : none
*/
template<class Type> Array2D<Type>::Array2D()
{
	m_col = 0;
	m_row = 0;

	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new Type[m_col];
	}

}

/*Purpose: Allows the user to create copys of 2D array classes

   Entry: originalArray is a constant Array2D reference, it is the array that
   gets coppied.

   Exit: none*/
template<class Type> Array2D<Type>::Array2D(int row, int col)
{
	m_row = row;
	m_col = col;

	m_array = new Type*[row];

	for (int i = 0; i < row; i++)
	{
		m_array[i] = new Type[col];
	}
}


/*Purpose: Allows the user to create copys of 2D array classes

   Entry: originalArray is a constant Array2D reference, it is the array that
   gets coppied.

   Exit: none*/
template<class Type> Array2D<Type>::Array2D(const Array2D& originalArray) :
m_row(originalArray.m_row),
m_col(originalArray.m_col)
{
	//realocate the array
	m_array = new Type*[m_row];

	//creates the 2 dimentional array
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new Type[m_col];
	}

	//coppys the originalArray into this array
	for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
	{
		for (int Colidx = 0; Colidx < m_col; Colidx++)
		{
			m_array[rowIdx][Colidx] = originalArray.m_array[rowIdx][Colidx];
		}
	}
}

/* Purpose: To clean up all the alocated memory

   Entry: none

   Exit: none*/
template<class Type> Array2D<Type>::~Array2D()
{
	//cleanup allowcated memor
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;
}

//operator overloading

/*Purpose: To all the user to assing a Array2d to another with the = operator

   Entry: rhs, whihc is the Array2D that will be coppied

   Exit: none*/
template<class Type> Array2D<Type> &Array2D<Type>::operator=(const Array2D &rhs)
{
	m_row = rhs.m_row;
	m_col = rhs.m_col;

	m_array = new Type*[m_row];
	//Type* arrayofTypes = new Type[row];
	//m_array = new Row<Type>(arrayofTypes, col)[row];


	//creates the 2 dimentional array
	for (int i = 0; i < rhs.m_row; i++)
	{
		m_array[i] = new Type[rhs.m_col];
	}


	//coppys the originalArray into this array
	for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
	{
		for (int Colidx = 0; Colidx < m_col; Colidx++)
		{
			m_array[rowIdx][Colidx] = rhs.m_array[rowIdx][Colidx];
		}
	}
	return *this;
}


/*
   Purpose: To allow the user to modify data and accsess data in the 2DArray by
   using the subscript operator

   Entry: index which is the row size

   Exit: a Row object this row object will contain the data for the row*/
template<class Type>   Row<Type> Array2D<Type>::operator[](int index)
{
	if (index < 0)
	{
		throw Exception("column below 0");
	}

	if (index > m_row)
	{
		throw Exception("column above max column");
	}

	Row<Type> row(*this, index);
	return row;
}

/*Purpose: To allow the user to modify data and accsess data in the 2DArray by
	using the subscript operator from a constant object

Entry : index which is the row size

	Exit : a Row object this row object will contain the data for the row*/
template<class Type>   Row<Type> Array2D<Type>::operator[](int index) const
{
	if (index < 0)
	{
		throw Exception("column below 0");
	}

	if (index > m_row)
	{
		throw Exception("column above max column");
	}

	Row<Type> row(*this, index);
	return row;
}
/*
Purpose: Allows the user to get data at the point specified, at row, column

Entry: row, the row in which the data is in,
column, the column which the data is in

Exit: of Type the data that is at the cordinate
*/
template<class Type> Type& Array2D<Type>::Select(int row, int column)
{
	//Checking for user trying to go out of bounds
	if (row < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (row > m_row)
	{
		throw Exception("row specified is above maximum row");
	}

	if (column < 0)
	{
		throw Exception("column specified is below 0");
	}

	if (column > m_col)
	{
		throw Exception("column specified is above maximum column");
	}

	return m_array[row][column];
}

/*Purpose: Allows the user to get data at the point specified, at row, column
   from a const object

   Entry: row, the row in which the data is in,
   column, the column which the data is in
   
   Exit: of Type the data that is at the cordinate
   */
template<class Type> Type& Array2D<Type>::Select(int row, int column) const
{
	//Checking for user trying to go out of bounds
	if (row < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (row > m_row)
	{
		throw Exception("row specified is above maximum row");
	}

	if (column < 0)
	{
		throw Exception("column specified is below 0");
	}

	if (column > m_col)
	{
		throw Exception("column specified is above maximum column");
	}

	return m_array[row][column];
}


/*
Purpose: To allow the user to get the number of rows

Entry: none
Exit: number of rows
*/
template<class Type> int Array2D<Type>::getRow()
{
	return m_row;
}

/*Purpose: To allow the user to get the number of rows from a const object

Entry: none

Exit: number of rows
*/
template<class Type> int Array2D<Type>::getRow() const
{
	return m_row;
}

/*Purpose: To allow the user to get the number of columns

Entry : none
	Exit : the number of columns
	*/
template<class Type> int Array2D<Type>::getColumn()
{
	return m_col;
}

/*Purpose: To allow the user to get the number of columns from a const object

Entry: none
Exit: the number of columns
*/
template<class Type> int Array2D<Type>::getColumn() const
{
	return m_col;
}

/*Purpose: Allows the user to set the number of columns the 2Daray should have

Entry : columns, the new number of columns the 2Darray should have
	Exit : none
	*/
template<class Type> void Array2D<Type>::setColumn(int newCol)
{
	//Type **tempArray;
	
		Array2D temp;
		temp = *this;
	

	//deletes m_array
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	//might need to remove
	if (m_row > 0 || m_col > 0)
	{
		delete[] m_array;
	}
	
	//delete[] m_array;

	//allocates the new memory for the array
	m_row = temp.m_row;
	m_col = newCol;

	m_array = new Type*[m_row];

	
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new Type[newCol];//test
	}

	//transfers the temp to the new memory

	//check to see if anything needs to be coppied
	if (temp.getColumn() != 0 && temp.getRow() != 0)
	{
		for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
		{
			for (int Colidx = 0; Colidx < m_col; Colidx++)
			{
				m_array[rowIdx][Colidx] = temp[rowIdx][Colidx];
			}
		}
	}
}

/*Purpose: Allows the user to set the number of rows the 2Daray should have

Entry: rows, the new number of rows the 2Darray should have
Exit: none
*/
template<class Type> void Array2D<Type>::setRow(int newRow)
{
	Array2D<Type> temp;
	temp = *this;

	//deletes m_array
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	//might need to remove
	
	if (m_row > 0 || m_col > 0)
	{
		delete[] m_array;
	}
	
	//delete[] m_array;

	//allocates the new memory for the array
	m_row = newRow;
	m_col = temp.m_col;

	m_array = new Type*[newRow];

	for (int i = 0; i < newRow; i++)
	{
		m_array[i] = new Type[m_col];
	}

	//transfers the temp to the new memory
	if (temp.getColumn() != 0 && temp.getRow() != 0)//check to make sure temp has something inside of it
	{
		for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
		{
			for (int Colidx = 0; Colidx < m_col; Colidx++)
			{
				m_array[rowIdx][Colidx] = temp[rowIdx][Colidx];
			}
		}
	}
}