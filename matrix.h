#pragma once

class matrix
{
private:
	int rows;
	int cols;
	double** grid;
public:
	matrix();
	matrix(int);
	matrix(int, int);
	matrix(int, int, double);
	matrix(const matrix& orig);
	~matrix();
	void resize(int, int);
	void print();
	void fill(double);
	void zero();
	void assign(int, int, double);
	void transpose();
	int getRows();
	int getColumns();
	double read(int, int);
	static matrix transpose(const matrix);
	static matrix identity(int);
	static matrix rowToVector(const matrix, int);
	static matrix columnToVector(const matrix, int);
	
public:
	// Operators
	matrix& operator = (const matrix&);
	matrix operator + (const matrix&);
	matrix operator - (const matrix&);
	matrix operator * (const matrix&);
	matrix operator * (const double&);
	matrix operator | (const matrix&);
	matrix& operator *= (const matrix&);
	matrix& operator *= (const double&);
	matrix& operator += (const matrix&);
	matrix& operator -= (const matrix&);
	matrix& operator |= (const matrix&);

};
