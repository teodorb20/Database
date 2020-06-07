#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"Matrix.h"

class Table {
public:
	/**
	* Big four
	*/
	Table(const char* _FileName = "unnamed", int value = 0, int column = 0, const char* column_name = "unnamed", const char* column_type = "unnamed");
	Table(const Table& other);
	Table& operator=(const Table& other);
	~Table();

private:
	/**
	* Copy method is used in big four
	*/
	void copy(const Table& other);
	/**
	* Clear method is used in big four
	*/
	void clear();

protected:
	/**
	* "FileName" - write a name in which to save a table
	*/
	char* FileName;
	/**
	* "m_value" - write a value that we check if it is contained
	*/
	int m_value;
	/**
	* "m_column" - write a column in which we look for whether the "m_value" is contained
	*/
	int m_column;
	/**
	* "m_column_type" - the column type can be char, int, double ot NULL
	*/
	char* m_column_type;
	/**
	* "m_column_name" - write a name for the column
	*/
	char* m_column_name;
};