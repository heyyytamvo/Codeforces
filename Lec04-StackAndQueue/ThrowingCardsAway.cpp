#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int number;

    cin >> number;

    while (number != 0){
        //queue setting up
        queue<int> queueNumbers;
        vector<int> discardedNumbers;
        for (int i = 1; i <= number; i++){
            queueNumbers.push(i);
        }

        if (number == 1){
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: 1" << endl;
            cin >> number;
            continue;
        }

        while (queueNumbers.size() >= 2){
            int discardValue = queueNumbers.front();
            discardedNumbers.push_back(discardValue);
            queueNumbers.pop();
            int keepingValue = queueNumbers.front();
            queueNumbers.pop();
            queueNumbers.push(keepingValue);
        }

        //print discarded numbers
        cout << "Discarded cards: ";
        for (int i = 0; i < discardedNumbers.size() - 1; i++){
            cout << discardedNumbers[i] << ", ";
        }
        cout << discardedNumbers[discardedNumbers.size() - 1] << endl;
        //print remaining numbers
        cout << "Remaining card: " << queueNumbers.front() << endl;

        //new
        cin >> number;

    }
    
    
    return 0;
}