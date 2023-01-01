#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, x, y;
    int soldier[100005];
    int vest[100005];

    //userInput
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++){
        cin >> soldier[i];
    }

    for (int i = 0; i < m; i++){
        cin >> vest[i];
    }
    //userInput

    vector<int> result;
    int total = 0;
    int soldierIndex = 0;
    for (int vestIndex = 0; vestIndex < m; vestIndex++){

       while ((soldierIndex < n) && (vest[vestIndex] > soldier[soldierIndex] + y))
        {
            /* code */
            soldierIndex++;
        }

        if (soldierIndex == n){
            break;
       }

       if ((vest[vestIndex] >= soldier[soldierIndex] - x) && (vest[vestIndex] <= soldier[soldierIndex] + y)){
            total++;
            result.push_back(soldierIndex + 1);
            result.push_back(vestIndex + 1);
            soldierIndex++;
       }
    }

    cout << total << endl;
    int count = 0;
    while (count < total * 2)
    {
        /* code */
        cout << result[count] << " " << result[count + 1] << endl;
        count += 2;
    }
    
    
    return 0;
}