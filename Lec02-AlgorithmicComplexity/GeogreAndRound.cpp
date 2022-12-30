#include <iostream>
using namespace std;

int main(){
    int n, m;
    int N[3001], M[3001];
    
    /*debug
    n = 4;
    m = 6;
    int N[4] = {1, 7, 9, 10};
    int M[6] = {1, 3, 5, 6, 7, 12};
    DEBUG*/

    

    //take input n, m
    cin>>n>>m;
    // NOTE: the maximum numbers of problems that need to be prepared is n problems
    int result = n;
    
    //take input for array N
    
    for (int i = 0; i < n; i++){
        cin >> N[i];
    }

    //take input for array M
    for (int i = 0; i < m; i++){
        cin >> M[i];
    }
    
    //for the case n > m
    if (n > m){
        //if everything George prepared does not sastified, he had to prepare n problems
        if (M[m - 1] < N[0]){
            cout << n;
            return 0;
        }

        int subN[3001];        
        for (int i = 0; i < m; i++){
            subN[i] = N[i];
        }
        int startIndexSubN = 0;
        for (int i = 0; i < m; i++){
            if (M[i] >= subN[startIndexSubN]){
                result -= 1;
                startIndexSubN += 1;
                continue;
            }
        }

        cout << result;
        return 0;

    }
    

    //for the case n < m
    if (n <= m){
        //if everything George prepared does not sastified, he had to prepare n problems
        if (M[m - 1] < N[0]){
            cout << n;
            return 0;
        }

        int subM[3001];        
        for (int i = 0; i < n; i++){
            subM[i] = M[m - n + i];
        }
        int startIndexN = 0;
        for (int i = 0; i < n; i++){
            if (subM[i] >= N[startIndexN]){
                result -= 1;
                startIndexN += 1;
                continue;
            }
        }

        cout << result;
        return 0;
    }
    return 0;
}
