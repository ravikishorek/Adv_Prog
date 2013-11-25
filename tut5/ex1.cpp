#include <iostream>
#include <cstdint>

int calc_mem_align(void *address) {
    uintptr_t test_ptr = reinterpret_cast<uintptr_t>(address);
    int res = 1;
    int align = 2;
    while((test_ptr % align) == 0) {
        res = align;
        align *= 2;     
    }
    return res;
}

void test_func(int a, double b, char c) {
    int d;
    double e;
    char f;
    std::cout<<"Int a: Address is  "<< &a <<"   Size is   "<< sizeof(a) <<"   Alignment is   "<<calc_mem_align(&a)<<std::endl;
    std::cout<<"Double b: Address is   "<< &b <<"   Size is   "<< sizeof(b) <<"   Alignment is   "<<calc_mem_align(&b)<<std::endl;
    std::cout<<"Char c: Address is   "<< static_cast<void *>(&c) <<"   Size is   "<< sizeof(c) <<"  Alignment is   "<<calc_mem_align(static_cast<void *>(&c))<<std::endl;
    std::cout<<"Int d: Address is  "<< &d <<"   Size is   "<< sizeof(d) <<"   Alignment is   "<<calc_mem_align(&d)<<std::endl;
    std::cout<<"Double e: Address is   "<< &e <<"   Size is   "<< sizeof(e) <<"   Alignment is   "<<calc_mem_align(&e)<<std::endl;
    std::cout<<"Char f: Address is   "<< static_cast<void *>(&f) <<"   Size is   "<< sizeof(f) <<"  Alignment is   "<<calc_mem_align(static_cast<void *>(&f))<<std::endl;

}
int main(int argc, char *argv[]) {
    test_func(1,2.0,'c');
    return 0;
}
