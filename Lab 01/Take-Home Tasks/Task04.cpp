//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    int aqi[4][28];
    string city[4]={"Karachi", "Islamabad", "Lahore", "Peshawar"};

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter AQI values for " << city[i] << " for 28 days" <<endl;
        for (int j = 0; j < 28; j++)
        {
            cout << "AQI value for day "  << j+1 << ":";
            cin >> aqi[i][j];
        }
    }

    cout << endl <<  "Monthly average AQI for each city";
    double monthlyavg[4]={0};
    for (int i = 0; i < 4; i++)
    {
       double sum=0;
        for (int j = 0; j < 28; j++)
        {
            sum+=aqi[i][j];
        }
        monthlyavg[i]=sum/28;
        cout << city[i] << "monthly average:" << monthlyavg[i] << endl;
    }
    double firstWeekAvg[4] = {0};
    double lastWeekAvg[4] = {0};
    double improvement[4] = {0};

    for (int i = 0; i < 4; i++) 
    {
        double firstWeekSum = 0; 
        double lastWeekSum = 0;
        for (int j = 0; j < 7; j++) 
        {
            firstWeekSum+=aqi[i][j];
        }
        firstWeekAvg[i] = firstWeekSum/7;

        for (int j = 21; j < 28; j++) 
        {
            lastWeekSum += aqi[i][j];
        }
        lastWeekAvg[i] = lastWeekSum/7;
        improvement[i] = firstWeekAvg[i]-lastWeekAvg[i];
    }
    int mostimprovedcity = 0;
    double maximprovement = improvement[0];
    for (int i = 1; i < 4; i++) 
    {
        if (improvement[i] > maximprovement){
            maximprovement = improvement[i];
            mostimprovedcity= i;
        }
    }
    cout << "The city with the most improved air quality is "<< city[mostimprovedcity] << "with improvement of:" << maximprovement << endl;
    return 0;
}