/*
 * ws6.cpp
 *
 *  Created on: 30.11.2013
 *      Author: Xiao Xue
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
	return float(difftime( clock(), start_time) )/ CLOCKS_PER_SEC;
}

//allocate and fill a matrix of size NxN
double* create_random_matrix( int n) {
	//alloc ressources
    int mem_size;
	mem_size = n * n * sizeof(double);
    double *mat = (double*)malloc(mem_size);

	//fill randomly
	for ( int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i*n+j] = (float)rand()*10/(float)RAND_MAX;
		}
	}

	return mat;
}

//allocate and fill a rhs matrix of size NxN
double* create_rhs_matrix( int n) {
	//alloc ressources
    int mem_size;
	mem_size = n * n * sizeof(double);
    double *mat = (double*)malloc(mem_size);
    
    for ( int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i*n+j] = 0.0;
		}
	}
    
	return mat;
}

//compute the square of the matrix ijk
int mat_times_mat_ijk( double * mat1, double* mat2, double* res, int n ) {
	for ( int i = 0; i < n; i ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			for ( int k = 0; k < n; k ++ ) {
				res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
			}
		}
	}
	return 0;
}

//compute the square of the matrix ikj
int mat_times_mat_ikj( double * mat1, double* mat2, double* res, int n ) {
	for ( int i = 0; i < n; i ++ ) {
		for ( int k = 0 ; k < n ; k ++ ) {
			for ( int j = 0; j < n; j ++ ) {
				res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
			}
		}
	}
	return 0;
}

//compute the square of the matrix jki
int mat_times_mat_jki( double * mat1, double* mat2, double* res, int n ) {
	for ( int j = 0; j < n; j ++ ) {
		for ( int k = 0 ; k < n ; k ++ ) {
			for ( int i = 0; i < n; i ++ ) {
				res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
			}
		}
	}
	return 0;
}

//compute the square of the matrix jik
int mat_times_mat_jik( double * mat1, double* mat2, double* res, int n ) {
	for ( int j = 0; j < n; j ++ ) {
		for ( int i = 0 ; i < n ; i ++ ) {
			for ( int k = 0; k < n; k ++ ) {
				res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
			}
		}
	}
	return 0;
}

//compute the square of the matrix kij
int mat_times_mat_kij( double * mat1, double* mat2, double* res, int n ) {
	for ( int k = 0; k < n; k ++ ) {
		for ( int i = 0 ; i < n ; i ++ ) {
			for ( int j = 0; j < n; j ++ ) {
				res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
			}
		}
	}
	return 0;
}

//compute the square of the matrix kji
int mat_times_mat_kji( double * mat1, double* mat2, double* res, int n ) {
	for ( int k = 0; k < n; k ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			for ( int i = 0; i < n; i ++ ) {
				res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
			}
		}
	}
	return 0;
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
	double* mat1 = create_random_matrix(size);
	double* mat2 = create_random_matrix(size);
	double* res = create_rhs_matrix(size);

	cout << "time needed for initialization: " << stop_time_measuring(start_time)<<endl;

	if( strcmp(method, "normal") == 0) {
		cout << " Doing normal multiplication mode " <<endl;
//  		mat_times_mat_ijk(mat1, mat2, res, size);
        mat_times_mat_ikj(mat1, mat2, res, size);
//        mat_times_mat_jki(mat1, mat2, res, size);
//        mat_times_mat_jik(mat1, mat2, res, size);
//        mat_times_mat_kij(mat1, mat2, res, size);
//        mat_times_mat_kji(mat1, mat2, res, size);
	} else if (strcmp(method, "blocked") == 0) {

		// TODO Blocked method
	} else if (strcmp(method, "optimized") == 0) {
		// TODO optimized
	} else {
		cout << " Multiplication method not found ..." <<endl;
		return -1;
	}

	cout << "time needed for multiplication: " << stop_time_measuring(start_time)<<endl;
    
    free(mat1);
    free(mat2);
    free(res);
    return 0;
}



