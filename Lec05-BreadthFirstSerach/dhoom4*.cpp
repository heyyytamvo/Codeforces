#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int keyStart, lockValue;
int Nkeys;
vector<int> package[100000];

void BFS(){
    int result = keyStart;
    int count = 0;
    queue<int> waitingQueue;

    for (int i = 0; i < package[keyStart].size(); i++){
        int checkValue = package[keyStart][i];
        waitingQueue.push(checkValue);
    }

    while (!waitingQueue.empty()){
        int value = waitingQueue.front();
        waitingQueue.pop();
        result *= value;
        result = result % 100000;
        //DEBUGcout << "Current key value is: " << result << endl;
        count += 1; 

        if (result == lockValue){
            break;
        }
    }

    if (result == lockValue){
        cout << count << endl;
        return;
    }

    cout << -1;
    return;
}

void input(){
    cin >> keyStart >> lockValue;
    cin >> Nkeys;

    for (int i = 0; i < Nkeys; i++){
        int value;
        cin >> value;
        package[keyStart].push_back(value);
    }
}

int main(){
    input();
    BFS();

    return 0;
}