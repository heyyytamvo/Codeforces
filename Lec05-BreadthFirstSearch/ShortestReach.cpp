#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int weight = 6;

class Graph {
    public:
    int vertices,edges;
    int startingPoint;
    vector<int> adj[1001];
    bool visited[1001];
    int path[1001];
    vector<int> pathWeightCounting;

    void BFS(){
        queue<int> Waiting;
        Waiting.push(startingPoint);
        visited[startingPoint] = true;

        while (!Waiting.empty()){
            int value = Waiting.front();
            Waiting.pop();
            for (int vi : adj[value]){
                if (visited[vi] == false){
                    Waiting.push(vi);
                    visited[vi] = true;
                    path[vi] = value;
                }
            }
        }
    }

    void PathWeight(int endingVertex){
        int b[1001];
        int m = 0;

        if (endingVertex == startingPoint){
            return;
        }

        if (path[endingVertex] == -1){
            pathWeightCounting.push_back(-1);
            return;
        }

        while (true){
            b[m] = endingVertex;
            endingVertex = path[endingVertex];
            m++;
            if (endingVertex == startingPoint){
                b[m] = endingVertex;
                break;
            }
        }

        m *= weight;
        pathWeightCounting.push_back(m);
        return;
    }

    void addingPathWeight(){
        for (int i = 1; i <= vertices; i++){
            PathWeight(i);
        }
    }

    void printingWeight(){
        for (int i = 0; i < pathWeightCounting.size(); i++){
            cout << pathWeightCounting[i]<< " ";
        }
    }
};

vector<Graph> Data;
int numberOfQueries;

void input(){
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++){
        int numberOfVertices, numberOfEdges;
        cin >> numberOfVertices >> numberOfEdges;

        Graph graph;
        graph.vertices = numberOfVertices;
        graph.edges = numberOfEdges;
        memset(graph.visited, false, sizeof(graph.visited));
        memset(graph.path, -1, sizeof(graph.path));

        for (int j = 1; j <= numberOfEdges;j++){
            int vertex1, vertex2;
            cin >> vertex1 >> vertex2;
            graph.adj[vertex1].push_back(vertex2);
            graph.adj[vertex2].push_back(vertex1);
        }

        int inputStartingPoint;
        cin >> inputStartingPoint;
        graph.startingPoint = inputStartingPoint;
        Data.push_back(graph);
    }


}

int main(){
    input();
    for (int i = 0; i < numberOfQueries; i++){
        Graph graph = Data[i];
        graph.BFS();
        graph.addingPathWeight();
        graph.printingWeight();
        cout << endl;
    }

    return 0;
}

