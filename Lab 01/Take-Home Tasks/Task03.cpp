//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    int aqi[4][7];
    string city[4]={"Karachi", "Islamabad", "Lahore", "Peshawar"};

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter AQI values for " << city[i] << " for 7 days" <<endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "AQI value for day "  << j+1 << ":";
            cin >> aqi[i][j];
        }
    }
    cout << endl << "Visual Representation";
    for (int i = 0; i < 4; i++)
    {
        cout << endl << city[i] << endl;
        for (int j = 0; j < 7; j++)
        {
            int stars= aqi[i][j]/50;
            cout << "Day " << j+1  << ":";
            for (int k = 0; k < stars; k++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}