#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int t; cin >> t;
    while(t-->0){
        int n, m; cin >> n >> m;
        cout << 2 - n  + m << '\n';
    }
    
    return 0;
}
