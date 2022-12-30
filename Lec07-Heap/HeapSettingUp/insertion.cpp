#include <iostream>
#include <vector>

using namespace std;

vector<int> maxH;

void SettingUp(){
    maxH.push_back(50);
    maxH.push_back(30);
    maxH.push_back(20);
    maxH.push_back(15);
    maxH.push_back(10);
    maxH.push_back(8);
    maxH.push_back(16);
}

void insertMaxHeap(int element){
    maxH.push_back(element);
    int itsIndex = maxH.size() - 1;

    while (itsIndex != 0 && maxH[(itsIndex - 1) / 2] < maxH[itsIndex]){
        swap(maxH[itsIndex], maxH[(itsIndex - 1) / 2]);
        itsIndex = (itsIndex - 1) / 2;
    }
}

int main(){
    SettingUp();

    int number;
    cin >> number;

    insertMaxHeap(number);

    for (int i = 0; i < maxH.size(); i++){
        cout << maxH[i] << " ";
    }
}