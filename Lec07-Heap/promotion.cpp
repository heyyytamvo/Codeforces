#include <iostream>
#include <vector>
#include <queue>
#define MaxNum 1000001

using namespace std;



int numberOfDays;
long int finalResult = 0;
int arrayMin[MaxNum];
int arrayMax[MaxNum];
bool Taken[MaxNum];
int Index = 0;
//int minHold;
//int maxHold;

priority_queue< pair<int, int> > maxPQ; //price, number
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > minPQ;
int main(){
    cin >> numberOfDays;
    int billIndex = 0;
    while (numberOfDays > 0){
        int numberOfReceipt;
        cin >> numberOfReceipt;

        for (int i = 0; i < numberOfReceipt; i++){
            int bill;
            cin >> bill;
            minPQ.push(make_pair(bill, billIndex));
            maxPQ.push(make_pair(bill, billIndex));
            Taken[billIndex] = false;
            billIndex++;
        }
    
        /*
        if (numberOfReceipt == 2 && minPQ.size() == 2 && maxPQ.size() == 2){
            arrayMin[Index] = minPQ.top().first;

            arrayMax[Index] = maxPQ.top().first;
            numberOfDays--;
            Index++;

            for (int i = 0; i < 2; i++){
                minPQ.pop();
                maxPQ.pop();
            }

            continue;
        }*/


        while (Taken[minPQ.top().second]){
            minPQ.pop();
        }
        

        while (Taken[maxPQ.top().second])
        {
            maxPQ.pop();
        }
        
        int minTop = minPQ.top().first;
        Taken[minPQ.top().second] = true;
        minPQ.pop();
        int maxTop = maxPQ.top().first;
        Taken[maxPQ.top().second] = true;
        maxPQ.pop();
        /*
        if (Index == 0){
            minHold = minPQ.top();
            maxHold = maxPQ.top();
        }*/

        arrayMin[Index] = minTop;
        arrayMax[Index] = maxTop;

        
        //new day
        numberOfDays--;
        Index++;
    }

    while (Index >= 0){
        finalResult += arrayMax[Index] - arrayMin[Index];
        Index--;
    }
    cout << finalResult;
}