#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

int main(){
    FASTIO

    ll n; cin >> n;
    ll res = n * (n-1) / 2;
    while(n--){
        ll x; cin >> x;
        res -= x;
    }
    cout << -res;
}