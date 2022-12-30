#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAX 100000
#define INF 1e9

using namespace std;
int numberOfTestCase;
vector<int> Result;
map<string, int> EncodeCity;
int numberOfCity, numberOfNeighbour, numberOfPaths;
vector< vector< pair<int, int> > > Graph;

struct option {
    bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

int dijkstra(int vertexStart, int vertexEnd){
    vector<int> dist(MAX, INF);
    priority_queue< pair<int, int>, vector< pair<int, int> >, option > pq;
    pq.push(make_pair(vertexStart, 0));
    dist[vertexStart] = 0;

    while (!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.first;
        int w = current.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> next = Graph[u][i];
            if (next.second + w < dist[next.first]){
                dist[next.first] = next.second + w;
                pq.push(make_pair(next.first, next.second + w));
            }
        }
    }

    return dist[vertexEnd];
}

int main(){
    cin >> numberOfTestCase;

    while (numberOfTestCase > 0){
        cin >> numberOfCity;
        Graph = vector< vector< pair<int, int> > > (MAX + 5, vector< pair<int, int> >());
        for (int i = 1; i <= numberOfCity; i++){
            string cityName;
            cin >> cityName;
            EncodeCity.insert(make_pair(cityName, i));
            cin >> numberOfNeighbour;
            for (int j = 0; j < numberOfNeighbour; j++){
                int cityCode, distance;
                cin >> cityCode >> distance;
                Graph[i].push_back(make_pair(cityCode, distance));
            }
        }
        cin >> numberOfPaths;
        for (int i = 0; i < numberOfPaths; i++){
            string start, destination;
            cin >> start >> destination;
            int temp = dijkstra(EncodeCity[start], EncodeCity[destination]);
            cout << temp << endl;
        }


        //new testcase
        numberOfTestCase--;
        for (int i = 0; i < numberOfCity; i++){
            Graph[i].clear();
        }
        EncodeCity.clear();
    }

    return 0;
}