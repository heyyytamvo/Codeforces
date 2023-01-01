#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int num;
string input;
map<int, int> Dict; //charAscii + number


int main(){
    cin >> num;
    cin >> input;

    for (int i = 0; i < num; i++){
        int charAscii = input[i];
        
        if (charAscii > 90){
            charAscii -= 32; 
        }

        if (Dict.find(charAscii) == Dict.end()){
            //not found
            Dict.insert(pair<int, int>(charAscii, 1));
        }else{
            Dict[charAscii] += 1;
        }
    }

    if (Dict.size() == 26){
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}