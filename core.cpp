#include "matrix.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void throwError(string str = "");

string getFileName();

matrix matrixFromFile(string fileName);
void matrixToFile(string fileName, matrix outMatrix);

matrix getMatrixDim(string fileName);

string getString();
bool yOrN();


int main() {
	system("color 05");

	while (true) {
		cout << "Matrix file: ";
		matrix myMatrix = matrixFromFile(getFileName());

		myMatrix.transpose();
		myMatrix.print();

		cout << "Would you like to save this transpose? ";
		if (yOrN()) {
			cout << "Save as: ";
			matrixToFile(getFileName(), myMatrix);
			cout << "Saved!";
		}

		cout << "\n---------------------------------------------------------------------------\n";

	}

	system("pause");
	return 0;
}

matrix matrixFromFile(string fileName) {
	ifstream file;
	double temp;
	int i = -2;
	int j = 0, k = 0;

	matrix newMatrix = getMatrixDim(fileName);

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

matrix getMatrixDim(string fileName) {
	ifstream file;
	file.open(fileName);

	if (file) {
		int m,n;
		file >> m;
		file >> n;
		file.close();
		return matrix(m,n);
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

void matrixToFile(string fileName, matrix outMatrix) {
	ofstream file;
	file.open(fileName);

	if (file) {
		file << outMatrix.getRows() << ' ';
		file << outMatrix.getColumns() << ' ';

		for (int i = 0; i < outMatrix.getRows(); i++) {
			for (int j = 0; j < outMatrix.getColumns(); j++) {
				file << outMatrix.read(i,j) << ' '; // Will overload [] eventually 
			}
		}

		file.close();
	}
	else {
		throwError("Could not open matrix file");
	}
}

bool yOrN() {
	char ch;
	cin >> ch;
	cin.ignore(1000, '\n');
	cout << "\n";

	while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n')) {
		cout << "\tPlease Y yes or N: ";
		cin >> ch;
		cin.ignore(1000, '\n');
		cout << "\n";
	}
	if (ch == 'Y' || ch == 'y') {
		return true;
	}
	else {
		return false;
	}
}