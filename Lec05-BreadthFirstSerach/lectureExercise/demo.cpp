#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
vector<int> adj[1000];
bool visited[1000];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(visited, false, sizeof(visited));
}

void BFS(int v){
    queue<int> Waiting;
    Waiting.push(v);
    visited[v] = true;

    while (!Waiting.empty()){
        int value = Waiting.front();
        Waiting.pop();
        cout << value << " ";
        for (int vi : adj[value]){
            if (visited[vi] == false){
                Waiting.push(vi);
                visited[vi] = true;
            }
        }
    }
}


int main(){
    input();
    BFS(1);
    for (int x : adj[1]){
        cout << x;
    }

    return 1;
}