#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAX 10000000
#define INF 1e9

using namespace std;

int numberOfDataSet;
int n, m, k, s, t;
vector< vector< pair<int, int> > > Graph;
vector< vector< pair<int, int> > > GraphT;  //location1 -> location2 : distance

int distFromVertexS[MAX];
int distFromVertexB[MAX];

struct option {
    bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

void dijkstra(int vertex, int dist[], vector< vector< pair<int, int> > > &graph){
    priority_queue< pair<int, int>, vector< pair<int, int> >, option> pq;
    pq.push(make_pair(vertex, 0));
    dist[vertex] = 0;

    while (!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();
        int u = current.first;
        int w = current.second;


        if (w > dist[u]){
            continue;
        }
        for (pair<int, int> &neighbor : graph[u]){
            if (neighbor.second + w < dist[neighbor.first]){
                dist[neighbor.first] = neighbor.second + w;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}


int main(){
    cin >> numberOfDataSet;
    Graph = vector< vector< pair<int, int> > > (MAX + 5, vector< pair<int, int> >());
    GraphT = vector< vector< pair<int, int> > > (MAX + 5, vector< pair<int, int> >());

    while (numberOfDataSet > 0){
        cin >> n >> m >> k >> s >> t;
        

        for (int i = 0; i < MAX; i++){
            distFromVertexS[i] = INF;
            distFromVertexB[i] = INF;
            Graph[i].clear();
            GraphT[i].clear();
        }
        for (int i = 0; i < m; i++){
            int locationA, locationB, distance;
            cin >> locationA >> locationB >> distance;
            Graph[locationA].push_back(make_pair(locationB, distance));
            GraphT[locationB].push_back(make_pair(locationA, distance));
        }

        dijkstra(s, distFromVertexS, Graph);
        dijkstra(t, distFromVertexB, GraphT);
        
        int shortestBeforeChanging = distFromVertexS[t];
        int result = shortestBeforeChanging;

        for (int i = 0; i < k; i++){
            int a, b, c;
            cin >> a >> b >> c;
            int new1 = distFromVertexS[a] + c + distFromVertexB[b];
            int new2 = distFromVertexS[b] + c + distFromVertexB[a];
            result = min(result, min(new1, new2));
        }

        if (result != shortestBeforeChanging){
            cout << result << endl;
        }else{
            cout << -1 << endl;
        }
        
        numberOfDataSet--;
    }



    return 0;
}