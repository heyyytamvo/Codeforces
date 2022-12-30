#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& dynamicArray, int numberOfInputs){
    int number0 = 0;

    if (numberOfInputs == 1){
        if (dynamicArray[0] == 1)
        {
            /* code */
            return true;
        }else{
            return false;
        }
    }


    for (int i = 0; i < numberOfInputs; i++){
        if (dynamicArray[i] == 0){
            number0 += 1;
        }
    }
    if (number0 == 1){
        return true;
    }
    return false;
}

int main(){
    vector<int> array;
    int numberInputs, value;
    cin >> numberInputs;

    for (int i = 0; i < numberInputs; i++){
        cin >> value;
        array.push_back(value);
    }

    bool result = check(array, numberInputs);
    if (result){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0;
}

