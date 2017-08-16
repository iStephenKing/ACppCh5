#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h
/*
    From Accellerated C++

    Student_info.h
    Stephen King
    8/12/17
*/

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& in, Student_info&s);
bool less_than(const Student_info& x, const Student_info& y);

#endif