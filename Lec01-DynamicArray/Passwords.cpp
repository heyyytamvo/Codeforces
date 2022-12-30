#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){

    //first element is the number of password
    //second element is the number of tries before being blocked for 5 second
    vector<int> requirements;
    string correctPassword;
    vector<int> _lengthList;
    for (int i = 0; i < 2; i++){
        int value;
        cin >> value;
        
        requirements.push_back(value);
    }

    vector<string> passwordPakage;
    for (int i = 0; i < requirements[0]; i++){
        string value;
        cin >> value;

        passwordPakage.push_back(value);
    }

    cin >> correctPassword;

    //-----------------------------------------------



}