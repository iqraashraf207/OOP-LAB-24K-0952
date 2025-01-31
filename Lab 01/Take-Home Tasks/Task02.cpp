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
    cout << endl << "Critical pollution days for each city" ;
    for (int i = 0; i < 4; i++)
    {
        cout << endl << city[i] << ":";
        bool criticalday=false;
        for (int j = 0; j < 7; j++)
        {
           if(aqi[i][j]>150){
            cout << "Day " << j+1  << " ";
            criticalday=true;
        }
        } 
    if(!criticalday){
            cout << "No critical days found" << endl;

        }
}
return 0;
}