#include <iostream>

using namespace std;

double interPolation(double x_a, double x_b, double y_a, double y_b, double y_r){
    double x_r;

    x_r = x_a + (y_r - y_a)*(x_b-x_a) / (y_b - y_a);    
//    y_r = y_a + (( y_b - y_a ) * ( x_r - x_a )) / ( x_b - x_a );
    return x_r;
}

void printPurpose(){
    cout<<"Linear Interpolation Caculator"<<endl;
    cout<<"Please input variables you need for interpolation function:"<<endl;
    cout<<" y_r = y_a + ( y_b - y_a ) * ( x_r - x_a ) / ( x_b - x_a )"<<endl;
    cout<<"x_r---unknown value"<<endl;
}

int main(int argc, char **argv){
    double x_a, x_b, y_a, y_b, y_r, x_r;
    int flag;
    
    flag = 0;

    printPurpose();
    
    while(!flag){
        cout<<"Please input x_a:"<<endl;
        cin>>x_a;
        cout<<"Please input x_b:"<<endl;
        cin>>x_b;
        cout<<"Please input y_a:"<<endl;
        cin>>y_a; 
        cout<<"Please input y_b:"<<endl;
        cin>>y_b; 
        cout<<"Please input y_r:"<<endl;
        cin>>y_r;
        
        if(x_b == x_a){
            cout << "error: please input different value of x_a and x_b."<<endl;
            flag = 0;
        }
        flag = 1;
    }
    
    x_r = interPolation(x_a, x_b, y_a, y_b, y_r);
    cout<<"x_r ="<<x_r<<endl;

    return 0;
}
