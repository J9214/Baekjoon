#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
#define modulo 1000000000000

int main(){
    FASTIO

    int n; cin >> n;
    ll res = 1;
    for(ll i = 1; i <= n ; i++){
        res *= i;
        while(!(res % 10)) res /= 10;
        res %= modulo;
    }

    res %= 100000;
    cout << setw(5) << setfill('0') << res;
    
}