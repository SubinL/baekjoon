#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

void turn(int n, int cl, bool w[4][8], int* idx){
    int ni[4];                                  //temporary new index of north for each wheel
    memcpy(ni, idx, sizeof(int) * 4);           //to turn wheels simultaniously

    int dir = cl;
    for (int i=n; i>0; i--){                    // turn left cogwheels
        if (w[i-1][(idx[i-1] + 2) % 8] ^ w[i][(idx[i] + 6) % 8]){   // if facing pole is diff
            ni[i-1] = (idx[i-1] + 8 + dir) % 8;
            dir *= -1;                          //direction should be opposite from neighbor wheel
        }
        else break;
    }

    dir = cl;
    for (int i=n; i<3; i++){                    // turn right cogwheels
        if ((w[i][(idx[i] + 2) % 8] ^ w[i+1][(idx[i+1] + 6) % 8])){   // if facing pole is diff
            ni[i+1] = (idx[i+1] + 8 + dir) % 8;
            dir *= -1;

        }
        else break;
    }
    ni[n] = (idx[n] + 8 - cl) % 8;             // change given cogwheel's north

    memcpy(idx, ni, sizeof(int) * 4);          // set index to new index
}


int main(void) {

    bool cogwheel[4][8];
    for (int i=0; i<4; i++){
        for (int j=0; j<8; j++){
            scanf("%1d", &cogwheel[i][j]);
        }
    }

    int k, wheelNum, clockwise, ans = 0, idx[4] = {0,};
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> wheelNum >> clockwise;
        turn(wheelNum - 1, clockwise, cogwheel, idx);
    }

    for (int i=0; i<4; i++){
        ans += cogwheel[i][ idx[i] ] * pow(2, i);
    }
    cout << ans;
}
