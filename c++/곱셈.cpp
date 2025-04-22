#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};
ll modulo;

ll mul(ll a, ll b){
    ll res = 1;

    if(!b) return res;
    if(b % 2) return (mul(a ,b - 1) * a + modulo) % modulo;
    ll h = (mul(a, b / 2) + modulo) % modulo;

    return (h * h + modulo) % modulo;
}

int main(){
    FASTIO
    
    ll a, b; cin >> a >> b >> modulo;
    
    cout << mul(a, b);
    
    return 0;
}