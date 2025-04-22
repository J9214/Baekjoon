#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    long long n, m; cin >> n >> m;
    long long s = 0;
    long long mi = 0;
    for(int i = floor(sqrt(n)); i < 10001; i++){
        long long po = pow(i,2);
        if(po > m) break;
        if(po >= n and po <= m) {
            s += po;
            if(mi == 0) mi = po;
        }
    }

    if(s == 0) cout << -1;
    else cout << s << '\n' << mi;
    return 0;   
}
