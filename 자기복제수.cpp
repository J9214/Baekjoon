#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    int t; cin >> t;
    while(t--){
        int n ; cin >> n;
        int d = floor(log10(n)) + 1;

        if((n * n) % int(pow(10,d)) == n) cout << "YES";
        else cout << "NO";
        cout << '\n';

    }
    
    return 0;
}