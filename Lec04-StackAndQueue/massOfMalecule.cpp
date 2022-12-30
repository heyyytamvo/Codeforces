#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


//H is 1 index 0
//C is 12 index 1
//O is 16 index 2

const int element[3] = {1, 12, 16};
int main(){
    string value;
    cin >> value;
    stack<int> storage;
    int result = 0;
    int stringLen = value.length();

    for (int i = 0; i < stringLen; i++){
        if (value[i] == 'C'){
            storage.push(12);
            continue;
        }
        if (value[i] == 'H'){
            storage.push(1);
            continue;
        }
        if (value[i] == 'O'){
            storage.push(16);
            continue;
        }
        if (isdigit(value[i])){
            int charInteger = value[i] - 48;
            int adjElement = storage.top();
            storage.pop();
            adjElement *= charInteger;
            storage.push(adjElement);
            continue;
        }

        if (value[i] == '('){
            storage.push(-1);
            continue;
        }

        if (value[i] == ')'){
            int temp = 0;
            while (storage.top() != -1){
                temp += storage.top();
                storage.pop();
            }

            storage.pop();
            storage.push(temp);
        }
    }

    while(!storage.empty()){
        result += storage.top();
        storage.pop();
    }

    cout << result;
    return 0;
}