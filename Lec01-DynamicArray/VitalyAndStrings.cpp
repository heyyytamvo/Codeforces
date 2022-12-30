#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    string stringS;
    string stringT;
    vector<char> letterStringS;
    vector<char> reversedS;

    //input string 
    cin >> stringS;
    cin >> stringT;

    int size = stringS.size();

    //initialising char arrays
    for (int i = 0; i < size; i++){
        letterStringS.push_back(stringS[i]);
    }

    for (int i = size - 1; i >= 0; i--){
        int ASCIIofS = letterStringS[i];

        if (ASCIIofS == 122){
            ASCIIofS = 97;
            stringS[i] = 97;
        }else{
            stringS[i] = ASCIIofS + 1;
            break;
        }
    }

    if (stringS == stringT){
        cout << "No such string";
        return 0;
    }

    cout << stringS;
    return 0;
}