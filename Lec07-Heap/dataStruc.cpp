#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int numberOfOperation;
queue<int> numQueue;
priority_queue<int> NumPQ;
stack<int> numStack;
bool isStack, isQueue, isPQ;
bool passCheckStack, passCheckQueue, passCheckPQ, noInput;


void reset(){
    isStack = true;
    isQueue = true;
    isPQ = true;
    noInput = false;
    int queueSize = numQueue.size();
    int stackSize = numStack.size();
    int PQsize = NumPQ.size();

    for (int i = 0; i < queueSize; i++){
        numQueue.pop();
    }

    for (int i = 0; i < stackSize; i++){
        numStack.pop();
    }

    for (int i = 0; i < PQsize; i++){
        NumPQ.pop();
    }
}

int main() {
    int numberOfOperation, type, x;
    
    while (cin >> numberOfOperation) {
        
        reset();
        for (int i = 0; i < numberOfOperation; i++){
            cin >> type >> x;
            if (type == 1){
                numQueue.push(x);
                numStack.push(x);
                NumPQ.push(x);
            }else if (type == 2)
            {
                /* code */
                if (numQueue.empty() && numStack.empty() && NumPQ.empty()){
                    isStack = false;
                    isQueue = false;
                    isPQ = false;
                    continue;
                }

                if (x != numQueue.front()){
                    isQueue = false;
                    
                }
                
                if (x != numStack.top()){
                    isStack = false;
                    
                }

                if (x != NumPQ.top()){
                    isPQ = false;
                    
                }
                numQueue.pop();
                numStack.pop();
                NumPQ.pop();

            }
        }

        if (isStack && isQueue && !isPQ){
            cout << "not sure" << endl;
            continue;
        }else if (isStack && !isQueue && isPQ){
            cout << "not sure" << endl;
            continue;
        }else if (!isStack && isQueue && isPQ){
            cout << "not sure" << endl;
            continue;
        }else if (isStack && isQueue && isPQ){
            cout << "not sure" << endl;
            continue;
        }

        if (isQueue){
            cout << "queue" << endl;
            continue;
        }else if (isStack){
            cout << "stack" << endl;
            continue;
        }else if (isPQ){
            cout << "priority queue" << endl;
            continue;
        }

        
        if (!isStack && !isQueue && !isPQ && !noInput){
            cout << "impossible" << endl;
            continue;
        }

        if (noInput){
            cout << "impossible" << endl;
        }

    }
    return 0;
}
