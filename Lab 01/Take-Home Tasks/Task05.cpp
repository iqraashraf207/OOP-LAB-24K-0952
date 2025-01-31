//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    int aqi[4][28];
    string city[4]={"KHI", "ISB", "LHE", "PEW"};

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter AQI values for " << city[i] << " for 28 days" <<endl;
        for (int j = 0; j < 28; j++)
        {
            cout << "AQI value for day "  << j+1 << ":";
            cin >> aqi[i][j];
        }
    }
    double weeklyavg[4][4] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int week = 0; week < 4; week++)
        {
            double sum = 0;
            for (int day = week*7; day<(week + 1)*7; day++)
            {
                sum += aqi[i][day];
            }
            weeklyavg[i][week] = sum/7;
        }
    }

    cout << endl << "Critical pollution days" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << city[i] << ": ";
        for (int j = 0; j < 28; j++)
        {
            if (aqi[i][j] > 150){
                cout << "Day " << j + 1 << " ";
            }
        }
        cout << endl;
    }

    int highest[4] = {0};
    int lowest[4] = {1000};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (aqi[i][j]>highest[i]) highest[i] = aqi[i][j];
            if (aqi[i][j]<lowest[i]) lowest[i] = aqi[i][j];
        }
    }

    cout << "Weekly averages for each city" << endl;
    cout << "City\t" << "Week 01\t" << "Week 02\t" <<"Week 03\t" << "Week 04" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << city[i];
        for (int week = 0; week < 4; week++)
        {
            cout << "\t "<< weeklyavg[i][week];
        }
        cout << endl;
    }
    cout << "Highest and Lowest AQI values" << endl;
    cout << "City\t" << "Highest\t" << "Lowest\t"<< endl;
    for (int i = 0; i < 4; i++)
    {
        cout << city[i] <<"\t" << highest[i]<<"\t"<<lowest[i]<<endl;
    }
    return 0;
}