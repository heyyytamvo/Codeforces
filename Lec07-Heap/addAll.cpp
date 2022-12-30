#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<unsigned long long	> Result;
priority_queue<unsigned long long	, vector<unsigned long long	>, greater<unsigned long long	> > pq;

int numberOfInput;
int main(){
    while (true){
        cin >> numberOfInput;
        unsigned long long	 result = 0;
        
        if (numberOfInput == 0){
            break;
        }

        for (int i = 0; i < numberOfInput; i++){
            unsigned long long	 value;
            cin >> value;
            pq.push(value);
        }

        unsigned long long	 temp = result;

        while (pq.size() > 1){
            unsigned long long	 first = pq.top();
            pq.pop();
            unsigned long long	 second = pq.top();
            pq.pop();
            unsigned long long	 temp = first + second;
            result += temp;
            pq.push(temp);
        }

    
        Result.push_back(result);
        pq.pop();
    }

    for (int i = 0; i < Result.size(); i++){
        cout << Result[i] << endl;
    }

    return 0;
}