#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

typedef 
	std::chrono::time_point<std::chrono::system_clock> TimeStamp;

void printTiming(const TimeStamp& start, std::string operation) {
	TimeStamp end = std::chrono::system_clock::now();
	double t = std::chrono::duration<double>(end-start).count();
	std::cout<<"Time: "<<t<<" s (Operation: "<<operation<< ")" <<std::endl;
}

bool compare(const double& left, const double& right) {
    return (left<right);
}


int main(int argc, char *argv[]) {
	
    size_t size = 100000; //make this arbitrary / dynamic
    std::vector<double> v(size);
    std::default_random_engine generator;
    
	// start timing
	TimeStamp start = std::chrono::system_clock::now();
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double random_val = distribution(generator);
    double temp;
    for(std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i) {
        v[i-v.begin()] = distribution(generator);
    }
    std::sort(v.begin(), v.end(), compare);
	
	printTiming(start, "SORTING - STL");
	
	return 0;
}
