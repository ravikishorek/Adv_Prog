#include <iostream>
#include <stdint.h>

#define PRINT_VARIABLE_DETAILS(var) std::cout <<" argument name is  " << #var <<  " address is  "\
<< &var  << " size is  " <<sizeof(var)<< "  alignment is  " << calc_mem_align(&var) <<std::endl;

#define PRINT_CHAR_DETAILS(var) std::cout<<" arguemnt name is  " << #var << " address is  " \
<< static_cast<void *>(&var) <<"   Size is   "<< sizeof(var) <<"  Alignment is  "\
<<calc_mem_align(static_cast<void *>(&var))<<std::endl;

#define PRINT_FUNC_DETAILS(var) std::cout<<" arguemnt name is  " << #var << " address is  " \
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
    double double_c;
    int int_b;
    double double_d;
    char char_e;
    double double_k;
    char char_f;
    int int_h;
    char char_g;
    int int_i;
    PRINT_FUNC_DETAILS(test_func);
    PRINT_VARIABLE_DETAILS(int_a);
    PRINT_VARIABLE_DETAILS(int_b);
    PRINT_VARIABLE_DETAILS(int_h);
    PRINT_VARIABLE_DETAILS(int_i);

    PRINT_VARIABLE_DETAILS(double_c);
    PRINT_VARIABLE_DETAILS(double_d);
    PRINT_VARIABLE_DETAILS(double_k);
    PRINT_CHAR_DETAILS(char_e);
    PRINT_CHAR_DETAILS(char_f);
    PRINT_CHAR_DETAILS(char_g);
    
}
void test_func2() {
    int int_a, int_b;
    double double_c, double_d, double_k;
    char char_e, char_f,char_g;
    int int_h, int_i;
    PRINT_FUNC_DETAILS(test_func);
    PRINT_VARIABLE_DETAILS(int_a);
    PRINT_VARIABLE_DETAILS(int_b);
    PRINT_VARIABLE_DETAILS(int_h);
    PRINT_VARIABLE_DETAILS(int_i);

    PRINT_VARIABLE_DETAILS(double_c);
    PRINT_VARIABLE_DETAILS(double_d);
    PRINT_VARIABLE_DETAILS(double_k);
    PRINT_CHAR_DETAILS(char_e);
    PRINT_CHAR_DETAILS(char_f);
    PRINT_CHAR_DETAILS(char_g);
    
}
int main(int argc, char *argv[]) {
    test_func();
    std::cout<<"Second call to function"<<std::endl;
    test_func();
    return 0;
}
