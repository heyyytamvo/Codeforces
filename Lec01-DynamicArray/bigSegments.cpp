#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main(){
    int numbersOfSegment;
    cin >> numbersOfSegment;


    vector< vector<int> > data;

    for (int k = 0; k < numbersOfSegment; k++)
    {
        /* code */
        vector<int> Coordinate;

        for (int i = 0; i < 2; i++)
        {
            /* code */
            int value;
            cin >> value;
            Coordinate.push_back(value);
        }
        
        data.push_back(Coordinate);
    }

    int indexData;
    int min_X = data[0][0];
    int min_X_index = 0;
    int max_Y = data[0][1];

    //check max Y
    for (int i = 1; i < numbersOfSegment; i++){
        int valueY = data[i][1];
        if (valueY >= max_Y){
            max_Y = valueY;
            continue;
        }        
    }

    //find min X
    for (int i = 0; i < numbersOfSegment; i++){
        int valueX = data[i][0];
        if (valueX <= min_X){
            min_X = valueX;
            continue;
        }        
    }

    //finding existed data
    for (int i = 0; i < numbersOfSegment; i++){
        if ((data[i][0] == min_X) && (data[i][1] == max_Y)){
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}