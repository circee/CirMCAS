#include "matrix.h"
#include <iostream>
#include <stdexcept>

// Default Constructor
matrix::matrix() {
	rows = 1;
	cols = 1;

	cout << "Creating new " << rows << "x" << cols << " matrix.\n";

	grid = new double* [rows];

	for (int i = 0;i < rows;++i) {
		grid[i] = new double[cols];
	}

	for (int r = 0; r < rows;++r) {
		for (int c = 0;c < cols;++c) {
			grid[r][c] = 0;
		}
	}
}

// Copy Constructor
matrix::matrix(const matrix& orig) {
	rows = orig.rows;
	cols = orig.cols;

	cout << "Creating new " << rows << "x" << cols << " matrix.\n";

	grid = new double* [rows];

	for (int i = 0;i < rows;++i) {
		grid[i] = new double[cols];
	}
	
	for (int r = 0; r < rows;++r) {
		for (int c = 0;c < cols;++c) {
			grid[r][c] = orig.grid[r][c];
		}
	}

}
// Init as a zero matrix
matrix::matrix(int m, int n) {

	rows = m;
	cols = n;

	cout << "Creating new " << rows << "x" << cols << " matrix.\n";

	grid = new double* [rows];

	for (int i = 0;i < rows;++i) {
		grid[i] = new double[cols];
	}
	fill(0);
	//for (int r = 0; r < rows;++r) {
	//	for (int c = 0;c < cols;++c) {
	//		grid[r][c] = 0;
	//	}
	//}
}

// Square matrix
matrix::matrix(int dim) {
	rows = dim;
	cols = dim;
	cout << "Creating new " << rows << "x" << cols << " matrix.\n";

	grid = new double* [rows];
	for (int i = 0;i < rows;++i) {
		grid[i] = new double[cols];
	}

	fill(0);
	//for (int r = 0; r < rows;++r) {
	//	for (int c = 0;c < cols;++c) {
	//		grid[r][c] = 0;
	//	}
	//}
}

// Fill on init
matrix::matrix(int m, int n, double d) {
	rows = m;
	cols = n;

	cout << "Creating new " << rows << "x" << cols << " matrix.\n";

	grid = new double* [rows];

	for (int i = 0;i < rows;++i) {
		grid[i] = new double[cols];
	}

	cout << "Populating with " << d << "\n";

	fill(d);
}

// Destructor
matrix::~matrix() {
	for (int i = 0;i < rows;++i) {
		delete[] grid[i];
	}
	delete[] grid;
}

// Printout
void matrix::print() {
	for (int r = 0;r < rows;r++) {
		for (int c = 0;c < cols;c++) {
			cout << (c == 0 ? "|" : "") << grid[r][c] << (c == (cols - 1) ? "|\n" : ",");
		}
	}
}

// Fill with d
void matrix::fill(double d) {
	for (int r = 0; r < rows;++r) {
		for (int c = 0;c < cols;++c) {
			grid[r][c] = d;
		}
	}
}

// Resize and zero
void matrix::resize(int m, int n) {
	for (int i = 0;i < rows;++i) {
		delete[] grid[i];
	}
	delete[] grid;

	rows = m;
	cols = n;

	grid = new double* [rows];
	for (int i = 0;i < rows;++i) {
		grid[i] = new double[cols];
	}

	zero();
}

// Populate with 0
void matrix::zero() {
	fill(0);
}

// Assign v to (i,j)
void matrix::assign(int i, int j, double v) {
	grid[i][j] = v;
}

// Read at (i,j)
double matrix::read(int i, int j) {
	return grid[i][j];
}

// Return rows
int matrix::getRows() {
	return rows;
}

// Return columns 
int matrix::getColumns() {
	return cols;
}

// Transpose
void matrix::transpose() {
	matrix trans(cols, rows);
	cout << "Transposing...\n";

	for (int r = 0; r < rows;++r) {
		for (int c = 0;c < cols;c++) {
			trans.assign(c, r, grid[r][c]);
		}
	}
	
	resize(cols, rows);

	for (int r = 0; r < rows;++r) {
		for (int c = 0;c < cols;c++) {
			grid[r][c] = trans.grid[r][c];
		}
	}
}

// Static Transpose 
matrix matrix::transpose(const matrix in) {
	matrix trans(in.cols, in.rows);
	cout << "Transposing...\n";

	for (int r = 0; r < in.rows;r++) {
		for (int c = 0;c < in.cols;c++) {
			trans.assign(c,r,in.grid[r][c]);
		}
	}
	//trans.transpose();
	/*
	for (int r = 0; r < in.rows;r++) {
		for (int c = 0;c < in.cols;c++) {
			trans.assign(c, r, in.grid[r][c]);
		}
	}*/

	return trans;
}

// Static Identity
matrix matrix::identity(int d) {
	matrix I(d, d, 0);
	for (int i = 0;i < d;i++) {
		I.assign(i, i, 1);
	}
	return I;
}

// Operators
// Equals
matrix& matrix::operator = (const matrix& B) {
	if (this->rows != B.rows || this->cols != B.cols) {
		for (int i = 0;i < this->rows;++i) {
			delete[] this->grid[i];
		}
		delete[] this->grid;
		this->rows = B.rows;
		this->cols = B.cols;
		this->grid = new double* [this->rows];
		for (int i = 0;i < this->rows;++i) {
			this->grid[i] = new double[this->cols];
		}

	}
	for (int r = 0; r < this->rows;r++) {
		for (int c = 0;c < this->cols;c++) {
			this->assign(r, c, B.grid[r][c]);
		}
	}

	return *this;
}

// Addition
matrix matrix::operator + (const matrix& B) {
	if (rows != B.rows && cols != B.cols) {
		throw domain_error("Incompatible matrix dimensions.");
	}

	matrix sum(rows, cols);

	for (int r = 0;r < rows;r++) {
		for (int c = 0;c < cols;c++) {
			sum.assign(r, c, (grid[r][c] + B.grid[r][c]));
		}
	}
	return sum;
}

// Subtraction
matrix matrix::operator - (const matrix& B) {
	if (rows != B.rows && cols != B.cols) {
		throw domain_error("Incompatible matrix dimensions.");
	}

	matrix sum(rows, cols);

	for (int r = 0;r < rows;r++) {
		for (int c = 0;c < cols;c++) {
			sum.assign(r, c, (grid[r][c] - B.grid[r][c]));
		}
	}
	return sum;
}

// Scalar Multiplication
matrix matrix::operator * (const double& d) {

	matrix product(rows, cols);

	for (int r = 0;r < rows;r++) {
		for (int c = 0;c < cols;c++) {
			product.assign(r, c, (grid[r][c] * d));
		}
	}
	return product;
}

// A*B matrix multiplicaiton yields a matrix of dimension A.rows x B.cols
matrix matrix::operator * (const matrix& B) {

	if (cols != B.rows) {
		throw domain_error("Incompatible matrix dimensions.");
	}
	matrix product(rows, B.cols);
	int sum;
	for (int Pr = 0; Pr < product.cols;Pr++) {
		for (int Pc = 0; Pc < product.rows;Pc++) {
			sum = 0;

			for (int u = 0; u < cols;u++) {
				sum += grid[Pr][u] * B.grid[u][Pc];
				//cout << "Doing " << grid[Pr][u] << "x" << B.grid[u][Pc] << "\n";
			}
			product.assign(Pr,Pc,sum);
		}
	}

	return product;
}