#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std; 

int numberTestCase, numberOfFriend,numberOfFriendDescription;
vector<int> circleOfFriend[100001];
vector<int> result;
bool visited[100001];

void input(){
    cin >> numberOfFriend;
    cin >>  numberOfFriendDescription;
    for (int i = 0; i < numberOfFriendDescription; i++){
        int person1, person2;
        cin >> person1 >> person2;
        circleOfFriend[person1].push_back(person2);
        circleOfFriend[person2].push_back(person1);
    }
    return;
}

void DFS(int friendRoot){
    visited[friendRoot] = true;
    for (int i = 0; i < circleOfFriend[friendRoot].size(); i++){
        int nextFriend = circleOfFriend[friendRoot][i];
        
        if (visited[nextFriend] == false){
            DFS(nextFriend);
        }
    }

    return;
}


int main(){
    cin >> numberTestCase;
    int numberOfPeopleThatNeedToBeAnnounced = 0;
    while (numberTestCase > 0){
        //debug
        //int testcase = 1;
        //cout << "Test case " << testcase <<  endl;
        input();
        memset(visited, false, sizeof(visited));
        //processing DFS
        for (int friendIndex = 0; friendIndex < numberOfFriend; friendIndex++){
            //cout << "Friend index " << friendIndex << " " << visited[friendIndex] << endl;
            if (visited[friendIndex] == false){
                numberOfPeopleThatNeedToBeAnnounced += 1;
                DFS(friendIndex);
            }

            circleOfFriend[friendIndex].clear();
        }

        //new loop
        result.push_back(numberOfPeopleThatNeedToBeAnnounced);
        numberOfPeopleThatNeedToBeAnnounced = 0;
        numberTestCase -= 1;
    }

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }

    return 0;
}