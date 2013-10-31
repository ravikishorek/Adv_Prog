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

int power(int a, int b){
    int sum = 1;

    for(int i=0;i< b;i++)
    {
        sum*= a;
    }
    return sum;
}

int base(int a, int b) {
    int res = 0, rem = a,i=0;
    while (a >= b) {
        rem = a % b;
        a = a / b;
        res = rem*power(10,i) + res;
        i++;
    }
    res = res + (a%b)*power(10,i);
    return res;
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

        case 'b':
            std::cout<< "Enter value in base 10" <<std::endl;
            std::cin >> a;
            std::cout<< "Enter value of output base" <<std::endl;
            std::cin >> b;
            std::cout <<"Result is "<<base(a,b)<<std::endl;
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

