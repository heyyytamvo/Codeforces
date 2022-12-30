#include <iostream>
#include <queue>

using namespace std;

int numberOfTestCase;
int n, m;
vector<int> Result;


int main(){
    cin >> numberOfTestCase;
    queue< pair<int, int> > q; //prior ID
    priority_queue< pair<int, int> > pq; //prior ID
    while (numberOfTestCase > 0){
        cin >> n >> m;
        int ID = 0;
        int tempResult = 0;
        
        //reset
        int sizeQ = q.size();
        int sizePQ = pq.size();

        for (int i = 0; i < sizeQ; i++){
            q.pop();
        }

        for (int i = 0; i < sizePQ; i++){
            pq.pop();
        }

        for (int i = 0; i < n; i++){
            int paper;
            cin >> paper;
            q.push(make_pair(paper, ID));
            pq.push(make_pair(paper, ID));
            ID++;
        }

        while (true){

            pair<int, int> next = q.front();
            if (next.first < pq.top().first){
                q.pop();
                q.push(next);
                continue;
            }

            if (next.first == pq.top().first){
                if (next.second == m){
                    tempResult++;
                    Result.push_back(tempResult);
                    break;
                }
                q.pop();
                pq.pop();
                tempResult++;
                continue;
            }

        }

        //new
        numberOfTestCase--;
    }

    for (int i = 0; i < Result.size(); i++){
        cout << Result[i] << endl;
    }

    return 0;
}