#include <iostream>

int fibonacci(int num);

int main() {
    int i,num;
    std::cout<<"Please enter the no. of terms in fibonacci series" <<std::endl;
    std::cin>> num;

    std::cout<<"The fibonacci series is - ";
        
    for(i=0; i<= num; i++)
    std::cout<<" "<<fibonacci(i);
    std::cout<<" " <<std::endl;
    return 0;
}

int fibonacci(int num) {
    if(num < 2) {
        return 1;
    } else {
        return fibonacci(num-1) + fibonacci(num-2);
    }
}
    
