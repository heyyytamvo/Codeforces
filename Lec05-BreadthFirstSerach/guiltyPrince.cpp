#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int vectorX[4] = {-1, 0, 1, 0};
const int vectorY[4] = {0, 1, 0, -1}; 
bool visited[21][21];
string matrix[21];
int numberOfTestCase;
vector<int> resultPakage;

bool Valid(int xPosi, int yPosi, int width, int height){
    if ((xPosi >= 0 && xPosi < height) && (yPosi >= 0 && yPosi < width) && matrix[xPosi][yPosi] == '.'){
        return true;
    }

    return false;
}


int BFS(pair<int, int> startPosition, int width, int height){
    queue< pair<int, int> > waitingQueue;
    waitingQueue.push(startPosition);
    visited[startPosition.first][startPosition.second] = true;
    int returnValue = 1;

    while (!waitingQueue.empty()){
        
        pair<int, int> currentPosition = waitingQueue.front();
        waitingQueue.pop();
        for (int i = 0; i < 4; i++){
            int newX = currentPosition.first + vectorX[i];
            int newY = currentPosition.second + vectorY[i];

            if (Valid(newX, newY, width, height) && !visited[newX][newY]){
                returnValue += 1;
                visited[newX][newY] = true;
                pair<int, int> nextCell;
                nextCell.first = newX;
                nextCell.second = newY;
                waitingQueue.push(nextCell);
            }
        }
    }

    return returnValue;
}

int main(){
    cin >> numberOfTestCase;

    for (int counter = 0; counter < numberOfTestCase; counter++){
        //get the W and H
        int width, height;
        pair<int,int> start;
        int result;
        cin >> width >> height;

        //get the land
        for (int i = 0; i < height; i++){
            cin >> matrix[i];
        }

        //setting up visited and finding the start position
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                visited[i][j] = false;
                if (matrix[i][j] == '@'){
                    start.first = i;
                    start.second = j;
                }
            }
        }

        result = BFS(start, width, height);
        resultPakage.push_back(result);
    }

    for (int i = 0; i < resultPakage.size(); i++){
        cout << "Case " << i + 1 << ": " << resultPakage[i] << endl;
    }

    return 0;
}
