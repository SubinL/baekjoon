#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void print(int x){
    cout << x << " ";
}

int main(void) {
    string s;
    cin >> s;
    int a[26];
    fill_n(a, 26, -1);
    for(int i = 0; i < s.size(); i++){
        if(a[s[i] - 0x61] == -1)
            a[s[i] - 0x61] = i;
    }
    for_each(a, &a[26], print);
}
