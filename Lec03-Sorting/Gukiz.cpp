#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


vector<int> Check(int rating, vector<int> listRating){
    vector<int> result;
    for (int i = 0; i < listRating.size(); i++){
        if (listRating[i] == rating){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    int numberStudent;
    vector<int> rating;
    vector<int> distinct;
    int Result[10000];

    cin >> numberStudent;
    for (int i = 0; i < numberStudent; i++){
        int value;
        cin >> value;

        rating.push_back(value);
        if (count(distinct.begin(), distinct.end(), value)){
            continue;
        }else{
            distinct.push_back(value);
        }
    }

    sort(distinct.begin(), distinct.end());
    reverse(distinct.begin(), distinct.end());
    //processing
    int rank = 1;

    for (int rankIndex = 0; rankIndex < distinct.size(); rankIndex++){
        vector<int> peopleArward;
        peopleArward = Check(distinct[rankIndex], rating);

        for (int i = 0; i < peopleArward.size(); i++){
            Result[peopleArward[i]] = rank;
        }

        rank += peopleArward.size();
    }

    for (int i = 0; i < numberStudent; i++){
        cout << Result[i] << " ";
    }

    return 0;
}