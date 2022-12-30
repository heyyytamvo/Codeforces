#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n, a, b;
    vector<int> complexity;

    //user input
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++){
        int value;
        cin >> value;

        complexity.push_back(value);
    }

    sort(complexity.begin(), complexity.end());

    int indexVasya = n - a - 1;
    int indexPetya = indexVasya + 1;

    if (n == 2){
        cout << complexity[1] - complexity[0];
        return 0;
    }

    int result = complexity[indexPetya] - complexity[indexVasya];
    cout << result;

    return 0;
}