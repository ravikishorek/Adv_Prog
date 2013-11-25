#include <iostream>
#include <cstdint>


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

size_t size_of_stack(int n, size_t top_of_stack) {
    char a[PAYLOAD_SIZE];
    PRINT_CHAR_DETAILS(a[0]);
    if( n > 0) {
        return size_of_stack(n-1, top_of_stack);
    } else {
        return top_of_stack - (size_t) &a[0];
    }
}

int main() {
    size_t top_of_stack;
    int x = 0;
    top_of_stack = (size_t) &x;
    std::cout<<"size is "<<size_of_stack(5, top_of_stack)<<std::endl;
    return 0;
}

