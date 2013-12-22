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

template<class ForwardIterator, class OutputIterator>
void mergelists
(
    ForwardIterator first1,     // starting iterator of first sequence
    ForwardIterator last1,      // ending iterator of first sequence
    ForwardIterator first2,     // starting iterator of second sequence
    ForwardIterator last2,      // ending iterator of second sequence
    OutputIterator out1 )        // output iterator for results
{
    while (first1 != last1 && first2 != last2)
    {
        // note the opposing less-comparison. equtes to (i1 <= i2)
        while (first1 != last1 && !(*first2 < *first1))
            *out1++ = *first1++;

        if (first1 != last1)
        {
            while (first2 != last2 && (*first2 < *first1))
                *out1++ = *first2++;
        }
    }

    // doesn't really matter which one finished first
    //  only one of these will put one or more final
    //  nodes into the sequence.
    while (first1 != last1)
        *out1++ = *first1++;
    while (first2 != last2)
        *out1++ = *first2++;
}

// general mergesort algorithm
template <class Iterator>
void mergesort(Iterator first, size_t d )
{
    typedef class std::iterator_traits<Iterator>::value_type value_type;

    Iterator last = first + d;
    size_t n = d/2;
    if (n == 0)
        return;

    if (n > 1) // no single elements
        mergesort(first, n);
    if (d > 1) // no single elements
        mergesort(first+n, d-n);

    // merge back into local sequence
    std::vector<value_type> vals;
    vals.reserve(d);
    mergelists(first, first+n, first+n, last, back_inserter(vals));

    // and copy into where it all began
    std::copy(vals.begin(), vals.end(), first);
}

int main(int argc, char *argv[]) {

    size_t size = 100000; //make this arbitrary / dynamic
    std::vector<double> v(size);
    std::default_random_engine generator;
    std::vector<Name> name;
    std::vector<Name> *name_p = new std::vector<Name>();
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    
    double random_val = distribution(generator);
    double temp;
    
    /*****************************  DOUBLE VECTOR ***************/
    
    // Initialize the double vector
    for(std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i) {
        v[i-v.begin()] = distribution(generator);
    }
    TimeStamp start = std::chrono::system_clock::now();
    std::sort(v.begin(), v.end());  // sort
    // mergesort(v.begin(), v.size());
    printTiming(start, "SORTING - STL");
 
    /*********************   NAME VECTOR *************/

    // Read from file and store into the Name vector
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
    mergesort(name.begin(), name.size());
    printTiming(start, "SORTING - STD NAME");
    //for(std::vector<Name>::const_iterator i = name.begin(); i != name.end(); ++i) {
        // std::cout << (*i).getFirstName() <<" " << (*i).getLastName() <<std::endl;
    //}

    /******************** NAME VECTOR POINTER *************/

    // pointer of vector
    file.open("namelist.txt");
    while(!file.eof()) {
        std::string firstName, lastName;
        file >> firstName;
        file >> lastName;
        Name n(firstName, lastName);
        // push it into the vector here
        name_p->push_back(n);
    }
    file.close();
    
    start = std::chrono::system_clock::now();
    mergesort(name_p->begin(), name_p->size());
    printTiming(start, "SORTING - MERGE NAME POINTER");
    
    //for(std::vector<Name>::const_iterator i = name_p->begin(); i != name_p->end(); ++i) {
        // std::cout << (*i).getFirstName() <<" " << (*i).getLastName() <<std::endl;
    //}
    delete name_p;
    return 0;
}
