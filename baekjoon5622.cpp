#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int cnt = 0;
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] < 83)                   // ASCII S is first 4th alphabet hangs at 7
            cnt += (s[i] - 65) / 3 + 3; // 65 == 'A'
        else if(s[i] < 90) {
            cnt += (s[i] - 81) / 3 + 8; // S to Y
        }
        else
            cnt += 10;                  //Z
    }

    cout << cnt;

}
