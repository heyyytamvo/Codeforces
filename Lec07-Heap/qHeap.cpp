#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
multiset<int, less<int> > pq;
int numberOfQuery;
vector<int> Result;


void insert(int number){
    pq.insert(number);
}

void deletingElement(int number){
    pq.erase(number);
}

void Root(){
    Result.push_back(*pq.begin());
}


int main(){
    cin >> numberOfQuery;

    for (int i = 0; i < numberOfQuery; i++){
        int type;
        cin >> type;
        if (type == 3){
            Root();
        }else{
            if (type == 1){
                int number;
                cin >> number;
                insert(number);
            } else if (type == 2){
                long int value;
                cin >> value;
                deletingElement(value);
            }
        }
    }

    for (int i = 0; i < Result.size(); i++){
        cout << Result[i] << endl;
    }

    return 0;
}

