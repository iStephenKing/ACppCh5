/*
    From Acellerated C++
 
    Student_info.cpp
    Stephen King
    8/12/17
 */

#include "Student_info.h"

using std::istream; using std::vector; using std::endl;

// Predicate used to sort Students
bool less_than(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

// Read homework grades into hw vector
istream& read_hw(istream& in, vector<double>& hw)
{
    // use input stream to read grades into hw
    if (in) {
        // Empty Vector of any previous results
        hw.clear();
        
        // Read homework grades until EOF or invalid data
        double x;
        while (in >> std::dec >> x)
            hw.push_back(x);
        
        // Clear Error state for next read attempt
        in.clear();
    }
    
    return in;
}

// Read and store the students name and grades
istream& read(istream& in, Student_info&s)
{
    // Read Students name, midterm and final grades
    in >> s.name >> s.midterm >> s.final;
    //std::cout << endl << "Name = " << s.name;
    
    // Read Students homework grades
    read_hw(in, s.homework);
    
    return in;
}