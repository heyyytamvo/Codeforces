#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct car{
    int id;
    int minute;
    string side;
};

//0 denotes left
//1 denote right
int numberTestCase, n, t, m;
int clockFerry;
int currentSide;
queue<car> waitingCar[2];


void waiting(int time){
    if (clockFerry < time){
        clockFerry = time;
    }
    return;
}

int main(){
    cin >> numberTestCase;
    
    while (numberTestCase > 0){
        //user input
        cin >> n >> t >> m;
        for (int i = 0; i < m; i++){
            int time;
            string side;

            cin >> time >> side;
            if (side == "left"){
                waitingCar[0].push((car) {i, time, side});
                continue;
            }
            waitingCar[1].push((car) {i, time, side});
        }
        //user input

        //initiallize
        clockFerry = 0;
        currentSide = 0;
        int waiting = !waitingCar[0].empty() + !waitingCar[1].empty();
        int result[10001]; 
        //initiallize

        //processing
        while (waiting){
            int nextTime;
            //if there are no empty queue in two queue
            if (!waitingCar[0].empty() && !waitingCar[1].empty()){
                if (waitingCar[0].front().minute < waitingCar[1].front().minute){
                    nextTime = waitingCar[0].front().minute;
                    
                }else{
                    nextTime = waitingCar[1].front().minute;
                }
                //
            }else{
                if (waitingCar[0].empty()){
                    nextTime = waitingCar[1].front().minute;
                }else{
                    nextTime = waitingCar[0].front().minute;
                }
            }

            clockFerry = max(clockFerry, nextTime);

            int numberOfCarOnFerry = 0;
            
            //checking the current side of the ferry
            while (!waitingCar[currentSide].empty()){
                car frontCar = waitingCar[currentSide].front();
                if (frontCar.minute <= clockFerry && numberOfCarOnFerry < n){
                    int arrivedTime = clockFerry + t;
                    result[frontCar.id] = arrivedTime;
                    waitingCar[currentSide].pop();
                    numberOfCarOnFerry++;
                }else{
                    break;
                }
            }

            //go to another side
            clockFerry += t;
            currentSide = 1 - currentSide;
            waiting = !waitingCar[0].empty() + !waitingCar[1].empty();
        }
            
        for (int i = 0; i < m; i++){
            cout << result[i] << endl;
        }

        //new loop

        if (numberTestCase != 1){
            cout << endl;
        }
        numberTestCase -= 1;
    }

    return 0;
}