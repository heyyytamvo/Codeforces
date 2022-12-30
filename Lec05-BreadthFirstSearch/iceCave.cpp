#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Coordinate{
    int row, column;
};

char matrix[501][501];
Coordinate path[501][501];
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0};
int n, m;
Coordinate start, target;

bool Valid(Coordinate posi){
    if ((posi.row >= 1 && posi.row <= n) && (posi.column >= 1 && posi.column <= m)){
        if ((matrix[posi.row][posi.column] == '.') || (posi.row == target.row && posi.column == target.column)){
            return true;
        }
    }
    return false;
}

void BFS(Coordinate startingPoint){
    queue<Coordinate> waitingQueue;
    waitingQueue.push(startingPoint);

    while (!waitingQueue.empty()){
        Coordinate currentPosi = waitingQueue.front();
        waitingQueue.pop();

        for (int i = 0; i < 4; i++){
            int newX = currentPosi.row + vectorX[i];
            int newY = currentPosi.column + vectorY[i];
            Coordinate next;
            next.row = newX;
            next.column = newY;

            if (next.row == target.row && next.column == target.column && matrix[target.row][target.column] == 'X'){
                cout << "YES";
                return;
            }

            if (Valid(next)){
                waitingQueue.push(next);
                matrix[next.row][next.column] = 'X';
                path[next.row][next.column] = currentPosi;

            }
        }
    }

    cout << "NO";
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            path[i][j] = (Coordinate) {-1, -1};
        }
    }
    cin >> start.row >> start.column;
    cin >> target.row >> target.column;
    BFS(start);

    return 0;
}