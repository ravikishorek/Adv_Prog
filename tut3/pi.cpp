#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

float random_var(){
	return (float)random() / ( float ) RAND_MAX;
}

void printPurpose(){
	cout << "This program is going to calculate pi value." << endl;
}

int validCounter(int max){
	int counter = 0;
	
	for(int i = 0; i < max; i++){
		float x = random_var();
		float y = random_var();
		if (( x * x + y * y ) <= (float)1)
			counter++;
	}

	return counter;
}

void piPrint(int max, int counter){
	std::cout << "Sampling points: " << max << std::endl;
	std::cout << "Outer sampling points: " << counter << std::endl;
	std::cout << "Pi: " << (float)4*((float)counter/(float)max) << std::endl;
}

int main(int argc, char *argv[]){
	int max = 10000000;
	int counter;
	
	unsigned int maxNumber;

	printPurpose();
	counter = validCounter(max);
	piPrint(max, counter);

	return 0;
}
