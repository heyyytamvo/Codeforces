#include <iostream>
using namespace std;

int main(){
    int numberOfBooks, freeMinutes;
    int array[100001];
    //user input
    cin >> numberOfBooks >> freeMinutes;
    

    for (int i = 0; i < numberOfBooks; i++){
        cin >> array[i];
    }
    

    int startBook = 0;
    int readTime = 0;
    int result = 0;
    
    for (int endBook = 0; endBook < numberOfBooks; endBook++)
    {
        readTime += array[endBook];

        while (readTime > freeMinutes){
            readTime -= array[startBook];
            startBook += 1;
        }

        result = max(result, endBook - startBook + 1);
    }
    

    cout << result;
    return 0;

}