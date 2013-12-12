/*
 * ws6.cpp
 *
 *  Created on: 30.11.2013
 *      Author: felixrempe, Xiao Xue
 */

#include <iostream>
#include <time.h> //for measuring time

using namespace std;


//return the number of clock ticks spent on that programm
clock_t start_time_measuring() {
	return clock();
}

//returns the difference between the current time and a starting time in mseconds
float stop_time_measuring(clock_t start_time) {
	return float(difftime( clock(), start_time) )*1000.0/ CLOCKS_PER_SEC;
}

//allocate and fill a matrix of size NxN
double** create_random_matrix( int n) {
	//alloc ressources
	double ** mat = (double **) malloc( n * sizeof(double*));
	for( int i = 0; i < n; i++) {
		mat[i] = (double *) malloc (n * sizeof (double) );
	}

	//fill randomly
	for ( int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = (float)rand()*10/(float)RAND_MAX;
		}
	}

	return mat;
}

int main( int argc, char *argv[]) {
	cout << " Doing some matrix multiplications " <<endl;

	if (argc != 3 ) {
		cout <<" use like this: <size> <type> where size is the NxN size of the matrix and" <<
				"type can be <normal>, <blocked> or <optimized> " <<endl;
		return -1;
	}

	int size = atoi(argv[1]);
	char *method = argv[2];
	clock_t start_time;
	clock_t end_time;

	if(size < 8 ) {
		cout << "Size invalid. Must be greater equal 8"<<endl;
		return -1;
	}

	start_time = start_time_measuring();

	//create random matrix of size n
	double** mat1 = create_random_matrix(size);
	double** mat2 = create_random_matrix(size);
	double** res = create_random_matrix(size);

	cout << "time needed for initialization: " << stop_time_measuring(start_time)<<endl;

	if( strcmp(method, "normal") == 0) {
		cout << " Doing normal multiplication mode " <<endl;
        // TODO straight forward matix matix mult.
	} else if (strcmp(method, "blocked") == 0) {

		// TODO Blocked method
	} else if (strcmp(method, "optimized") == 0) {
		// TODO optimized
	} else {
		cout << " Multiplication method not found ..." <<endl;
		return -1;
	}

	cout << "time needed for multiplication: " << stop_time_measuring(start_time)<<endl;
}



