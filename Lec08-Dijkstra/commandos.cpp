#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 101

using namespace std;

int N, R, s, d;
int numberOfTestCase;
vector< vector<int> > Graph;
vector<int> DistD(MAX, INF);
vector<int> DistS(MAX, INF);


void input(){
    Graph = vector< vector<int> > (MAX + 5, vector<int>());
    for (int i = 0; i < Graph.size(); i++){
        Graph[i].clear();
    }

    for (int i = 0; i < MAX; i++){
        DistD[i] = INF;
        DistS[i] = INF;
    }

    cin >> N;
    cin >> R;

    for (int i = 0; i < R; i++){
        int building0, building1;
        cin >> building0 >> building1;

        Graph[building0].push_back(building1);
        Graph[building1].push_back(building0);
    }

    cin >> s >> d;
}


void dijkstraFromS(int parameterS){
    queue<int> q;
    q.push(parameterS);
    DistS[parameterS] = 0;

    while (!q.empty()){
        int current = q.front();
        q.pop();

        for (int i = 0; i < Graph[current].size(); i++){
            int neighbour = Graph[current][i];

            if (DistS[current] + 1 < DistS[neighbour]){
                DistS[neighbour] = DistS[current] + 1;
                q.push(neighbour);
            }
        }
    }
}


void dijkstraFromD(int parameterD){
    queue<int> q;
    q.push(parameterD);
    DistD[parameterD] = 0;

    while (!q.empty()){
        int current = q.front();
        q.pop();

        for (int i = 0; i < Graph[current].size(); i++){
            int neighbour = Graph[current][i];

            if (DistD[current] + 1 < DistD[neighbour]){
                DistD[neighbour] = DistD[current] + 1;
                q.push(neighbour);
            }
        }
    }
}

int main(){
    cin >> numberOfTestCase;
    int index = 1;

    while (numberOfTestCase > 0){
        input();
        dijkstraFromS(s);
        dijkstraFromD(d);
        int result = 0;
        for (int i = 0; i < N; i++){
            result = max(result, DistD[i] + DistS[i]);
        }
        cout << "Case " << index << ": " << result << endl;


        //new
        numberOfTestCase--;
        index++;
    }
}