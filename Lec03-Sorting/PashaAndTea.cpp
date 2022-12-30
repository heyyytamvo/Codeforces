#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    double friendNumber, capacity;
    vector<double> cups;

    cin >> friendNumber >> capacity;
    for (int i = 0; i < friendNumber * 2; i++){
        double value;
        cin >> value;

        cups.push_back(value);
    }

    sort(cups.begin(), cups.end());

    double eachCup = min(cups[0] ,cups[friendNumber] / 2);
    double result = 3 * friendNumber * eachCup;

       
    if (result > capacity){
        cout << capacity;
    }
    else{
        cout << setprecision(9) << min(result, capacity);
    }
    return 0;

}