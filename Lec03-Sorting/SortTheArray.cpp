#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int main(){
    int numberOfElements;
    vector<int> Array;
    vector<int> testCaseEntireArray;
    vector<int> SortedArray;

    //user input
    cin >> numberOfElements;
    for (int i = 0; i < numberOfElements; i++){
        int value;
        cin >> value;

        Array.push_back(value);
        testCaseEntireArray.push_back(value);
        SortedArray.push_back(value);
    }

    sort(SortedArray.begin(), SortedArray.end());
    testCaseEntireArray = SortedArray;
    //case 1: if the array is already sorted
    if (is_sorted(Array.begin(), Array.end())){
        cout << "yes" << endl;
        cout << "1 1";
        return 0;
    }

    //case 2: we need to sort the entire array
    reverse(testCaseEntireArray.begin(), testCaseEntireArray.end());
    if (testCaseEntireArray == Array){
        cout << "yes" << endl;
        cout << 1 << " " << numberOfElements;
        return 0;
    }
    
    int startIndex;
    int endIndex;

    for (int i = 0; i < numberOfElements - 1; i++){
        
       if (Array[i] < Array[i + 1]){
            continue;
       }

       startIndex = i;
       int j = startIndex;

       while(Array[j] > Array[j + 1] && (j < numberOfElements - 1)){
            endIndex = j + 1;
            j++;
       }
        break;
    }

    //reverse the sub array
    vector<int>::iterator ptrStart;
    vector<int>::iterator ptrEnd;
    ptrStart = Array.begin() + startIndex;
    ptrEnd = Array.begin() + endIndex + 1;

    reverse(ptrStart,ptrEnd);

    if (is_sorted(Array.begin(), Array.end())){
        cout << "yes" << endl;
        cout << startIndex + 1 << " " << endIndex + 1;
        return 0;
    }

    cout << "no";
    //cout << startIndex << " " << endIndex;
    return 0;
}