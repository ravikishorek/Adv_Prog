#include <chrono>
#include <fstream>
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


class Name {
    public:
        Name(std::string first, std::string last) : firstName(first), lastName(last) { };
        std::string getFirstName() const {
            return firstName; };
        std::string getLastName() const {
            return lastName; };
    bool operator<(const Name &rhs) const {
        std::string temp1 = (firstName+" "+lastName);
        std::string temp2 = (rhs.firstName+" "+rhs.lastName);
        return ( temp1 < temp2 );  
    }
    private:
        std::string firstName;
        std::string lastName;
};


// general mergesort algorithm
template <class Iterator>
void bubblesort(Iterator first, Iterator last )
{
    bool finished = false;
    Iterator it, end = last - 1;
    while (!finished) {
        bool changed = false;
        for(it = first; it < end; ++it) {
            if( *(it+1) < *(it)) {
                std::swap(*it, *(it+1));
                changed = true;
            }
        }
        if (changed) {
            --end;
        } else {
            finished = true;
        }
    }
}

int main(int argc, char *argv[]) {

    size_t size = 10000; //make this arbitrary / dynamic
    std::vector<double> v(size);
    std::default_random_engine generator;
    std::vector<Name> name;
    // start timing
    TimeStamp start = std::chrono::system_clock::now();
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double random_val = distribution(generator);
    double temp;
    for(std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i) {
        v[i-v.begin()] = distribution(generator);
    }
    bubblesort(v.begin(), v.end());

    printTiming(start, "SORTING - BUBBLE VECTOR");
    std::ifstream file;
    file.open("namelist.txt");
    while(!file.eof()) {
        std::string firstName, lastName;
        file >> firstName;
        file >> lastName;
        Name n(firstName, lastName);
        // push it into the vector here
        name.push_back(n);
    }
    file.close();
    start = std::chrono::system_clock::now();
    // std::sort(name.begin(), name.end());
    bubblesort(name.begin(), name.end());
    printTiming(start, "SORTING - BUBBLE NAME VECTOR");
//    for(std::vector<Name>::const_iterator i = name.begin(); i != name.end(); ++i) {
  //     std::cout << (*i).getFirstName() <<" " << (*i).getLastName() <<std::endl;
   // }
    return 0;
}
