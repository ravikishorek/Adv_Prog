#include <iostream>
struct Square
{
    double operator()(double number) { return number * number; }
};

template <class Function>
double integrate(Function& f, double a, double b, unsigned int intervals)
{
    double delta = (b - a) / intervals, sum = 0.0;

    while(a < b)
    {
    	sum += f(a) * delta;
    	a += delta;
    }

    return sum;
}
int main() {
	std::cout << "interval : " << i << tab << tab << "intgeration = "
 << integrate(Square(), 0.0, 1.0, 10) << std::endl;
}
