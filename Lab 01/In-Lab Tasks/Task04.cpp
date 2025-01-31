//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    const int max_participants = 5;
    string event1[max_participants];
    string event2[max_participants];
    int event1count;
    int event2count;

    cout << "Enter the number of participants for event 1: ";
    cin >> event1count;

    if(event1count > max_participants){
        event1count=max_participants;
        cout << "Only " << max_participants << " allowed." << endl;
    }

    cout << "Enter participants for event 1" << endl;
    for (int i = 0; i < event1count; i++)
    {
        cout << "Name of " << i+1 << " participant: ";
        cin >> event1[i];
    }

    cout << "Enter the number of participants for event 2: ";
    cin >> event2count;

    if(event2count > max_participants){
        event2count=max_participants;
        cout << "Only " << max_participants << " allowed." << endl;
    }

    cout << "Enter participants for event 2" << endl;
    for (int i = 0; i < event2count; i++)
    {
        cout << "Name of " << i+1 << " participant: ";
        cin >> event2[i];
    }

    cout << "Participants of event 1" << endl;
    for (int i = event1count-1; i >= 0; i--)
    {
       cout << event1[i] <<endl;
    }

    cout << "Participants of event 2" << endl;
    for (int i = event2count-1; i >= 0; i--)
    {
       cout << event2[i] <<endl;
    }
    return 0;
}