#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int k, n, w;

int main(){
    cin >> k >> n >> w;

    long int times = ((1 + w) * w) / 2;
    long int total = k * times;
    long int result = total - n;
    if (result < 0){
        cout << 0;
        return 0;
    }

    cout << result;
    return 0;
}