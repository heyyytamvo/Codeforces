#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 20001

using namespace std;

int numberOfTestCase, n, m, s, t;
vector< vector< pair<int, int> > > Graph;  //server1[{server2, weight}, ...]
vector<int> Dist(MAX, INF);
bool checked[MAX];

struct option {
    bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

void intitialize(){
    Graph = vector< vector< pair<int, int> > > (MAX + 5, vector< pair<int, int> >());
    
    for (int i = 0; i < MAX; i++){
        Dist[i] = INF;
        Graph[i].clear();
        checked[i] = false;
    }
}

void input(){
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++){
        int server0, server1, delaytime;
        cin >> server0 >> server1 >> delaytime;

        Graph[server0].push_back(make_pair(server1, delaytime));
        Graph[server1].push_back(make_pair(server0, delaytime));
    }
}

void dijkstra(int begin){
    priority_queue< pair<int, int>, vector< pair<int, int> >, option > pq;
    pq.push(make_pair(begin, 0));
    Dist[begin] = 0;
    checked[begin] = true;


    while (!pq.empty())
    {
        /* code */
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.first;
        int w = current.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> neighbour = Graph[u][i];
            checked[neighbour.first] = true;
            if (neighbour.second + w < Dist[neighbour.first]){
                Dist[neighbour.first] = neighbour.second + w;
                pq.push(make_pair(neighbour.first, Dist[neighbour.first]));
            }
        }
    }
}

int main(){
    cin >> numberOfTestCase;
    int index = 1;

    while (index <= numberOfTestCase){
        intitialize();
        input();
        dijkstra(s);

        if (checked[t] == false){
            cout << "Case #"<< index <<": " << "unreachable" << endl;
            index++;
            continue;
        }else{
            cout << "Case #"<< index <<": " << Dist[t] << endl;
        }
        index++;
    }

    return 0;
}