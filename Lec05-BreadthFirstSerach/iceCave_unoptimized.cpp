#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#include <chrono>
using namespace std::chrono;


struct Coordinate{
    int row, column;
};

char matrix[501][501];
Coordinate path[501][501];
//bool visited[501][501];
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0};
int n, m;
Coordinate start, target;

/*
void Path(){
    Coordinate begin = path[target.row][target.column];
    
    while (true){
        if ((begin.row == start.row) && (begin.column == start.column)){
            break;
        }

        Coordinate next;
        next.row = begin.row;
        next.column = begin.column;

        begin = path[next.row][next.column];
        matrix[begin.row][begin.column] = 'X';
    }
}
*/

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

            if (Valid(next)){
                waitingQueue.push(next);
                matrix[next.row][next.column] = 'X';
                path[next.row][next.column] = currentPosi;

            }
        }
    }
}

int main(){
    
    //auto startTime = high_resolution_clock::now();

    //user input
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            path[i][j] = (Coordinate) {-1, -1};
            //visited[i][j] = false;
        }
    }

    cin >> start.row >> start.column;

    cin >> target.row >> target.column;
    BFS(start);
    
    // After function call
    //auto stopTime = high_resolution_clock::now();
    //auto var = startTime - stopTime;
    //auto duration = duration_cast<milliseconds> (var);

    //cout << "Taking " << duration.count() << "ms" << endl;
    Coordinate targetCell = path[target.row][target.column];
    if (targetCell.row == -1 && targetCell.column == -1){
        cout << "NO";
        return 0;
    }

    //Path();
    
    if (matrix[target.row][target.column] == 'X'){
        cout << "YES";
        return 1;
    }else if (matrix[target.row][target.column] == '.')
    {
    /* code */
        for (int i = 0; i < 4; i++){
            int newX = target.row + vectorX[i];
            int newY = target.column + vectorY[i];

            if (Valid((Coordinate) {newX, newY})){
                cout << "YES";
                return 1;
            }
        }
    }
    cout << "NO";

    
    return 0;
}