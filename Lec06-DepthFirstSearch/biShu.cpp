#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std; 

struct country{
    int id, distance;
};

int numberOfCountry, numberOfGirl;
vector<int> girlList;
vector<country> finalList;
vector<int> adj[1001];
int path[1001];
bool visited[1001];

void input(){
    memset(visited, false, sizeof(visited));
    cin >> numberOfCountry;

    for (int i = 1; i < numberOfCountry; i++){
        int x, y;

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> numberOfGirl;
    for (int i = 0; i < numberOfGirl; i++){
        int country;
        cin >> country;
        girlList.push_back(country);
    }
}

void BFS(){
    queue<int> waitingQueue;
    waitingQueue.push(1);
    visited[1] = true;

    while (!waitingQueue.empty()){
        int value = waitingQueue.front();
        waitingQueue.pop();

        for (int vertex : adj[value]){
            if (visited[vertex] == false){
                visited[vertex] = true;
                path[vertex] = value;
                waitingQueue.push(vertex);
            }
        }
    }
    return;
}

int distance(int vertex){
    int result = 0;
    while (true){
        vertex = path[vertex];
        result += 1;

        if (vertex == 1){
            break;
        }
    }
    return result;
}

int main(){
    input();
    BFS();

    for (int i = 0; i < girlList.size(); i++){
        int vertex = girlList[i];
        int distanceRequire = distance(vertex);
        finalList.push_back((country){vertex, distanceRequire});
    }

    country result = finalList[0];
    for (int i = 1; i < numberOfGirl; i++){
        country temp = finalList[i];
        if (temp.distance < result.distance){
            result = temp;
        }else if (temp.distance == result.distance && temp.id < result.id)
        {
            /* code */
            result = temp;
        }
        continue;
    }

    cout << result.id;
    return 0;
}