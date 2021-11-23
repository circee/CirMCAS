#include "matrix.h"
#include <iostream>
#include <random>
using namespace std;

int main() {
	system("color 05");
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(0, 10);

	matrix a(5, 5);
	for (int z = 0;z < a.getRows();z++) {
		for (int w = 0;w < a.getColumns();w++) {
			a.assign(z, w, z+w);
		}
	}
	a.print();
	matrix b(5, 5);
	for (int z = 0;z < b.getRows();z++) {
		for (int w = 0;w < b.getColumns();w++) {
			b.assign(z, w, z*w);
		}
	}
	b.print();
	b |= a;
	b.print();

	system("pause");
	return 0;
}

