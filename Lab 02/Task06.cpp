//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

struct Student{
    string name;
    int rollNumber;
    float marks[3];
};

float calculateAverage(float marks[]){
    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum/3;
}

int main(){
    int numofStudents;

    cout << "Enter the number of students: ";
    cin >> numofStudents;

    Student* students = new Student[numofStudents];

    for (int i = 0; i < numofStudents; i++)
    {
        cout << "Enter student details " << i+1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;

        cout << "Enter marks in 3 subjects: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter marks for " << j+1 << ": ";
            cin >> students[i].marks[j];
        }
    }

    cout << "Student Records:" << endl;
    for (int i = 0; i < numofStudents; i++)
    {
        cout << "Records of " << i+1 << " student: "<<endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Marks: " << students[i].marks[0] << ", " << students[i].marks[1] << ", " << students[i].marks[2] << endl;
        cout << "Average Marks: " << calculateAverage(students[i].marks) << endl;
    }

    delete[] students;

    return 0;
}
