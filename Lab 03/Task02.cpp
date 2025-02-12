//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class FitnessTracker{
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int goal){
        userName = name;
        dailyStepGoal = goal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps){
        if (steps > 0){
            stepsTaken += steps;
            caloriesBurned += steps * 0.02;
            cout << steps << " steps logged successfully" << endl;
        } else{
            cout << "Step count invalid" << endl;
        }
    }

    void calculateCalories(int steps){
        caloriesBurned += steps * 0.02;
        cout << caloriesBurned << " calories burned succesfullly" << endl;
    }

    bool isGoal(){
        return stepsTaken >= dailyStepGoal;
    }

    void displayProgress(){
        cout << "Fitness Progress" << endl;
        cout << "User: " << userName << endl;
        cout << "Daily Step Goal: " << dailyStepGoal << " steps" << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;
        if (isGoal()){
            cout << "Congrats! You've accomplished your goal." << endl;
        } else{
            cout << "You need to work hard." << endl;
        }
        cout << endl;
    }
};

int main(){
    FitnessTracker laiba("Laiba", 7000);

    laiba.logSteps(5000);
    laiba.calculateCalories(5000);
    laiba.displayProgress();
    laiba.logSteps(9000);
    laiba.calculateCalories(9000);
    laiba.displayProgress();

    return 0;
}