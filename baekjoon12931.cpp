#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n, b[50], cnt = 0;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++){
        cin >> b[i];
    }

    while(true){
        for (int i=0; i<n; i++){
            if (b[i] % 2) {            // if odd
                b[i] -= 1;             // make it even
                cnt++;                 // +1 to one element operation
            }
            b[i] /= 2;                 // *2 to all element operation
        }
        if(*max_element(b, b+n) <= 0) break;    //break before counting 0*2 operation when all elements are 0
        cnt++;
    }

    printf("%d", cnt);
}
