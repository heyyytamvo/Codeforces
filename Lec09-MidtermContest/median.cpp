#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> list;
int totalNum;
int main(){
    cin >> totalNum;
    for (int i = 0; i < totalNum; i++){
        int num;
        cin >> num;

        list.push_back(num);
    }

    sort(list.begin(), list.end());

    if (totalNum % 2 == 1){
        int mid = floor(totalNum / 2);
        cout << list[mid];
    }else{
        int begin = 0;
        int end = totalNum - 1;

        while (end - begin != 1){
            begin++;
            end--;
        }

        int med = (list[end] + list[begin]) / 2;
        cout << med;
    }

    return 0;
}