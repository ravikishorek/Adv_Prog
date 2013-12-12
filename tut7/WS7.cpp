//============================================================================
// Name        : WS7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <immintrin.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory>

using namespace std;

#define N 1000
#define ALIGN 3

#define ALIGNED_ALLOC
#define AUTO

// icc: -fast , -xavx
// gcc: -ftree-vec...

//check mem alignment
int calc_mem_align(void *address) {
    size_t test_ptr = reinterpret_cast<size_t>(address);
    int res = 1;
    int align = 2;
    while((test_ptr % align) == 0) {
        res = align;
        align *= 2;
    }
    return res;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "test" <<endl;

#ifdef ALIGNED_ALLOC
	float* b = (float*) memalign( ALIGN, 4*N);
	float* a = (float*) memalign( ALIGN, 4*N);
	float* c = (float*) memalign( ALIGN, 4*N );
#else
	float* a = ( float* ) malloc(  N * sizeof (float) );
	float* b = ( float* ) malloc(  N * sizeof (float) );
	float* c = ( float* ) malloc(  N * sizeof (float) );
#endif

	cout << "alignment a: " << calc_mem_align(a) <<endl;
	cout << "alignment b: " << calc_mem_align(b) <<endl;
	cout << "alignment c: " << calc_mem_align(c) <<endl;

	//fill arrays
	for (int i = 0; i < N; i ++) {
		a[i] = (float) i;
		b[i] = (float) i;
		c[i] = (float) i;
	}


#ifdef AUTO
#pragma vector aligned
	for(int i = 0; i < N; i++ ){
		c[i] = a[i] + b[i];
	}
#else
	__m256 a_i;
	__m256 b_i;
	__m256 out_i;

	for(int i = 0; i < N; i += 8)
	{
		// Read 8 floats from a to a_i, and b to b_i.
		a_i = _mm256_load_ps(&a[i]);
		b_i = _mm256_load_ps(&b[i]);

		// Compute out_i = a_i + b_i.
		out_i = _mm256_add_ps(a_i, b_i);

		// Write 8 floats from out_i to out.
		_mm256_store_ps(&c[i], out_i);
	}
#endif


	cout << a[N-1] << "  " << b[N-1] << c[N-1] <<endl;
	return 0;
}


/*
	float a[N] ;
	float b[N] ;
	float c[N] ;
*/
	/*
	float* a = (float*) _mm_malloc( 4*N,ALIGN);
	float* b= (float*) _mm_malloc( 4*N,ALIGN);
	float* c= (float*) _mm_malloc( 4*N,ALIGN);
*/
	/*
	float* a = (float*) aligned_alloc(ALIGN, 4*N);
	float* b= (float*) aligned_alloc(ALIGN, 4*N);
	float* c= (float*) aligned_alloc(ALIGN, 4*N);
	*/
