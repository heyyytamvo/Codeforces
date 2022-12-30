#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 101
using namespace std;

struct cell{
    int row, column;
};

vector<int> result;
int height, width;
int visited[MAX][MAX];
string matrix[MAX];
vector<cell> Aposi;
const int vectorX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int vectorY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void input(){
    cin >> height >> width;
    Aposi.clear();
    for (int i = 0; i < height; i++){
        string value;
        cin >> value;
        matrix[i] = value;
    }
}

bool valid(int x, int y){
    return ((x >= 0) && (x < height) && (y >= 0) && (y < width));
}

void findingAposi(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (matrix[i][j] == 'A'){
                Aposi.push_back((cell){i, j});
            } 
        }
    }
}

int DFS(cell start){
    int CharASCII = matrix[start.row][start.column];
    int count = 0;
    //visited[start.row][start.column] = true;
    //char character = CharASCII;
    //cout << "Now, the character is: " << character << " at (" << start.row << ", " << start.column << ")" << endl;
    for (int i = 0; i < 8; i++){
        int newX = start.row + vectorX[i];
        int newY = start.column + vectorY[i];
        //cout << "Next is: " << newX << " " << newY << endl;

        if (valid(newX, newY)){
            int nextASCII = matrix[newX][newY];
            if (nextASCII == CharASCII + 1 && nextASCII < 91 && visited[newX][newY] == 0){
                DFS((cell){newX, newY});
                count = max(count, visited[newX][newY]);  //KEY
            }
        }
    }

    visited[start.row][start.column] = count + 1;
    return visited[start.row][start.column]; //KEY

}

int main(){

    while (true){
        input();

        if (height == 0 && width == 0){
            break;
        }

        findingAposi();
        int temp = 0;
        for (int i = 0; i < Aposi.size(); i++){
            cell begin = Aposi[i];
            memset(visited, 0, sizeof(visited));
            temp = max(temp, DFS(begin));
        }

        result.push_back(temp);
    }
    
    for (int i = 0; i < result.size(); i++){
        cout << "Case " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}



