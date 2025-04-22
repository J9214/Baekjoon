#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

pair<ll, ll> inv(ll a, ll b){
    if(!b) return {1,0};
    ll x, y;
    tie(x,y) = inv(b, a%b);
    return {y, x - (a / b) * y};
}

int main(){
    FASTIO
    ll n, k, result = 1;

    cin >> n >> k;

    cout << n - k << ' ';
    if(gcd(n,k) == 1) {
        pair<ll, ll> res = inv(k, n);
        cout << (res.first + n) % n;
    }
    else cout << -1;

    return 0;
}