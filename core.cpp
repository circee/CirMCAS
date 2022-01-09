#include "matrix.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Dim {
	int m;
	int n;
};

void throwError(string str = "");

matrix matrixFromFile(string fileName);
string getFileName();
Dim getMatrixDim(string fileName);
string getString();



int main() {
	system("color 05");

	while (true) {
		cout << "File: ";
		matrix myMatrix = matrixFromFile(getFileName());

		myMatrix.transpose();
		myMatrix.print();
	}

	system("pause");
	return 0;
}

matrix matrixFromFile(string fileName) {
	ifstream file;
	double temp;
	int i = -2;
	int j = 0, k = 0;

	Dim matrixDim = getMatrixDim(fileName);
	matrix newMatrix(matrixDim.m, matrixDim.n);

	file.open(fileName);

	// Dumpster fire code 

	if (file) {
		while (file >> temp) {
			if (!(i < 0)) {
				newMatrix.assign(j, k, temp);
				if (k+1 == newMatrix.getColumns()) {
					j++;
					k = 0;
				}
				else {
					k++;
				}
			}
			i++;
		}

		return newMatrix;
	}
	else {
		throwError("Could not open matrix file");
	}
}

string getString() {
	string str;

	cin >> ws;
	getline(cin, str);
	return str;
}

string getFileName() {
	return getString();
}

Dim getMatrixDim(string fileName) {
	ifstream file;
	file.open(fileName);

	if (file) {
		Dim matrixDim;
		file >> matrixDim.m;
		file >> matrixDim.n;
		file.close();
		return matrixDim;
	}
	else {
		throwError("Could not open matrix file");
	}
}

void throwError(string errMsg) {
	cout << "ERROR: " << errMsg << ". Program will now close.";
	system("pause");
	system("exit");
}
