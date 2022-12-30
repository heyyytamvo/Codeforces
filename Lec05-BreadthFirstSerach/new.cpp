#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define max 501
using namespace std;


struct Position{
    int row, column;
};
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0};

int n, m;
char field[max][max];
bool visited[max][max];
int numberOfSheep = 0;
int numberOfWolf = 0;

bool Valid(Position posi){
    return (posi.row >= 0 && posi.column >= 0 && posi.row < n && posi.column < m);
}

void BFS(Position startPoint){
    queue<Position> waitingQueue;
    waitingQueue.push(startPoint);
    int sheepInArea = 0;
    int wolfInArea = 0;
    bool onEdge = false;

    sheepInArea += (field[startPoint.row][startPoint.column] == 'k');
    wolfInArea += (field[startPoint.row][startPoint.column] == 'v');

    visited[startPoint.row][startPoint.column] = true;
    while (!waitingQueue.empty()){
        Position value = waitingQueue.front();
        waitingQueue.pop();

        for (int i = 0; i < 4; i++){
            int newX = value.row + vectorX[i];
            int newY = value.column + vectorY[i];

            if (field[newX][newY] == '#'){
                continue;
            }

            if (!Valid((Position) {newX, newY})){
                onEdge = true;
                continue;
            }

            if (visited[newX][newY] == false){
                visited[newX][newY] = true;
                sheepInArea += (field[newX][newY] == 'k');
                wolfInArea += (field[newX][newY] == 'v');
                waitingQueue.push((Position) {newX, newY});
                continue;
            }            
        }
    }

    //DEBUGcout << "Sheep in area: " << sheepInArea << endl;
    //DEBUGcout << "Wolf in area: " << wolfInArea << endl;
    if (onEdge){
        //DEBUGcout << "HAHA" << endl;
        numberOfSheep += sheepInArea;
        numberOfWolf += wolfInArea;
        return;
    }


    if (wolfInArea >= sheepInArea){
        numberOfWolf += wolfInArea;
        return;
    }

    numberOfSheep += sheepInArea;
    return;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> field[i][j];
            visited[i][j] = false;
        }
    }

    for (int row = 0; row < n; row++){
        for (int column = 0; column < m; column++){
            if (visited[row][column] == false && field[row][column] != '#'){
                //DEBUGcout << "Check from: " << row << " " << column << endl;
                BFS((Position) {row, column});
            }
        }
    }

    cout << numberOfSheep << " " << numberOfWolf << endl;
    return 1;
}