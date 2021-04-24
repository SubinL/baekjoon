#include <iostream>
using namespace std;

int main(void) {
    int n, i = 2;
    cin >> n;
    while(i <= n){
        if(n%i == 0){
            n /= i;
            cout << i << endl;
        }
        else
            i++;
    }
}
