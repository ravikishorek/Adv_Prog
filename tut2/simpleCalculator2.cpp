#include <iostream>
#include <cmath>

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
    std::cout<< "Enter the operator (valid entries +, -, *, /, m, s, c, t" <<std::endl;
    std::cin >> c;

    switch(c) {
        case 's':
            std::cout<< "Enter angle in degrees" <<std::endl;
            std::cin >> a;
            b = sin(a*M_PI/180);
            std::cout <<"Result is "<< b <<std::endl;
            break;

        case 'c':
            std::cout<< "Enter angle in degrees" <<std::endl;
            std::cin >> a;
            b = cos(a*M_PI/180);
            std::cout <<"Result is "<< b <<std::endl;
            break;
        case 't':
            std::cout<< "Enter angle in degrees" <<std::endl;
            std::cin >> a;
            b = tan(a*M_PI/180);
            std::cout <<"Result is "<< b <<std::endl;
            break;
        case '+':
            std::cout<< "Enter value 1" <<std::endl;
            std::cin >> a;
            std::cout<< "Enter value 2" <<std::endl;
            std::cin >> b;
            std::cout <<"Result is "<<sum(a,b)<<std::endl;
            break;
        case '-':
            std::cout<< "Enter value 1" <<std::endl;
            std::cin >> a;
            std::cout<< "Enter value 2" <<std::endl;
            std::cin >> b;
            std::cout <<"Result is "<<subtract(a,b)<<std::endl;
            break;
        case '*':
            std::cout<< "Enter value 1" <<std::endl;
            std::cin >> a;
            std::cout<< "Enter value 2" <<std::endl;
            std::cin >> b;
            std::cout <<"Result is "<<multiply(a,b)<<std::endl;
            break;
        case '/':
            std::cout<< "Enter value 1" <<std::endl;
            std::cin >> a;
            std::cout<< "Enter value 2" <<std::endl;
            std::cin >> b;
            std::cout <<"Result is "<<divide(a,b)<<std::endl;
            break;
        case 'm':
            std::cout<< "Enter value 1" <<std::endl;
            std::cin >> a;
            std::cout<< "Enter value 2" <<std::endl;
            std::cin >> b;
            std::cout <<"Result is "<<mean(a,b)<<std::endl;
            break;
        default:
            std::cout <<"Invalid operator entered" <<std::endl;
        }
    return 0;
}

