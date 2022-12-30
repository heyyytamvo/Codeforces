#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

vector<string> result;
int numberOfTestCase, numberOfDocuments, numberOfDependencies;
vector<int> dependencies[10001];
bool visited[10001];
bool RecStack[10001];
bool cycle;
vector<int> path[10001];

void input(){
    //user input
    cin >> numberOfDocuments >> numberOfDependencies;
    for (int i = 0; i < numberOfDependencies; i++){
        int doc1, doc2;
        cin >> doc1 >> doc2;
        dependencies[doc1].push_back(doc2);
    }
}

void DFS(int document){
    visited[document] = true;
    RecStack[document] = true;

    for (int i = 0; i < dependencies[document].size(); i++){
        int deDoc = dependencies[document][i];
        
        if (RecStack[deDoc] && visited[deDoc]){
            cycle = true;
            return;
        }

        if (visited[deDoc] == false){
            path[deDoc].push_back(document);
            DFS(deDoc);
        }
    }

    RecStack[document] = false;
}


int main(){
    cin >> numberOfTestCase;

    while (numberOfTestCase > 0){
        input();
        for (int i = 1; i <= numberOfDocuments; i++){
            if (visited[i] == false){
                DFS(i);
            }
        }

        if (cycle){
            result.push_back("YES");
        }else{
            result.push_back("NO");
        }
        //new loop
        numberOfTestCase--;
        cycle = false;
        //reset 
        for (int i = 0; i < 10001; i++){
            dependencies[i].clear();
            visited[i] = false;
            RecStack[i] = false;
        }
    }
    //cout << "Size is: " << path[1].size() << endl;
    for (int testcase = 0; testcase < result.size(); testcase++){
        cout << result[testcase] << endl;
    }    
    return 0;
}