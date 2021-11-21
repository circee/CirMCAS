#include "matrix.h"
#include <iostream>
#include <random>
using namespace std;

int main() {
	system("color 05");
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distr(1.0, 10.0);

	matrix a(200, 200);
	a.fill(17.82822);
	for (int z = 0;z < a.getRows();z++) {
		for (int w = 0;w < a.getColumns();w++) {
			a.assign(z, w, (a.read(z, w) + distr(gen)));
		}
	}
	a.print();
	matrix b(200, 200, 5.122);
	for (int z = 0;z < b.getRows();z++) {
		for (int w = 0;w < b.getColumns();w++) {
			b.assign(z, w, (b.read(z, w) + distr(gen)));
		}
	}
	b.print();

	matrix c = b*a;
	c.print();
	system("pause");
	return 0;
}