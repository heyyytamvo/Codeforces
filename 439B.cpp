#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long numberOfSubject, learningMinute;
    vector<long long> chapter;

    //user input
    cin >> numberOfSubject >> learningMinute;

    for (long long i = 0; i < numberOfSubject; i++){
        long long value;
        cin >> value;

        chapter.push_back(value);
    }

    sort(chapter.begin(), chapter.end());

    long long result = 0;
    for (long long i = 0; i < numberOfSubject; i++){
        result += chapter[i] * learningMinute;
        learningMinute -= 1;

        if (learningMinute == 0){
            learningMinute += 1;
            continue;
        }
    }

    cout << result;
    return 0;
}