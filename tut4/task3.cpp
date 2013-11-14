
#include <iostream>


/* Recursive
int gcd(int a, int b) {
    if(b == 0){
        return a;
    } else {
        return (gcd(b, a % b));
    }
}
*/


/*
int gcd(int a, int b) {
    int temp = 0;
    do
    {
        temp = a;
        a = b;
        b = temp % b;
    }while(b != 0);

    return a;

}
*/

int gcd (int a, int b) {
    do {
        a = a % b;
        a = a+b;
        b = a - b;
        a = a - b;
    }while(b != 0);
    return a;

}

int main(){

    std::cout << "GCD of 39 and 169  is : "<< gcd(39,169)<< std::endl;
    return 0;

}
