#include <iostream>
#include <vector>
#include <string>
using namespace std;

//get the smaller number
int compareMin(int a, int b){
    if (a <= b){
        return a;
    }
    return b;
}


//finding index given an ASCII number
int FindIndex(vector<char> array, int c_ASCII){
    for (int i = 0; i < array.size(); i++)
    {
        char c = c_ASCII;
        if (array[i] == c)
        {
            return i;
        }
    }
    return -1;
}

//go Clockwise
int goClockWise(vector<char> array, int pointer, int charIndex, char charList[]){
    int charASCII = charList[charIndex];

    vector<char> subArray;
    for (int i = pointer; i < array.size(); i++){
        subArray.push_back(array[i]);
    }

    for (int i = 0; i < pointer; i++)
    {
        subArray.push_back(array[i]);
    }

    int step = FindIndex(subArray, charASCII);
    return step;
}

int goAntiClockWise(vector<char> array, int pointer, int charIndex, char charList[]){
    int charASCII = charList[charIndex];

    vector<char> subArray;
    for (int i = 0; i < array.size(); i++)
    {
        /* code */
        subArray.push_back(array[i]);
    }

    for (int i = 0; i <= pointer; i++){
        subArray.push_back(array[i]);
    }

    //reverse
    vector<char> subArray1;
    for (int i = subArray.size() - 1; i >= 0; i--){
        subArray1.push_back(subArray[i]);
    }
    
    int step = FindIndex(subArray1, charASCII);
    return step;
}

int main(){
    //initialise vector alphabet
    vector<char> Clock;

    for (int i = 97; i < 123; i++){
        char character = i;
        Clock.push_back(character);
    }

    
    //user input
    string userInput;
    cin >> userInput;
    

    //creating array storing char from the user input
    int inputSize = userInput.length();
    char charList[inputSize];

    for (int i = 0; i < inputSize; i++) {
        charList[i] = userInput[i];
    }

    //create pointer and charIndex
    int pointer = 0;
    int charIndex = 0;

    //result
    int result = 0;

    while (charIndex < inputSize){
    

        int stepGoClockwise = goClockWise(Clock, pointer, charIndex, charList);
        int stepGoAntiClockwise = goAntiClockWise(Clock, pointer, charIndex, charList);

        int stepChoose = compareMin(stepGoClockwise, stepGoAntiClockwise);
        result += stepChoose;


        //update pointer and charIndex
        int charASCII = charList[charIndex];
        pointer = FindIndex(Clock, charASCII);
        charIndex += 1;
        
    } 

    cout << result;
    return 0;
}