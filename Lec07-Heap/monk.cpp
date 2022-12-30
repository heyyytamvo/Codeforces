#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<unsigned long int> Result;
vector<unsigned long int> storage;
priority_queue<unsigned long int> maxHeap;

unsigned long int multiplication(){
    unsigned long int returnValue = 1;
    unsigned long int temp[3];
    for (int i = 0; i < 3; i++){
        returnValue *= maxHeap.top();
        temp[i] = maxHeap.top();
        maxHeap.pop();
    }

    for (int i = 0; i < 3; i++){
        maxHeap.push(temp[i]);
    }

    return returnValue;
}


int main(){
    Result.push_back(-1);
    Result.push_back(-1);

    unsigned long int numberOfElements;
    cin >> numberOfElements;

    if (numberOfElements == 2 || numberOfElements == 1){
        for (int i = 0; i < numberOfElements; i++){
            cout << -1 << endl;
        }

        return 0;
    }

    for (unsigned long int i = 0; i < numberOfElements; i++){
        unsigned long int value;
        cin >> value;

        storage.push_back(value);
    }


    /*for (int i = 0; i < numberOfElements; i++){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }*/

    for (unsigned long int i = 0; i < numberOfElements; i++){
        if (i == 0 || i == 1){
            maxHeap.push(storage[i]);
            continue;
        }
        maxHeap.push(storage[i]);
        unsigned long int result = multiplication();
        Result.push_back(result);
    }

    cout << -1 << endl << -1 << endl;
    for (unsigned long int i = 2; i < numberOfElements; i++){
        cout << Result[i] << endl;
    }

    return 0;
}