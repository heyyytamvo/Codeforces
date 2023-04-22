#include <iostream>
using namespace std;
const long long num = 5 * 1e5 + 1;

long long output[num];
int n;
int main(){
    output[1] = 0;
    for (long long i = 2; i < num / 2 + 1; i++){
        output[i] = output[i - 1] + 8 * (i - 1) * (i - 1);
    }

    cin >> n;
    int num;
    for (int i = 0; i < n; i++){
        
        scanf("%lld", &num);
        printf("%lld\n", output[(num + 1) / 2]);
    }

    return 0;
}