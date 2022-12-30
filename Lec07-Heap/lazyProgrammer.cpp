#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>

using namespace std;

int numberOfTestCase;
vector<double> finalResult;
int main(){
    cin >> numberOfTestCase;

    /*
    double c = 1;
    double b = 4;
    double a = c / b;
    printf("%.02f", a);
    */

    while (numberOfTestCase > 0){
        int numberOfContract;
        cin >> numberOfContract;
        double result = 0;
        for (int i = 0; i < numberOfContract; i++){
            double a, b, d;
            cin >> a >> b >> d;
            if (b - d <= 0){
                continue;
            }

            double time = b - d;
            double temp = (b - time) / a;
            result += temp;
        }

        finalResult.push_back(result);
        numberOfTestCase--;
    }

    for (int i = 0; i < finalResult.size(); i++){
        printf("%.02f", finalResult[i]);
        cout << endl;
    }
    


    return 0;
}