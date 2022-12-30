#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std; 

int vertices,edges;
vector<int> adj[1000];
bool visited[1000];
int path[1000];

void input(){
    memset(visited, false, sizeof(visited));
    memset(path, -1, sizeof(path));

    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++){
        int n, m;
        cin >> n >> m;

        adj[n].push_back(m);
        adj[m].push_back(n);
    }
}

void BFS(int vertex){
    queue<int> waitingQueue;
    waitingQueue.push(vertex);
    visited[vertex] = true;

    while (!waitingQueue.empty()){
        int value = waitingQueue.front();
        waitingQueue.pop();

        for (int x : adj[value]){
            if (visited[x] == false){
                visited[x] = true;
                path[x] = value;
                waitingQueue.push(x);
            }
        }
    }

    return;
}

void DFSrecursion(int vertex){
    visited[vertex] = true;
    for (int i = 0; i < adj[vertex].size(); i++){
        int nextVertex = adj[vertex][i];

        if (visited[nextVertex] == false){
            path[nextVertex] = vertex;
            DFSrecursion(nextVertex);
        }
    }

    return;
}

void printPath(int start, int end){
    int b[100];
    int index = 0;

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
        if (start == end){
            b[index] = end;
            break;
        }

        b[index] = end;
        end = path[end];
        index++;
    }

    for (int i = index; i >= 0; i--){
        cout << b[i] << " -> ";
    }

    cout << endl;
}

int main(){
    input();
    //DFSrecursion(0);
    BFS(0);
    printPath(0, 5);

    return 0;

}