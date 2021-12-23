<<<<<<< HEAD
#include "Matrica.h"

Matrica::Matrica() : data(nullptr), rows(0), cols(0) {}
Matrica::Matrica(int N, int M) {
	data = nullptr;
	newMatrica(N, M);
}
Matrica::~Matrica() {
	newMatrica(0, 0);
}
void Matrica::newMatrica(int N, int M) {
	int i;
	delete[] data;
	if (N && M) {
		data = new Vector[M];
		for (i = 0; i < M; ++i)
			data[i].resize(N);
		rows = N;
		cols = M;
	}
	else {
		data = nullptr;
		rows = cols = 0;
	}
}
void Matrica::setMatrica(double Element ...) {
	int i, j;
	va_list ap;
	va_start(ap, Element);
	data[0][0] = Element;
	for (j = 1; j < cols; j++) {
		data[j][0] = (double)va_arg(ap, double);
	}
	for (i = 1; i < rows; ++i)
		for (j = 0; j < cols; j++) {
			data[j][i] = (double)va_arg(ap, double);
		}
	va_end(ap);
}
Vector operator*(const Matrica &A, const Vector &a) {
	int i, j;
	Vector resVector;
	resVector.resize(a.size());
	for (i = 0; i < A.rows; ++i) {
		resVector[i] = 0;
		for (j = 0; j < A.cols; ++j) {
			resVector[i] += A.data[j][i] * a[j];
		}
	}
	return resVector;
}
Vector operator*(const Vector &a, const Matrica &A) {
	int i, j;
	Vector resVector;
	resVector.resize(A.cols);
	for (i = 0; i < A.cols; ++i) {
		resVector[i] = 0.0;
		for(j = 0; j < A.rows; ++j)
			resVector[i] += a[j] * A.data[i][j];
	}
	return resVector;
=======
#include "Matrica.h"

Matrica::Matrica() : data(nullptr), rows(0), cols(0) {}
Matrica::Matrica(int N, int M) {
	data = nullptr;
	newMatrica(N, M);
}
Matrica::~Matrica() {
	newMatrica(0, 0);
}
void Matrica::newMatrica(int N, int M) {
	int i;
	delete[] data;
	if (N && M) {
		data = new Vector[M];
		for (i = 0; i < M; ++i)
			data[i].resize(N);
		rows = N;
		cols = M;
	}
	else {
		data = nullptr;
		rows = cols = 0;
	}
}
void Matrica::setMatrica(double Element ...) {
	int i, j;
	va_list ap;
	va_start(ap, Element);
	data[0][0] = Element;
	for (j = 1; j < cols; j++) {
		data[j][0] = (double)va_arg(ap, double);
	}
	for (i = 1; i < rows; ++i)
		for (j = 0; j < cols; j++) {
			data[j][i] = (double)va_arg(ap, double);
		}
	va_end(ap);
}
Vector operator*(const Matrica &A, const Vector &a) {
	int i, j;
	Vector resVector;
	resVector.resize(a.size());
	for (i = 0; i < A.rows; ++i) {
		resVector[i] = 0;
		for (j = 0; j < A.cols; ++j) {
			resVector[i] += A.data[j][i] * a[j];
		}
	}
	return resVector;
}
Vector operator*(const Vector &a, const Matrica &A) {
	int i, j;
	Vector resVector;
	resVector.resize(A.cols);
	for (i = 0; i < A.cols; ++i) {
		resVector[i] = 0.0;
		for(j = 0; j < A.rows; ++j)
			resVector[i] += a[j] * A.data[i][j];
	}
	return resVector;
>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
}