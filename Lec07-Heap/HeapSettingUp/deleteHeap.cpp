#include <iostream>
#include <vector>

using namespace std;

vector<int> MinH;

void settingUp(){
    MinH.push_back(2);
    MinH.push_back(3);
    MinH.push_back(6);
    MinH.push_back(4);
    MinH.push_back(17);
    MinH.push_back(15);
    MinH.push_back(7);
    MinH.push_back(12);
    MinH.push_back(10);
}

void buildingMinHeap(int index){
    int smallest = index;
    int childLeftIndex = index * 2 + 1;
    int childRightIndex = index * 2 + 2;

    if (childLeftIndex < MinH.size() && MinH[childLeftIndex] < MinH[smallest]){
        smallest = childLeftIndex;
    }

    if (childRightIndex < MinH.size() && MinH[childRightIndex] < MinH[smallest]){
        smallest = childRightIndex;
    }

    if (smallest != index){
        swap(MinH[index], MinH[smallest]);
        buildingMinHeap(smallest);
    }
}

void deleteRoot(){
    int lastIndex = MinH.size() - 1;
    swap(MinH[lastIndex], MinH[0]);
    MinH.pop_back();

    buildingMinHeap(0);
}

int main(){
    settingUp();
    for (int i = MinH.size()/2 - 1; i >= 0; i--){
        buildingMinHeap(i);
    }

    deleteRoot();

    for (int i = 0; i < MinH.size(); i++){
        cout << MinH[i] << " ";
    }

    return 0;

}

