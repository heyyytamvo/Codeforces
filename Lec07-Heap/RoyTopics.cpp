#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int numberOfTopics;
priority_queue< pair<long int, long int> > pq;
map<long int, long int> Dict;
vector< pair<long int, long int> > tempResult; // changes ID

int main(){
    cin >> numberOfTopics;
    
    for (int i = 0; i < numberOfTopics; i++){
        long int ID;
        long int z, p, l, c, s;
        cin >> ID >> z >> p >> l >> c >> s;
        long int changes = (50 * p + 5 * l + 10 * c + 20 * s) - z;
        long int newZ = z + changes;
        Dict.insert(pair<long int, long int>(ID, newZ));
        pq.push(make_pair(changes, ID));
    }

    pair<long int, long int> firstElement = pq.top();
    pq.pop();
    tempResult.push_back(firstElement);

    while (tempResult.size() < 5){
        pair<long int, long int> nextValue = pq.top();
        pq.pop();
        tempResult.push_back(nextValue);

        //swapping if z is equal
        int insertedValueIndex = tempResult.size() - 1;
        int nextChecking = insertedValueIndex - 1;

        while (nextChecking >= 0 && tempResult[insertedValueIndex].first == tempResult[nextChecking].first && tempResult[insertedValueIndex].second > tempResult[nextChecking].second){
            swap(tempResult[insertedValueIndex], tempResult[nextChecking]);
            insertedValueIndex -= 1;
            nextChecking -= 1;
        }
    }

    for (int i = 0; i < 5; i++){
        cout << tempResult[i].second << " " << Dict[tempResult[i].second] << endl;
    }

    

    return 0;
}
