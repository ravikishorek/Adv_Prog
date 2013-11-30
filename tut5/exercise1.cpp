#include <iostream>
#include <stdint.h>

#define PRINT_VARIABLE_DETAILS(var) std::cout <<" Argument name is  " << #var <<  " address is  "\
<< &var  << " size is  " <<sizeof(var)<< "  alignment is  " << calc_mem_align(&var) <<std::endl;

#define PRINT_CHAR_DETAILS(var) std::cout<<" Argument name is  " << #var << " address is  " \
<< static_cast<void *>(&var) <<" Size is  "<< sizeof(var) <<"  Alignment is  "\
<<calc_mem_align(static_cast<void *>(&var))<<std::endl;

#define PRINT_FUNC_DETAILS(var) std::cout<<" Argument name is  " << #var << " address is  " \
<< reinterpret_cast<void *>(&var) <<"   Size is   "<< sizeof(reinterpret_cast<size_t>(&var))<< "  Alignment is  "\
<<calc_mem_align(reinterpret_cast<void *>(&var))<<std::endl;

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

void test_func() {
    int int_a;
    double dbl_c;
    int int_b;
    double dbl_d;
    char chr_e;
    double dbl_k;
    char chr_f;
    int int_h;
    char chr_g;
    int int_i;
    PRINT_FUNC_DETAILS(test_func);
    PRINT_VARIABLE_DETAILS(int_a);
    PRINT_VARIABLE_DETAILS(int_b);
    PRINT_VARIABLE_DETAILS(int_h);
    PRINT_VARIABLE_DETAILS(int_i);

    PRINT_VARIABLE_DETAILS(dbl_c);
    PRINT_VARIABLE_DETAILS(dbl_d);
    PRINT_VARIABLE_DETAILS(dbl_k);
    PRINT_CHAR_DETAILS(chr_e);
    PRINT_CHAR_DETAILS(chr_f);
    PRINT_CHAR_DETAILS(chr_g);
    
}
void test_func2() {
    int int_a, int_b;
    double dbl_c, dbl_d, dbl_k;
    char chr_e, chr_f,chr_g;
    int int_h, int_i;
    PRINT_FUNC_DETAILS(test_func);
    PRINT_VARIABLE_DETAILS(int_a);
    PRINT_VARIABLE_DETAILS(int_b);
    PRINT_VARIABLE_DETAILS(int_h);
    PRINT_VARIABLE_DETAILS(int_i);

    PRINT_VARIABLE_DETAILS(dbl_c);
    PRINT_VARIABLE_DETAILS(dbl_d);
    PRINT_VARIABLE_DETAILS(dbl_k);
    PRINT_CHAR_DETAILS(chr_e);
    PRINT_CHAR_DETAILS(chr_f);
    PRINT_CHAR_DETAILS(chr_g);
    
}
int main(int argc, char *argv[]) {
    test_func();
    std::cout<<"Second call to function"<<std::endl;
    test_func();
    return 0;
}
