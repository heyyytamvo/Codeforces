#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

int numberOfBombs, numberOfRelation;
vector<int> relation[MAX];
bool visited[MAX];

void input(){
    cin >> numberOfBombs >> numberOfRelation;

    for (int i = 0; i < numberOfRelation; i++){
        int bomb1, bomb2;
        cin >> bomb1 >> bomb2;
        relation[bomb1].push_back(bomb2);
    }
}

int DFS(int bomb){
    stack<int> waitingBomb;
    int numberOfTriggeredBomb = 1;
    waitingBomb.push(bomb);
    visited[bomb] = true;

    while (!waitingBomb.empty()){
        int topValue = waitingBomb.top();
        waitingBomb.pop();

        for (int i = 0; i < relation[topValue].size(); i++){
            int next = relation[topValue][i];
            if (visited[next] == false){
                visited[next] = true;
                numberOfTriggeredBomb += 1;
                waitingBomb.push(next);
            }
        }
    }

    return numberOfTriggeredBomb;
}


int main(){
    input();

    int result = 0;
    for (int i = 1; i <= numberOfBombs; i++){
        int temp = DFS(i);
        memset(visited, false, sizeof(visited));
        if (temp >= result){
            result = temp;
        }
    }

    cout << result;

    return 0;
}