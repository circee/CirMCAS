#include "matrix.h"
#include <iostream>
#include <random>
using namespace std;

int main() {
	system("color 05");
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(0, 20);

	matrix a(10, 10);
	for (int z = 0;z < a.getRows();z++) {
		for (int w = 0;w < a.getColumns();w++) {
			a.assign(z, w, z+w);
		}
	}

	matrix b(10, 10);
	for (int z = 0;z < b.getRows();z++) {
		for (int w = 0;w < b.getColumns();w++) {
			b.assign(z, w, z+w);
		}
	}

	b = b * 2;
	b *= 2;
	b.print();

	system("pause");
	return 0;
}

