#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int matrix[251][251];
bool visited[251][251];
int result[251 * 251];
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0}; 

struct cell
{
    /* data */
    int row;
    int column;
};


bool Valid(int Xposi, int Yposi){
    return ((Xposi >= 0 && Xposi < n) && (Yposi >= 0 && Yposi < m));
}


void BFS(cell start){
    queue< cell > waitingQueue;
    waitingQueue.push(start);
    visited[start.row][start.column] = true;
    int area = 1;

    while (!waitingQueue.empty()){
        cell value = waitingQueue.front();
        waitingQueue.pop();

        for (int i = 0; i < 4; i++){
            int newX = value.row + vectorX[i];
            int newY = value.column + vectorY[i];

            if (Valid(newX, newY) && matrix[newX][newY] == 1 && !visited[newX][newY]){
                waitingQueue.push((cell) {newX, newY});
                visited[newX][newY] = true;
                area += 1;
            }
        }

    }

    result[area] += 1;
    return;
}

int main(){
    while (true){
        //user input
        cin >> n >> m;

        if (n == 0 || m == 0){
            break;
        }
        //memset(result, 0, sizeof(result));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> matrix[i][j];
                visited[i][j] = false;
            }
        }

        int totalOilSpill = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 1 && visited[i][j] == false){
                    totalOilSpill += 1;
                    BFS((cell) {i, j});
                }
            }
        }

        cout << totalOilSpill << endl;
        for (int i = 0; i < 251 * 251; i++){
            if (result[i] != 0){
                cout << i << " " << result[i] << endl;
            }
        }
    }
    return 1;
}