#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Table.h"
#include "Matrix.h"

/*
** Setting maximum values
*/
int const MAX_INPUT_SIZE = 11;
int const MAX_FILENAME_SIZE = 32;
int const MAX_NAME_SIZE = 32;
int const MAX_TYPE_SIZE = 7;

class System : protected Table {
public:

	/*
	** Check the name if is loaded
	*/
	int findMatrixId(std::vector<Matrix> vec, const char* m_name);
	/*
	** Print help menu
	*/
	void Help();
	/*
	** This function does not allow a new copy of the system to be made
	*/
	static System& i();
	/*
	** Function "run" is used to write all other functions and run the program
	*/
	void run();

};
