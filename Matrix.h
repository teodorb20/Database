#pragma once
#include<cstring>
#include<fstream>

class Matrix {
public:
	/*
	** Big four
	*/
	Matrix(size_t rows = 0, size_t cols = 0, const char* name = "unnamed");
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	/*
	** Get methods for rows, cols and name
	** it is inline because I define it here
	*/
	inline size_t rows() const { return this->m_rows; }
	inline size_t cols() const { return this->m_cols; }
	inline const char* name() const { return this->m_name; }

	/*
	** This operator is for const objects
	*/
	const int* operator[](size_t index) const { return m_mat[index]; }
	/*
	** This operator is for non-const objects
	*/
	int* operator[](size_t index) { return m_mat[index]; }
	/*
	** Dynamic matrtix allocation
	*/
	int** initMat(size_t rows, size_t cols);
	/*
	** This operators are for writing and reading from console
	*/
	friend std::istream& operator>>(std::istream& in, Matrix& obj);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& obj);

private:
	/*
	** Delete the dynamically allocated matrix
	*/
	void clearMatrix();
	/*
	** Copy and clear methods are used in big four
	*/
	void copy(const Matrix& other);
	void clear();

protected:
	/*
	** m_rows - the rows in the matrix
	** m_cols - the cols in the matrix
	** m_mat - with in** we can dynamically allocated matrix
	** m_name - use for matrix name
	*/
	size_t m_rows;
	size_t m_cols;
	int** m_mat;
	char* m_name;
};
