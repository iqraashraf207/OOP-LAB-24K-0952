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

    int highestavgcity=0;
    double highestavg=0.0;

    cout << endl << "Average AQI for each city" << endl;
    for (int i = 0; i < 4; i++)
    {
        double sum=0;
        for (int j = 0; j < 7; j++)
        {
            sum+=aqi[i][j];
        }
        double avg=sum/7;
        cout << city[i] << " average AQI:" << avg << endl;

        if(avg>highestavg){
            highestavg=avg;
            highestavgcity=i;
        }
    }

    cout << "The city having the worst air quality is " << city[highestavgcity] << " with average AQI: " << highestavg << endl;

    return 0;
}