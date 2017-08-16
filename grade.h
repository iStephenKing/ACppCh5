#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <vector>

double grade(const Student_info& s);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
bool fgrade(const Student_info& s);
std::vector<Student_info> extract_fails(std::vector<Student_info>& students);

#endif