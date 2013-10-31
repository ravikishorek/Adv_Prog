#include <iostream>

double sum(double a, double b) {
    return (a+b);
}
double subtract(double a, double b) {
    return (a-b);
}
double multiply(double a, double b) {
    return (a*b);
}
double divide(double a, double b) {
    return (a/b);
}
double mean(double a, double b) {
    return (a+b)/2.0;
}

int main(int argc, char* argv[]) {
    double a, b;
    char c;
    std::cout<< "Enter value 1" <<std::endl;
    std::cin >> a;
    std::cout<< "Enter value 2" <<std::endl;
    std::cin >> b;
    std::cout<< "Enter the operator (valid entries +, -, *, /, m" <<std::endl;
    //c = getc();
    std::cin >> c;
    // Check if the operator belongs to the set and call function
    if( c == '+') {
        std::cout<<"Result is "<<sum(a,b)<<std::endl;
    } else if( c == '-') {
        std::cout<<"Result is "<<subtract(a,b)<<std::endl;
    } else if( c == '*') {
        std::cout<<"Result is "<<multiply(a,b)<<std::endl;
    } else if( c == '/') {
        std::cout<<"Result is "<<divide(a,b)<<std::endl;
    } else if( c == 'm') {
        std::cout<<"Result is "<<mean(a,b)<<std::endl;
    } else {
        std::cout <<"Invalid operator entered" <<std::endl;
    }
    return 0;
}

