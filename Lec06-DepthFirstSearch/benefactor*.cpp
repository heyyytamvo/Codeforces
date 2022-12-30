#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#define maxNum 5001
#include <cstring>

using namespace std;

int numberOfTestCase, numberOfPlaces;
int distanceBet[maxNum][maxNum];
bool visited[maxNum];
vector<int> adj[maxNum];
vector<int> result;
int staticArray[maxNum];


void input(){
    cin >> numberOfPlaces;
    memset(visited, false, sizeof(visited));
    memset(staticArray, 0, sizeof(staticArray));

    for (int i = 1; i < numberOfPlaces; i++){
        int place1, place2, length;
        cin >> place1 >> place2 >> length;

        adj[place1].push_back(place2);
        adj[place2].push_back(place1);
        distanceBet[place1][place2] = length;
        distanceBet[place2][place2] = length;
    }
}


int DFS(int begin){
    visited[begin] = true;
    int totalDistance = 0;
    int temp;
    if (adj[begin].size() == 0){
        return 0;
    }

    for (int i = 0; i < adj[begin].size(); i++){
        int nextPlace = adj[begin][i];

        if (visited[nextPlace] == false){
            visited[nextPlace] = true;
            DFS(nextPlace);
            totalDistance = max(totalDistance, distanceBet[begin][nextPlace]);
        }
    }

    staticArray[begin] += totalDistance;
    return staticArray[begin];
}

int main(){
    input();

    int result = 0;
    /*for (int i = 1; i < numberOfPlaces; i++){
        result = max(result, DFS(i));
    }*/


    for (int i = 1; i <= numberOfPlaces; i++){
        int a = DFS(i);
        memset(visited, false, sizeof(visited));
    }

    for (int i = 1; i <= 6; i++){
        cout << "Array " << i << " is " << staticArray[i] << endl;
    }

    return 0;
}