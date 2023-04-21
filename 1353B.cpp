#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool compareIntReverse(const int& i1, const int& i2) {
    return i1 > i2; // Use ">" to sort in descending order
}

int numberOfTestCase;
int sumA = 0;
int sumB = 0;
vector<int> ListA;
vector<int> ListB;
int n, k;
int main(){
    cin >> numberOfTestCase;

    for (int i = 0; i < numberOfTestCase; i++){
        cin >> n >> k;

        for (int j = 0; j < n; j++){
            int number;
            cin >> number;
            sumA += number;
            ListA.push_back(number);
        }

        for (int j = 0; j < n; j++){
            int number;
            cin >> number;
            sumB += number;
            ListB.push_back(number);
        }

        sort(ListA.begin(), ListA.end(), compareIntReverse);
        sort(ListB.begin(), ListB.end());
        
        int performSwitchingCount = 0;
        int indexA = n - 1;
        int indexB = n - 1;
        while (performSwitchingCount < k && indexA >= 0 && indexB >= 0){
            if (ListA[indexA] < ListB[indexB]){
                sumA -= ListA[indexA];
                sumA += ListB[indexB];
                indexA--;
                indexB--;
                performSwitchingCount++;
            }else{
                break;
            }
        }
        cout << sumA << endl;
        //reset
        sumA = 0;
        sumB = 0;
        ListA.clear();
        ListB.clear();
    }

    

    return 0;
}