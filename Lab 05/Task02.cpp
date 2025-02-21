//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    int ID;
    string name;
    int* scores;
    int numOfScores;

    Student(int id, string n, int* sc, int num) {
        ID = id;
        name = n;
        numOfScores = num;
        scores = new int[numOfScores];

        for (int i = 0; i < numOfScores; i++)
        {
            scores[i] = sc[i];
        }
    }

    Student(const Student &obj) {
        ID = obj.ID;
        name = obj.name;
        numOfScores = obj.numOfScores;
        scores = new int[numOfScores];

        for (int i = 0; i < numOfScores; i++)
        {
            scores[i] = obj.scores[i];
        }
    }

    void display() {
        cout << "Student ID: " << ID << ", Name: " << name << ", Scores: ";
        for (int i = 0; i < numOfScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int score1[] = {56, 78, 80};
    Student s1(20, "Hamza", score1, 2);

    cout << "Original Student Record:" << endl;
    s1.display();

    Student s2(s1);
    cout << "Duplicate Record for Verification:" << endl;
    s2.display();

    return 0;
}