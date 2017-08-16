/*
    From Accellerated C++

    We are calculated grades again, but now we use functions and later structs it sounds like

    Stephen King
    08/08/2017
*/
#include <iomanip>
#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "grade.h"
#include "Student_info.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // Read and store all records, find length of longest name
    cout << "Enter Student Names and Grades" << endl;
    while (read(cin, record)) {
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    cout << endl;
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    // Compute Students Grade
    vector<Student_info> failed_students;
    try {
        failed_students = extract_fails(students);
    } catch (domain_error e) {
        cout << e.what();
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    cout << "--Passed--" << endl;
    if (students.size())
        for (vector<Student_info>::size_type i = 0; i < students.size(); ++i)
            cout << students[i].name << endl;
    else
        cout << "None" << endl;
    cout << endl;
    cout << "--Failed--" << endl;
    if (failed_students.size())
        for (vector<Student_info>::size_type i = 0; i < failed_students.size(); ++i)
            cout << failed_students[i].name << endl;
    else
        cout << "None" << endl;
    
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << endl << "Computation time: " << duration << "us" << endl;
    return 0;
    
}