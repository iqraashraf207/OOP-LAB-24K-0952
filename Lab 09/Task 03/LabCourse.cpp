//Name: Iqra Ashraf
//Roll number: 24K-0952

#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int cr, double lab, double proj) : Course(code, cr), labTasks(lab), project(proj) {}

void LabCourse::calculateGrade() {
    double finalGrade = (labTasks * 0.5) + (project * 0.5);
    cout << "Final Grade (Lab): " << finalGrade << endl;
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << " | Credits: " << credits << endl;
}