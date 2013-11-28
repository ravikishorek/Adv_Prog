
#include <iostream>
#include <cstdlib>
#include <cstring>
#define SIZE 1000
#define BLOCKSIZE 20

void print_matrix(int n, double *matrix) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            std::cout<<"  "<< matrix[i*n + j];
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char **argv)
{
    int n = SIZE;
    double *a, *b, *c;

    int mem_size;

    int i, j, k, kk, jj;
    int bsize = BLOCKSIZE;

    if(argc > 1){
        n = atoi(argv[1]);
    }
    if(argc > 2){
        bsize = atoi(argv[2]);
    }
    
    if( (n % bsize) != 0) {
        std::cout<<" Blocksize does not divide matrix size exactly. Choose correct parameters " <<std::endl;
    }
    mem_size = n * n * sizeof(double);
    a = (double*)malloc(mem_size);
    b = (double*)malloc(mem_size);
    c = (double*)malloc(mem_size);
    if(0 == a || 0 == b || 0 == c){
        std::cout<<"memory allocation failed"<<std::endl;
        return 0;
    }

    /* initialisation */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            *(a + i * n + j) = (double)i + (double)j;
            *(b + i * n + j) = (double)(n - i) + (double)(n - j);
        }
    }
    memset(c, 0, mem_size);

    // split the k and j loops into k, kk and j, jj with kk running from 0 to n 
    // with a jump of bsize and k running from kk -> kk+bsize
    for(kk = 0; kk < n; kk+=bsize){
        for(jj = 0; jj < n; jj+=bsize){
            for(i = 0; i < n; i++){
                for(j=jj; j<jj + bsize; j++) {
                    for (k = kk; k < kk + bsize; k++) {
                        c[i*n + j] += a[i*n + k] * b[k*n + j];
                    }

                }
            }
        }			
    }

    //	print_matrix(size, c);

    return(0);
}

