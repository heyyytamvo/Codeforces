#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


struct cell
{
    /* data */
    int row;
    int column;
};

cell startPoint, endPoint;
bool visited[1001][1001];
char map[1001][1001];
cell path[1001][1001];
vector<int> Result;
int r, c;
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0}; 


bool Valid(int Xposi, int Yposi){
    return ((Xposi >= 0 && Xposi < r) && (Yposi >= 0 && Yposi < c));
}


void BFS(){
    queue<cell> waitingQueue;
    waitingQueue.push(startPoint);
    visited[startPoint.row][startPoint.column] = true;

    while (!waitingQueue.empty()){
        cell next = waitingQueue.front();
        waitingQueue.pop();

        for (int i = 0; i < 4; i++){
            int newX = next.row + vectorX[i];
            int newY = next.column + vectorY[i];

            if (Valid(newX, newY)){
                if (map[newX][newY] == '.' && visited[newX][newY] == false){
                    waitingQueue.push((cell){newX, newY});
                    visited[newX][newY] = true;
                    path[newX][newY] = next;
                }
            }
        }
    }
}

int stepsCounting(){
    int result = 1;

    cell begin = path[endPoint.row][endPoint.column];

    while (true){
        if (begin.row == startPoint.row && begin.column == startPoint.column){
            break;
        }
        cell next;
        next.row = begin.row;
        next.column = begin.column;

        begin = path[next.row][next.column];
        result++;
    }

    return result;
}

int main(){
    while (true){
        cin >> r >> c;
        if (r == 0 && c == 0){
            break;
        }
        int numberBombLines;
        cin >> numberBombLines;
        memset(map, '.', sizeof(map));
        memset(visited, false, sizeof(visited));

        //memset(path, -1, sizeof(path));
        for (int i = 0; i<numberBombLines; i++){
            int rIndex, numOfColumn;
            cin >> rIndex >> numOfColumn;
            for (int j = 0; j < numOfColumn; j++){
                int colIndex;
                cin >> colIndex;
                map[rIndex][colIndex] = 'x';
            }
        }

        cin >> startPoint.row >> startPoint.column;
        cin >> endPoint.row >> endPoint.column;
        BFS();
        int steps = stepsCounting();

        Result.push_back(steps);
    }

    for (int i = 0; i < Result.size(); i++){
        cout << Result[i] << endl;
    }

    

    return 0;
}