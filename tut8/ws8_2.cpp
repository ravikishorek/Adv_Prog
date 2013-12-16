#include <fstream>
#include <chrono>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <random>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef chrono::time_point< chrono::system_clock> TimeStamp;

class Name{
    public:
        Name(string first, string last):firstName(first), lastName(last){};

        string getFirstName() const{
            return firstName;
        };

        string getLastName() const{
            return lastName;
        }

    private:
        string firstName;
        string lastName;
};

struct name_compare{
    bool operator() (const Name& name1, const Name& name2){
        return (name1.getFirstName() < name2.getFirstName());
    }
};

bool compare(const double &left, const double &right){
    return (left < right);
}

void SplitMerge(vector<double> &, vector<double>::iterator &, vector<double>::iterator &, vector<double> &);

void Merge(vector<double> &, vector<double>::iterator &, vector<double>::iterator &, vector<double>::iterator &, vector<double> &);

void NameSplitMerge(vector<Name> &, vector<Name>::iterator &, vector<Name>::iterator &, vector<Name> &);

void NameMerge(vector<Name> &, vector<Name>::iterator &, vector<Name>::iterator &, vector<Name>::iterator &, vector<Name> &);

void printTiming(const TimeStamp& start, string operation){
    TimeStamp end = chrono::system_clock::now();
    double t= chrono::duration<double>(end-start).count();
    cout<<"Time: "<< t << " s (Operation: " << operation << ")" <<endl;
}

vector<double> vecGenerator(int length){
    vector<double> vec;
    int i;
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    // display the original size of vec
    vec.resize(length);

    // push values into the vector
    for(vector<double>::iterator it=vec.begin(); it!=vec.end(); ++it){
        vec[it-vec.begin()] = distribution(generator);
    }
    return vec;
}

void MergeSort(int n, vector<double> &A, vector<double> &B){
    vector<double>::iterator iBegin= A.begin();
    vector<double>::iterator iEnd=A.end();
    SplitMerge(A, iBegin, iEnd, B);

}

void SplitMerge(vector<double> &A, vector<double>::iterator &iBegin, vector<double>::iterator &iEnd, vector<double> &B)
{
    vector<double>::iterator iMiddle;

    if((iEnd - iBegin) < 2){
        //cout<<"merge finshed!"<<endl;
        return;    //   consider it sorted
    }                       

    iMiddle = iBegin+distance(iBegin,iEnd)/2;

    SplitMerge(A, iBegin,  iMiddle, B);  // split / merge left  half
    SplitMerge(A, iMiddle, iEnd, B);  // split / merge right half
    Merge(A, iBegin, iMiddle, iEnd, B);  // merge the two half runs
    A=B;
}

void Merge(vector<double> &A, vector<double>::iterator &iBegin, vector<double>::iterator &iMiddle, vector<double>::iterator &iEnd, vector<double> &B)
{
    vector<double>::iterator i0;
    vector<double>::iterator i1;
    vector<double>::iterator j;

    i0 = iBegin, i1 = iMiddle;
    // While there are elements in the left or right runs
    for (j = iBegin; j < iEnd; j++) {
        // If left run head exists and is <= existing right run head.
        if (i0 < iMiddle && (i1 >= iEnd || *i0 <= *i1)){
            B[j-A.begin()] = *i0;  // Increment i0 after using it as an index.
            i0=i0+1;
        }
        else{
            B[j-A.begin()] = *i1;  // Increment i1 after using it as an index.
            i1=i1+1;
        }
    }
}

void NameMergeSort(int n, vector<Name> &A, vector<Name> &B)
{
    vector<Name>::iterator iBegin= A.begin();
    vector<Name>::iterator iEnd=A.end();
    NameSplitMerge(A, iBegin, iEnd, B);

}

void NameSplitMerge(vector<Name> &A, vector<Name>::iterator &iBegin, vector<Name>::iterator &iEnd, vector<Name> &B)
{
    vector<Name>::iterator iMiddle;

    if((iEnd - iBegin) < 2){
        //cout<<"merge finshed!"<<endl;
        return;    //   consider it sorted
    }                       

    iMiddle = iBegin+distance(iBegin,iEnd)/2;

    NameSplitMerge(A, iBegin,  iMiddle, B);  // split / merge left  half
    NameSplitMerge(A, iMiddle, iEnd, B);  // split / merge right half
    NameMerge(A, iBegin, iMiddle, iEnd, B);  // merge the two half runs
    A=B;
}

void NameMerge(vector<Name> &A, vector<Name>::iterator &iBegin, vector<Name>::iterator &iMiddle, vector<Name>::iterator &iEnd, vector<Name> &B)
{
    vector<Name>::iterator i0;
    vector<Name>::iterator i1;
    vector<Name>::iterator j;

    i0 = iBegin, i1 = iMiddle,j = iBegin;
    // While there are elements in the left or right runs
    for (j = iBegin; j < iEnd; j++) {
        // If left run head exists and is <= existing right run head.
        if (i0 < iMiddle && (i1 >= iEnd || i0->getFirstName() <= i1->getFirstName())){
            B[j-A.begin()] = *i0;  // Increment i0 after using it as an index.
            i0=i0+1;
        }
        else{
            B[j-A.begin()] = *i1;  // Increment i1 after using it as an index.
            i1=i1+1;
        }
    }
}

void printVec(vector<double> vec){
    cout << "myvector contains:"<<endl;
    for(vector<double>::iterator it=vec.begin(); it!=vec.end(); ++it){
        cout<<" " <<*it;
    }
    cout <<endl;
}

int main () {
    double j;
    int length;
    vector<double> vec;
    //double* A;

    cout << "Specify array length" << endl;
    cin >> length;
    cout << "\n";

    /**  generate vector & std sort*/
    TimeStamp start1 = chrono::system_clock::now();
    vec = vecGenerator(length);

    sort(vec.begin(), vec.end(), compare);
    //printVec(vec);
    printTiming(start1, "std::sort");
    /***************************************************************/

    /**  generate vector & std sort*/
    TimeStamp start2 = chrono::system_clock::now();
    vec = vecGenerator(length);

    vector<double> sorted = vec;   //work vector ensure has the same size of the original vector

    MergeSort(length, vec, sorted);

    //printVec(vec);
    printTiming(start2, "merge_sort");
    /***************************************************************/

    /** reading file from the file in namelist */
    TimeStamp start3 = chrono::system_clock::now();
    ifstream file;
    file.open("namelist.txt");

    int counter=0;
    vector<Name> strvec;
    while (!file.eof()){
        string firstName, lastName;
        file >> firstName;
        file >> lastName;
        Name n(firstName,lastName);
        strvec.push_back(Name(firstName,lastName));
        counter=counter+1;
    }
    file.close();
    vector<Name> strvec_merge = strvec;
    cout<<"total number of namelist"<<counter<<endl;
    sort(strvec.begin(),strvec.end(), name_compare());
    printTiming(start3, "std::sort namelist");
    /***************************************************************/

    TimeStamp start4 = chrono::system_clock::now();
    vector<Name> strsorted = strvec_merge;
    NameMergeSort(counter, strvec_merge, strsorted);
    printTiming(start4, "merge_sort namelist");
    //    for(Name i: strvec_merge)
    //    {
    //        cout<<i.getFirstName()<<" "<<i.getLastName()<<endl;
    //    }    
    return 0;
}
