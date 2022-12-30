#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int vertices,edges;
vector<int> adj[1000];
bool visited[1000];
int path[1000];

void input(){
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
    memset(path, -1, sizeof(path));
}

void BFS(int v){
    queue<int> Waiting;
    Waiting.push(v);
    visited[v] = true;
    cout << "Checked order: ";
    while (!Waiting.empty()){
        int value = Waiting.front();
        Waiting.pop();
        cout << value << " ";
        for (int vi : adj[value]){
            if (visited[vi] == false){
                Waiting.push(vi);
                visited[vi] = true;
                path[vi] = value;
            }
        }
    }

    cout << endl;

}

void printPath(int start, int end){
    int b[100];
    int m = 0;

    cout << "Path from" << start << " to " << end << " is: ";
    if (start == end){
        cout << start;
        return;
    }

    if (path[end] == -1){
        cout << "No path";
        return;
    }

    while (true){
        b[m] = end;
        end = path[end];
        m++;
        if (end == start){
            b[m] = end;
            break;
        }
    }

    for (int i = m; i >= 0; i--){
        cout << b[i] << " ";
    }
    return;
}


int main(){
    input();
    BFS(0);
    printPath(0, 5);
    return 1;
}