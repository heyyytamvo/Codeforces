#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int numberOfCars;
    vector< vector<int> > Array;


    //user input

    cin >> numberOfCars;
    while (numberOfCars != 0)
    {
        /* code */
        vector<int> queueTruck;
        for (int i = 0; i < numberOfCars; i++){
            int value;
            cin >> value;
            queueTruck.push_back(value);
        }

        Array.push_back(queueTruck);
        cin >> numberOfCars;
    }
    

    

    //processing
    for (int i = 0; i < Array.size(); i++){
        int nextCar = 1;
        stack<int> SideStreet;

        for (int index = 0; index < Array[i].size(); index++){
            while (SideStreet.empty() == false && SideStreet.top() == nextCar){
                SideStreet.pop();
                nextCar += 1;
            }

            SideStreet.push(Array[i][index]);
            
            if (SideStreet.top() == nextCar){
                SideStreet.pop();
                nextCar += 1;
            }       
        }

        while (SideStreet.empty() == false){
                if (SideStreet.top() == nextCar){
                    SideStreet.pop();
                    nextCar += 1;
                    continue;
                }

                SideStreet.pop();
            }

        if (nextCar == Array[i].size() + 1){
            cout << "yes" << endl;
            nextCar = 1;
            continue;
        }

        cout << "no" << endl; 
    }
    
    return 0;
}