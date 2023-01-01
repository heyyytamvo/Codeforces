#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAX 10000000
#define INF 1e9

using namespace std;

struct option {
    bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

int N, M, k, x, A, B;
vector<int> citiesHaveChoco;
vector<int> DistFromB(MAX, INF);
vector<int> DistFromA(MAX, INF);
vector< vector< pair<int, int> > > Graph;  //city + length


void input(){
    cin >> N >> M >> k >> x;
    Graph = vector< vector< pair<int, int> > > (MAX, vector< pair<int, int> >());
    for (int i = 0; i < k; i++){
        int kCity;
        cin >> kCity;
        citiesHaveChoco.push_back(kCity);
    }

    for (int i = 0; i < M; i++){
        int city1, city2, length;
        cin >> city1 >> city2 >> length;
        Graph[city1].push_back(make_pair(city2, length));
        Graph[city2].push_back(make_pair(city1, length));
    }

    cin >> A >> B;
}

void dijkstraFromB(int vertexB){
    priority_queue< pair<int, int>, vector< pair<int, int> >, option> pq;
    pq.push(make_pair(vertexB, 0));
    DistFromB[vertexB] = 0;

    while (!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();
        int u, w;
        u = current.first;
        w = current.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> next = Graph[u][i];

            if (next.second + w < DistFromB[next.first]){
                DistFromB[next.first] = next.second + w;
                pq.push(make_pair(next.first, DistFromB[next.first]));
            }
        } 
    }
}

void dijkstraFromA(int vertexA){
    priority_queue< pair<int, int>, vector< pair<int, int> >, option> pq;
    pq.push(make_pair(vertexA, 0));
    DistFromA[vertexA] = 0;

    while (!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();

        int u, w;
        u = current.first;
        w = current.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> next = Graph[u][i];

            if (next.second + w < DistFromA[next.first]){
                DistFromA[next.first] = next.second + w;
                pq.push(make_pair(next.first, DistFromA[next.first]));
            }
        } 
    }
}

int main(){
    input();
    dijkstraFromB(B);
    dijkstraFromA(A);
    //cout << "B is: " << B << endl;
    //cout << "Distance from B is: ";
    /*for (int i = 0; i <= N; i++){
        cout << DistFromB[i] << " ";
    }*/

    //cout << endl;
    int result = INF;
    for (int i = 0; i < citiesHaveChoco.size(); i++){
        int currentCity = citiesHaveChoco[i];
        int distance = DistFromB[currentCity] + DistFromA[currentCity];
        //cout << "Current city: " << currentCity << endl;
        //cout << "From here to B is: " << DistFromB[currentCity] << endl;
        //cout << "From here to A is: " << DistFromA[currentCity] << endl;

        if (DistFromB[currentCity] <= x){
            result = min(result, distance);
        }
    }

    if (result >= INF){
        cout << -1 << endl;
    }else{
        cout << result << endl;
    }

    return 0;
}