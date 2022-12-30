#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int numberOfRoad, startingPoint, numberOfDestinations;
#define MAX 501
const int INF = 1e9;
vector< vector< pair<int, int> > > Graph;
vector<int> dist(MAX, INF);
int path[MAX];

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
    Graph = vector< vector< pair<int, int> > > (MAX + 5, vector< pair<int, int> >());
    memset(path, -1, sizeof(path));
    cin >> numberOfRoad;
    for (int i = 0; i < numberOfRoad; i++){
        int locationA, locationB, weight;
        cin >> locationA >> locationB >> weight;
        if (weight > 0){
            Graph[locationA].push_back(make_pair(locationB, weight));
            Graph[locationB].push_back(make_pair(locationA, weight));
        }
        
    }

    cin >> startingPoint;
}

void dijkstra(){
    priority_queue< pair<int, int>, vector< pair<int, int> >, option> pq;
    pq.push(make_pair(startingPoint, 0));
    path[startingPoint] = 0;

    while (!pq.empty()){
        pair<int, int> currentVertex = pq.top();
        pq.pop();

        int u = currentVertex.first;
        int w = currentVertex.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> neighbour = Graph[u][i];

            if (neighbour.second + w < dist[neighbour.first]){
                path[neighbour.first] = u;
                dist[neighbour.first] = neighbour.second + w;
                pq.push(make_pair(neighbour.first, neighbour.second + w));
            }
        }
    }
}

void printCost(int des){
    if (path[des] == -1){
        cout << "NO PATH" << endl;
        return;
    }

    if (des == startingPoint){
        cout << 0 << endl;
        return;
    }

    cout << dist[des] << endl;
    return;
}

int main(){
    input();
    dijkstra();
    cin >> numberOfDestinations;
    for (int i = 0; i < numberOfDestinations; i++){
        int value;
        cin >> value;
        printCost(value);
    }
    
    return 0;
}

