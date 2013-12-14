// simple code to compute Mandelbrot in C++
#include <iostream>
#define N 1000

int main() {


	float a[N];
	for ( int i = 0; i < N; i++ ) {
			a[i] += i;
	}
	for ( int i = 1; i < N; i++ ) {
		a[i] += a[i-1];
	}


	std::cout << a[N-1] <<std::endl;
	return 1;

}
