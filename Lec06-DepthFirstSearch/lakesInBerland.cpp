#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std; 


struct cell{
    int row, column;
};

int n, m, k;
string Berland[51];
bool visited[51][51];
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0};
vector< vector<cell> > lakeList;


bool sortBySize(const vector<cell> &a, const vector<cell> &b) {
    return a.size() < b.size();
}

bool belongToOcean(int row, int column){
    return (row == 0 || row == n - 1 || column == 0 || column == m - 1);
}

bool valid(int row, int column){
    return ((0 <= row && row <= n - 1) && (0 <= column && column <= m - 1));
}

void BFS(int row, int column){
    vector<cell> temp;
    queue<cell> waitingQueue;
    bool Ocean = false;
    waitingQueue.push((cell) {row, column});
    visited[row][column] = true;
    temp.push_back((cell) {row, column});

    if (belongToOcean(row, column)){
        Ocean = true;
    }

    while (!waitingQueue.empty()){
        cell value = waitingQueue.front();
        waitingQueue.pop();
        for (int k = 0; k < 4; k++){
            int newX = value.row + vectorX[k];
            int newY = value.column + vectorY[k];


            if (valid(newX, newY)){
                if (visited[newX][newY] == false && Berland[newX][newY] == '.'){
                    waitingQueue.push((cell){newX, newY});
                    visited[newX][newY] = true;
                    temp.push_back((cell){newX, newY});
                    if (belongToOcean(newX, newY)){
                        Ocean = true;
                    }   
                }
            }
        }
    }
    if (Ocean){
        return;
    }

    lakeList.push_back(temp);
    return;
}

void input(){
    memset(visited, false, sizeof(visited));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> Berland[i];
    }
}

int main(){
    input();
    
    for (int rowIndex = 0; rowIndex < n; rowIndex++){
        for (int columnIndex = 0; columnIndex < m; columnIndex++){
            if (visited[rowIndex][columnIndex] == false && Berland[rowIndex][columnIndex] == '.'){
                BFS(rowIndex, columnIndex);
            }
        }
    }

    sort(lakeList.begin(), lakeList.end(), sortBySize);


    int totalLake = lakeList.size();
    //cout << totalLake << endl;
    int result = 0;
    int index = 0;

    while (totalLake > k){
        vector<cell> lake = lakeList[index];
        result += lake.size();
        index += 1;
        totalLake -= 1;

        for (int i = 0; i < lake.size(); i++){
            cell x = lake[i];
            Berland[x.row][x.column] = '*';
        }
    }

    cout << result << endl;
    //cout << result << endl;
    for (int i = 0; i < n; i++){
        cout << Berland[i] << endl;
    }

    return 0;
}