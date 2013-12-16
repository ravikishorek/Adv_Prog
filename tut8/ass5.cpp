#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

typedef 
std::chrono::time_point<std::chrono::system_clock> TimeStamp;

class Name {
    public:
        Name(std::string first, std::string last) : firstName(first), lastName(last) { };
        std::string getFirstName() const {
            return firstName; };
        std::string getLastName() const {
            return lastName; };

    private:
        std::string firstName;
        std::string lastName;
};
void printTiming(const TimeStamp& start, std::string operation) {
    TimeStamp end = std::chrono::system_clock::now();
    double t = std::chrono::duration<double>(end-start).count();
    std::cout<<"Time: "<<t<<" s (Operation: "<<operation<< ")" <<std::endl;
}

struct Compare_double
{
    bool operator()(const double& left, const double& right) {
        return( left < right );
    }
};

struct Compare_name
{
    bool operator()(const Name& first,  const Name& second) {
        std::string temp1 = (first.getFirstName()+first.getLastName());
        std::string temp2 = (second.getFirstName()+second.getLastName());
        return ( temp1 < temp2 );  
    }
};

template<typename Iterator>
void swap1(Iterator first, Iterator last)
{
    int temp;
    temp=*first;
    *first=*last;
    *last=temp;
    return;
}

template<typename Iterator, class Function>
void mergesort(Iterator first, Iterator last, Function compare)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    if(first==last) return; 
    if(first+1==last)  
    {
        if(!(compare(*last,*first))) {
        	Iterator temp = first;
        	*first = *last;
        	*last = *temp;
       	}
        return;
    }

    Iterator middle;
    middle=first+(last-first)/2;

    mergesort(first, middle, compare);
    mergesort(middle+1, last, compare);

    int a,b,pa,pb;
    std::vector<value_type> h;
        //the number of elements in a
    pa=middle-first+1; 
        //the number of elements in b
    pb=last-middle;    
         h.resize(pa+pb);
    a=0; b=0;

    while(a<pa && b<pb)
        if(compare(*(first+a),*(middle+1+b))) 
          {
              h[a+b]=*(first+a); a++;
          }
        else
          {
              h[a+b]=*(middle+1+b); b++;
          }

    while(a<pa) 
       {
           h[a+b]=*(first+a); a++;
       }
    while(b<pb)
       {
           h[a+b]=*(middle+1+b); b++;
       }

    for(int i=0;i<((a+b)-1);i++)
    *(first+i)=h[i];

    return;
}

int main(int argc, char *argv[]) {

    size_t size = 10; //make this arbitrary / dynamic
    std::vector<double> v(size);
    std::default_random_engine generator;
    std::vector<Name> name;

    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double random_val = distribution(generator);
    double temp;
    for(std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i) {
        v[i-v.begin()] = distribution(generator);
    }
    // start timing
    TimeStamp start = std::chrono::system_clock::now();
    // std::sort(v.begin(), v.end(), Compare_double());
    for(std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i) {
        std::cout<<*i<<std::endl;
    }
    
    std::cout<< "sorting now" <<std::endl;
    mergesort(v.begin(),v.end(), Compare_double());     
    //mergesort(v.begin(), v.size(), Compare_double());
    for(std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i) {
        std::cout<<*i<<std::endl;
    }

    printTiming(start, "DOUBLE SORTING - STL");
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
    std::sort(name.begin(), name.end(), Compare_name());
    // mergesort(name.begin(), name.size(), Compare_name());
    printTiming(start, "NAME SORTING - STL");
    return 0;
}
