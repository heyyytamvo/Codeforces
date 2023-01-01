#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool continueWatching(int value1, int value2){
    if ((value2 - value1) <= 15){
        return true;
    }
    return false;
}

int minuteContinueWatching(int value1, int value2){
    if ((value2 - value1) <= 15){
        return (value2 - value1);
    }
    return 15;
}

int main(){
    vector<int> interestingData;
    int numberOfInterestingData;

    cin >> numberOfInterestingData;
    for (int i = 0; i < numberOfInterestingData; i++)
    {
        /* code */
        int value;
        cin >> value;
        interestingData.push_back(value);
    }

    //just watch in the first 15 minutes
    if (interestingData[0] > 15){
        cout << 15;
        return 0;
    }

    //just watch in the first 15 minutes
    if (interestingData[0] <= 15 && numberOfInterestingData == 1){
        cout << interestingData[0] + 15;
        return 0;
    }

    int totalMin = interestingData[0];
    
    for (int i = 0; i < numberOfInterestingData - 1; i++){
        int first = interestingData[i];
        int second = interestingData[i + 1];

        if (continueWatching(first, second)){
            int nextMinsWatching = minuteContinueWatching(first, second);
            totalMin += nextMinsWatching;

            if ((i == numberOfInterestingData - 2) && (continueWatching(first, second))){
                //last interesting minute comparing
                if ((90 - interestingData[numberOfInterestingData - 1]) <= 15){
                    totalMin += (90 - interestingData[numberOfInterestingData - 1]);
                }else{
                    totalMin += 15;
                }
            }
            continue;
        }else{
            totalMin += 15;
            break;
        }
    }

    

    cout << totalMin;
    return 0;
}
