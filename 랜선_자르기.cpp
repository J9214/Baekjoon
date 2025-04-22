#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    ll n, m; cin >> n >> m;
    vll vec(n);
    ll l=1, r =0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> vec[i];
        r = max(r, vec[i]);
    }
    
    
    ll mid;

    while(l<=r){
        mid = (l+r)/2;
        ll cnt = 0 ;

        for(auto i : vec) cnt += i / mid;
        if(cnt < m) r = mid-1;
        else l = mid+1;
    }

    cout << r;
}