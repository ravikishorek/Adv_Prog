#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926

double my_func(double param){
    double result; 
    
    result = sin( param * PI / 180 );
//    result = param * param;
    return result;
}

double differenceQuotient(double (*f)(double), double x_0, double h = 1e-8 ){
    double d_f;
    double x_1;

    x_1 = x_0 + h;
    d_f = (f(x_1) - f(x_0)) / h;
 
    return d_f;
}

int main(int argc, char **argv){
    double param, d_f;
    double (*foo)(double);
    
    cout<<"please input parameter you want to calculate in the function"<<endl;
    cin>> param;
    foo = &my_func;
 
    d_f = differenceQuotient(foo, param);
    
    cout<<"Difference Quotient is: "<< d_f <<endl;      
    return 0;
}
