#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int vectorX[4] = {0, 1, 0, -1};
const int vectorY[4] = {1, 0, -1, 0}; 

/*OOP design ------RUNTIME ERROR-----------
class Graph{
    //attribute
    public:
    int G_row, G_column;
    char matrix[21][21];
    vector< pair<int, int> > Entries;
    bool visited[1000][1000];

    

    //contructor
    Graph(){
        memset(visited, false, sizeof(visited));
    }

    //method
    void FindingEntryPoints(){
        for (int i = 0; i < G_row; i++){
            for (int j = 0; j < G_column; j++){
                if ((matrix[i][j] == '.') && ((i == 0) || (i == G_row - 1) || (j == 0) || (j == G_column - 1))){
                    pair<int, int> position;

                    position.first = i;
                    position.second = j;

                    Entries.push_back(position);
                }
            }
        }
    }

    bool Valid(int x, int y){
        if (((x >= 0) && (x < G_row) && (y >= 0) && (y < G_column)) && (matrix[x][y] == '.')){
            return true;
        }

        return false;
    }

    void BFS(pair<int, int> start, pair<int, int> end){
        queue< pair<int, int> > waitingQueue;
        waitingQueue.push(start);
        visited[start.first][start.second] = true;

        while (waitingQueue.empty() == false){
            pair<int, int> value = waitingQueue.front();
            waitingQueue.pop();

            if (value == end){
                cout << "valid" << endl;
                return;
            }

            for (int i = 0; i < 4; i++){
                int newX = value.first + vectorX[i];
                int newY = value.second + vectorY[i];

                if (Valid(newX, newY)){
                    pair<int, int> newPair;
                    newPair.first = newX;
                    newPair.second = newY;
                    waitingQueue.push(newPair);
                    visited[newX][newY] = true;
                }
            }
        }

        cout << "invalid" << endl;
        return;
    }
};


int numberOfTestCase;
vector<Graph> Data;
 

void input(){
    cin >> numberOfTestCase;

    for (int i = 0; i < numberOfTestCase; i++){
        int row,column;
        cin >> row >> column;

        Graph newGraph = Graph();
        newGraph.G_row = row;
        newGraph.G_column = column;

        for (int rowIndex = 0; rowIndex < row; rowIndex++){
            string value;
            cin >> value;    
            for (int columnIndex = 0; columnIndex < column; columnIndex++){
                newGraph.matrix[rowIndex][columnIndex] = value[columnIndex];
            }
        }

        Data.push_back(newGraph);
    }
}

int main(){
    input();
    for (int i = 0; i < numberOfTestCase; i++){
        Graph graph = Data[i];
        graph.FindingEntryPoints();

        //if the number of finding entry points is not 2, then the maze will be not valid
        if (graph.Entries.size() != 2){
            cout << "invalid" << endl;
            continue;
        }

        graph.BFS(graph.Entries[0], graph.Entries[1]);
    
    }
    return 0;
}
*/

int numberTestCase;
bool visited[21][21];

bool Valid(int x, int y, int G_row, int G_column, char matrix[21][21]){
        if (((x >= 0) && (x < G_row) && (y >= 0) && (y < G_column)) && (matrix[x][y] == '.')){
            return true;
        }

        return false;
    }



string BFS(pair<int, int> start, pair<int, int> end, int row, int column, char matrix[21][21]){
    queue< pair<int, int> > waitingQueue;
    waitingQueue.push(start);
    visited[start.first][start.second] = true;

    while (waitingQueue.empty() == false){
        pair<int, int> value = waitingQueue.front();
        waitingQueue.pop();

        if (value == end){
            return "valid";
        }

        for (int i = 0; i < 4; i++){
            int newX = value.first + vectorX[i];
            int newY = value.second + vectorY[i];

            if (Valid(newX, newY, row, column, matrix)){
                pair<int, int> newPair;
                newPair.first = newX;
                newPair.second = newY;
                waitingQueue.push(newPair);
                visited[newX][newY] = true;
            }
        }
    }
    return "invalid"; 
}

int main(){
    cin >> numberTestCase;
    vector<string> result;
    for (int i = 0; i < numberTestCase; i++){
        int row, column;
        char matrix[21][21];
        vector< pair<int, int> > Entries;
        
        cin >> row >> column;
        for (int rowIndex = 0; rowIndex < row; rowIndex++){
            string value;
            cin >> value;

            for (int columnIndex = 0; columnIndex < column; columnIndex++){
                matrix[rowIndex][columnIndex] = value[columnIndex];
                visited[rowIndex][columnIndex] = false;
            }
        }

        //finding entries
        for (int j = 0; j < row; j++){
            for (int k = 0; k < column; k++){
                if ((matrix[j][k] == '.') && ((j == 0) || (j == row - 1) || (k == 0) || (k == column - 1))){
                    pair<int, int> position;

                    position.first = j;
                    position.second = k;

                    Entries.push_back(position);
                }
            }
        }

        if (Entries.size() != 2){
            result.push_back("invalid");
            continue;
        }
        result.push_back(BFS(Entries[0], Entries[1], row, column, matrix));
    }

    for (int index = 0; index < numberTestCase; index++){
        cout << result[index] << endl;
    }

    return 1;
}