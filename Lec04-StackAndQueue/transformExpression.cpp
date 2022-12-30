#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int numberOfExpressions;
    vector<string> data;



    //user input
    cin >> numberOfExpressions;
    for (int i = 0; i < numberOfExpressions; i++){
        string value;
        cin >> value;
        data.push_back(value);
    }

    for (int stringIndex = 0; stringIndex < numberOfExpressions; stringIndex++){
        int stringLen = data[stringIndex].size();
        string currentString = data[stringIndex];
        vector<char> output;
        stack<int> operators;

        for (int charIndex = 0; charIndex < stringLen; charIndex++){
            int currentChar = currentString[charIndex];

            if (currentChar == 40){
                continue;
            }

            if (currentChar == 41){
                int sign = operators.top();
                output.push_back(sign);
                operators.pop();
                continue;
            }

            if ((currentChar < 97) || (currentChar > 122)){
                operators.push(currentChar);
                continue;
            }

            if ((currentChar >= 97) && (currentChar <= 122))
            {
                /* code */
                output.push_back(currentChar);
            }
        }

        for (int i = 0; i < output.size(); i++){
            cout << output[i];
        }

        cout << endl; 
    }

    return 0;
    
}