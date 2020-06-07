#include "Table.h"

Table::Table(const char* _FileName, int value, int column, const char* column_name, const char* column_type)
	: FileName(new char[strlen(_FileName) + 1])
	, m_value(value)
	, m_column(column)
	, m_column_name(new char[strlen(column_name) + 1])
	, m_column_type(new char[strlen(column_type) + 1])
{
	strcpy(FileName, _FileName);
	strcpy(m_column_name, column_name);
	strcpy(m_column_type, column_type);
}

Table::Table(const Table& other)
{
	copy(other);
}

Table& Table::operator=(const Table& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

Table::~Table()
{
	clear();
}

void Table::copy(const Table& other)
{
	this->FileName = new char[strlen(other.FileName) + 1];
	strcpy(this->FileName, other.FileName);
	this->m_value = other.m_value;
	this->m_column = other.m_column;
	this->m_column_name = new char[strlen(other.m_column_name) + 1];
	strcpy(this->m_column_name, other.m_column_name);
	this->m_column_type = new char[strlen(other.m_column_type) + 1];
	strcpy(this->m_column_type, other.m_column_type);

}

void Table::clear()
{
	delete[] FileName;
	FileName = nullptr;
	delete[] m_column_name;
	m_column_name = nullptr;
	delete[] m_column_type;
	m_column_type = nullptr;
}
