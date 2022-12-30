#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int numberOfOperation;
priority_queue<int> pq;
priority_queue< int, vector<int>, greater<int> > list;


int main(){
    cin >> numberOfOperation;
    int totalRatings = 0;
    while (numberOfOperation > 0){
        int type;
        cin >> type;

        if (type == 1){
            int number;
            cin >> number;
            totalRatings += 1;
            if (totalRatings < 3){
                pq.push(number);
                
            }else{
                int maxSize = floor(totalRatings / 3);
                if (list.size() < maxSize){
                    list.push(number);
                    if (list.top() <= pq.top()){
                        int goToList = pq.top();
                        int goToPq = list.top();

                        pq.pop();
                        list.pop();

                        pq.push(goToPq);
                        list.push(goToList);
                    }

                }else{
                    pq.push(number);
                    if (list.top() <= pq.top()){
                        int goToList = pq.top();
                        int goToPq = list.top();

                        pq.pop();
                        list.pop();

                        pq.push(goToPq);
                        list.push(goToList);
                    }
                }
            }
            
        }
        if (type == 2){
            if (totalRatings < 3){
                cout << "No reviews yet" << endl;
                numberOfOperation--;
                continue;
            }

            cout << list.top() << endl; 
        }

        numberOfOperation--;
    }
}