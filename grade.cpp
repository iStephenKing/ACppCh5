/*
    From Accellerated C++

    grade.cpp
    Stephen King
    8/12/17
*/

#include "grade.h"
#include <stdexcept>
#include <vector>
#include "median.h"
#include "Student_info.h"

using std::vector; using std::domain_error;

// compute a students grade from midterm and final exam grades and homeword grades
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Computes a students grades from midterm, final, and homework grades
// Passes a pointer (reference) to homework vector
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(hw));
}

// Calculates a students grades
double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

// Determines if a Student has fail
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// Seperate failed students from vector and return vector of failed students
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    // Copy current Student into pass list or fail list
    vector<Student_info> fail;
    vector<Student_info>::size_type i = students.size();
    while ( i  > 0) {
        if (fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        --i;
        
    }
    

    return fail;
    
}