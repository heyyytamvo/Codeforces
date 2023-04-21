#include <iostream>

using namespace std;

int numberOfTestCase;
int n, m;
int main(){
    cin >> numberOfTestCase;

    for (int i = 0; i < numberOfTestCase; i++){
        cin >> n >> m;

        if (n == 1){
            cout << 0 << endl;
        }else if (n == 2){
            cout << m << endl;
        }else{
            cout << 2 * m << endl;
        }
    }

    return 0;
}