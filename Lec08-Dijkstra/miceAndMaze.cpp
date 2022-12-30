#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 101
#define INF 1e9

using namespace std;

int N, E, T, M;
vector< vector< pair<int, int> > > Graph;  //vertex + taken time


struct option {
    bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

void input(){
    Graph = vector< vector< pair<int, int> > > (MAX, vector< pair<int, int> >());
    cin >> N >> E >> T >> M;

    for (int i = 0; i < M; i++){
        int begVertex, endVertex, cost;
        cin >> begVertex >> endVertex >> cost;
        Graph[begVertex].push_back(make_pair(endVertex, cost));
    }
}

int dijkstra(int begin){
    vector<int> timeTaken(MAX, INF);
    priority_queue< pair<int, int>, vector< pair<int, int> >, option > pq;
    pq.push(make_pair(begin, 0));
    timeTaken[begin] = 0;


    while (!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.first;
        int w = current.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> next = Graph[u][i];

            if (next.second + w < timeTaken[next.first]){
                pq.push(make_pair(next.first, next.second + w));
                timeTaken[next.first] = next.second + w;
            }
        }
    }

    if (timeTaken[E] <= T){
        return 1;
    }

    return 0;
}



int main(){
    input();
    int result = 0;
    for (int i = 1; i <= N; i++){
        result += dijkstra(i);
    }

    cout << result << endl;

    return 0;
}