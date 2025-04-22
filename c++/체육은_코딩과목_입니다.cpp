#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n = 0;
    
    for(int i = 0 ; i < 10; i++){
        int d; cin >> d;
        if(d == 1) n++;
        if(d == 2) n += 2;
        if(d == 3) n--;
        n = (n + 4) % 4;
    }

    if (n == 0) cout << "N";
    else if(n == 1) cout << "E";
    else if(n == 2) cout << "S";
    else if(n == 3) cout << "W";
    return 0;
}