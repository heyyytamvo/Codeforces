#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> findMinArray(vector<int> array, int neededSize){
    vector<int> result;
    for (int i = 0; i < neededSize; i++)
    {
        /* code */
        result.push_back(array[i]);
    }

    return result;
}

vector<int> findMaxArray(vector<int> array, int neededSize){
    vector<int> result;
    int endPoint = array.size() - neededSize;
    int startPoint = array.size() - 1;
    for (int i = startPoint; i >= endPoint; i--)
    {
        /* code */
        result.push_back(array[i]);
    }
    return result;
}


int minElement(vector<int> array){
    int value = array[0];
    for (int i = 1; i < array.size(); i++){
        if (value >= array[i]){
            value = array[i];
            continue;
        }
    }

    return value;
}

int maxElement(vector<int> array){
    int value = array[0];
    for (int i = 1; i < array.size(); i++){
        if (value <= array[i]){
            value = array[i];
            continue;
        }
    }

    return value;
}


int main(){
    //take the size of array A and array B
    vector<int> ArraySize;
    for (int i = 0; i < 2; i++){
        int value;
        cin >> value;

        ArraySize.push_back(value);
    }

    //k and m number
    vector<int> takenNumber;
    for (int i = 0; i < 2; i++){
        int value;
        cin >> value;

        takenNumber.push_back(value);
    }

    //array A
    vector<int> arrayA;
    for (int i = 0; i < ArraySize[0]; i++){
        int value;
        cin >> value;

        arrayA.push_back(value);
    }

    //array B
    vector<int> arrayB;
    //ArraySize[1]
    for (int i = 0; i < ArraySize[1]; i++){
        int value;
        cin >> value;

        arrayB.push_back(value);
    }

    //choosing k numbers from A


    //choosing m numbers from B

    //k = m = size
    vector<int> subArrayA = findMinArray(arrayA, takenNumber[0]);
    vector<int> subArrayB = findMaxArray(arrayB, takenNumber[1]);

    int maxSubArrayA = maxElement(subArrayA);
    int minSubArrayB = minElement(subArrayB);

    if (maxSubArrayA < minSubArrayB){
        cout << "YES";
    } 
    
    if (maxSubArrayA >= minSubArrayB)
    {
        /* code */
        cout << "NO";
    }
    

    return 0;
}