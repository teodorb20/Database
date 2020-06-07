#pragma once
#include<cstring>
#include<fstream>

class Matrix {
public:
	/**
	* Big four
	*/
	Matrix(size_t rows = 0, size_t cols = 0, const char* name = "unnamed");
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	/**
	* Get method for rows.
	* It is inline because I define it here
	*/
	inline size_t rows() const { return this->m_rows; }
	/**
	* Get method cols.
	* It is inline because I define it here
	*/
	inline size_t cols() const { return this->m_cols; }
	/**
	* Get method name.
	* It is inline because I define it here
	*/
	inline const char* name() const { return this->m_name; }

	/**
	* This operator is for const objects
	*/
	const int* operator[](size_t index) const { return m_mat[index]; }
	/**
	* This operator is for non-const objects
	*/
	int* operator[](size_t index) { return m_mat[index]; }
	/**
	* Dynamic matrtix allocation
	*/
	int** initMat(size_t rows, size_t cols);
	/**
	* This operators are for writing from console
	*/
	friend std::istream& operator>>(std::istream& in, Matrix& obj);
	/**
	* This operators are for reading from console
	*/
	friend std::ostream& operator<<(std::ostream& out, const Matrix& obj);

private:
	/**
	* Delete the dynamically allocated matrix
	*/
	void clearMatrix();
	/**
	* Copy method is used in big four
	*/
	void copy(const Matrix& other);
	/**
	* Clear method is used in big four
	*/
	void clear();

protected:
	/**
	* m_rows - the rows in the matrix
	*/
	size_t m_rows;
	/**
	* m_cols - the cols in the matrix
	*/
	size_t m_cols;
	/**
	* m_mat - with in** we can dynamically allocated matrix
	*/
	int** m_mat;
	/**
	* m_name - use for matrix name
	*/
	char* m_name;
};