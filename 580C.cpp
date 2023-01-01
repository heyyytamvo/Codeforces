#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int numberOfVertices;
int maxCat;
vector<int> adj[100001];
int Cat[100001];
int path[100001];
bool visited[100001];
vector<int> leaveList;



//consecutive
bool canGo(int end){
    int start = 1;
    int b[100001];
    int index = 1;
    int catFoundConsecutive = 0;

    while (true){
        b[index] = end;
        end = path[end];
        index++;
        if (end == start){
            b[index] = end;
            break;
        }
    }

    for (int i = index; i > 0; i--){
        int vertex = b[i];
        if (Cat[vertex] == 1){
            catFoundConsecutive += 1;
            if (catFoundConsecutive > maxCat){
                return false;
            }
        }else{
            catFoundConsecutive = 0;
        }
    }
    return true;
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

bool isLeave(vector<int> adj[100001], int vertex){
    if (adj[vertex].size() == 1 && vertex != 1){
        return true;
    }

    return false;
}

int main(){
    //setting up
    cin >> numberOfVertices >> maxCat;
    int finalResult = 0;
    for (int i = 1; i <= numberOfVertices; i++){
        cin >> Cat[i];
    }

    //finding parent before assign
    for (int i = 1; i < numberOfVertices; i++){
        int x, y;
        cin >> x >> y;
    
        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    memset(visited, false, sizeof(visited));
    memset(path, -1, sizeof(path));

    //finding leaves
    for (int i = 1; i <= numberOfVertices; i++){
        if (isLeave(adj, i)){
            leaveList.push_back(i);
        }
    }

    BFS();

    
    for (int i = 0; i < leaveList.size(); i++){
        int end = leaveList[i];
        if (canGo(end)){
            finalResult += 1;
        }
    }
    
    cout << finalResult;

    return 0;
}