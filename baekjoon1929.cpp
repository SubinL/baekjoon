#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    bool *composite = new bool[n + 1];

    fill_n(composite, n+1, 0);
    composite[1] = 1;

    for(int i = 2; i * i <= n; i++){
        for(int j = i * i; j <= n; j += i){
            composite[j] = 1;
        }

    }
    for(int i = m; i <= n; i++){
        if(!composite[i])
            printf("%d\n", i);
    }

    delete []composite;
    return 0;
}
