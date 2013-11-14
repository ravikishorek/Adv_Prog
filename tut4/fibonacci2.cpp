#include <iostream>

int fibonacci(int term, int &a, int &b);

int main() {
    int i,num;
    std::cout<<"Please enter the no. of terms in fibonacci series" <<std::endl;
    std::cin>> num;

    std::cout<<"The fibonacci series is - 0 1";
    int a = 0,b = 1;    
    fibonacci(num,a,b);
    std::cout<<" " <<std::endl;
    return 0;
}

int fibonacci(int num, int &a, int &b)
{
     if(num > 0) {
         int sum = a + b;
         a = b;
         b = sum;
         std::cout<<" "<<sum;
         fibonacci(num-1,a,b);

     }
}
    
