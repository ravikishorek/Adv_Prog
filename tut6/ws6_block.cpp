/*
 * ws6.cpp
 *
 *  Created on: 30.11.2013
 *      Author: Xiao Xue
 */

#include <iostream>
#include <time.h> //for measuring time

#define SIZE 1024
#define BLOCKSIZE 1024

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
double* create_random_matrix(int n) {
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

//compute the square of the matrix ijk
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

//compute the cache-blocking optimization for matrix*matrix
int mat_times_mat_block( double * mat1, double* mat2, double* res, int n, int bsize ) {
    for(int kk = 0; kk < n; kk+=bsize){
        for(int jj = 0; jj < n; jj+=bsize){
            for(int i = 0; i < n; i++){
                for(int j=jj; j<jj + bsize; j++) {
                    for (int k = kk; k < kk + bsize; k++) {
                        res[i*n + j] += mat1[i*n + k] * mat2[k*n + j];
                    }
                    
                }
            }
        }			
    }
//	for ( int ii = 0; ii < n; ii += bsize ) {
//		for ( int jj = 0 ; jj < n ; jj += bsize ) {
//			for ( int k = 0; k < n; k ++ ) {
//                for (int i=ii; i<ii+bsize; i++) {
//                    for (int j= jj; j<jj+bsize; j++) {
//                        res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
//                    }
//                }
//			}
//		}
//	}
	return 0;
}

int mat_times_mat_block_2( double * mat1, double* mat2, double* res, int n, int bsize ) {
    	for ( int ii = 0; ii < n; ii += bsize ) {
    		for ( int jj = 0 ; jj < n ; jj += bsize ) {
                for (int i=ii; i<ii+bsize; i++) {
                    for (int j= jj; j<jj+bsize; j++) {
                        for ( int k = 0; k < n; k ++ ) {
                            res[i*n+j] += mat1[i*n+k] * mat2[k*n+j];
                        }
                    }
    			}
    		}
    	}
	return 0;
}

int main( int argc, char *argv[]) {
	cout << " Doing some matrix multiplications " <<endl;

	if (argc != 2 ) {
		cout <<" use like this: <type> where type can be <normal>, <blocked> or <optimized> "<<endl;
		return -1;
	}

	int size = SIZE;
	char *method = argv[1];
    int bsize = BLOCKSIZE;
    
    cout<<"bsize="<<bsize<<endl;
	
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
  		//mat_times_mat_kji(mat1, mat2, res, size);
        mat_times_mat_ijk(mat1, mat2, res, size);
	} else if (strcmp(method, "blocked") == 0) {
        cout << " Doing block-wise multiplication mode " <<endl;
		//mat_times_mat_block(mat1, mat2, res, size, bsize);
        mat_times_mat_block_2(mat1, mat2, res, size, bsize);
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



