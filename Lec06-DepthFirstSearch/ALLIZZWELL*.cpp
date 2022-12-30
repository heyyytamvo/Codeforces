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

int rowInput, columnInput, indexCounting;
vector<string> result;
int numberOfTestCase;
string sentence = "ALLIZZWELL";
string matrix[MAX];
bool charDetect[MAX][MAX];
char currentChar;
const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0};



bool valid(cell newCell){
    return ((newCell.row >= 0 && newCell.row < rowInput) && (newCell.column >= 0 && newCell.column < columnInput));
}

void input(){
    cin >> rowInput >> columnInput;
    indexCounting = 0;
    currentChar = sentence[indexCounting];
    memset(charDetect, false, sizeof(charDetect));

    for (int i = 0; i < rowInput; i++){
        string value;
        cin >> value;

        matrix[i] = value;
    }
}

void DFS(cell Cell){
    if (matrix[Cell.row][Cell.column] == sentence[indexCounting] && !charDetect[Cell.row][Cell.column]){
        charDetect[Cell.row][Cell.column] = true;
        indexCounting += 1;
        return;
    }

    for (int i = 0; i < 4; i++){
        int newX = Cell.row + vectorX[i];
        int newY = Cell.column + vectorY[i];

        if (valid((cell) {newX, newY}) && !charDetect[Cell.row][Cell.column]){
            DFS((cell){newX, newY});
        }
    }

    return;
}

int main(){
    /*
    cin >> numberOfTestCase;

    while (numberOfTestCase > 0){
        input();
        
        for (int i = 0; i < rowInput; i++){
            for (int j = 0; j < columnInput; j++){
                if (visited[i][j] == false){
                    DFS((cell){i, j});
                }
            }
        }
    
        if (indexCounting == 11){
            cout << "YES";
        }

        //new loop
        numberOfTestCase--;
    }
    */

    input();
    cout << matrix[0][1];

    for (int i = 0; i < rowInput; i++){
        for (int j = 0; j < columnInput; j++){
            if (!charDetect[i][j]){
                DFS((cell){i, j});
            }
        }
    }
    
    if (indexCounting == 11){
        cout << "YES";
    }



    return 0;
}

