#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numberInput;
    int array[1001];

    //user input
    cin >> numberInput;
    
    for (int i = 0; i < numberInput; i++){
        cin >> array[i];
    }
    //user input

    int SerejaPoints = 0;
    int DimaPoints = 0;

    int left = 0;
    int right = numberInput - 1;

    bool SerejaTurn = true;
    int done = right - left;
    while (right != left){
        if (SerejaTurn){
            //choose left
            if (array[left] > array[right]){
                SerejaPoints += array[left];
                left += 1;
                SerejaTurn = false;
                continue;
            }

            //choose right
            if (array[left] < array[right]){
                SerejaPoints += array[right];
                right -= 1;
                SerejaTurn = false;
                continue;
            }
        }else{
            //choose left
            if (array[left] > array[right]){
                DimaPoints += array[left];
                left += 1;
                SerejaTurn = true;
                continue;
            }
            //choose right
            if (array[left] < array[right]){
                DimaPoints += array[right];
                right -= 1;
                SerejaTurn = true;
                continue;
            }
        }
    }

    //last turn
    if (SerejaTurn){
        SerejaPoints += array[left];
    }else{
        DimaPoints += array[left];
    }

    cout << SerejaPoints << " " << DimaPoints;
    return 0;
}