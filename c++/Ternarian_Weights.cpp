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
void print(vll vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    vll vec; vec.push_back(0);
    for(ll n=1; n < INT_MAX; n*=3)
        vec.push_back(n);
    vec.push_back(vec.back()*3);
    
    ll t; cin >> t;
    vll lv, rv;
    while(t--){
        ll n; cin >> n;
        lv.clear();
        rv.clear();
        ll l=n,r=0;

        while(l!=r){
            ll t = abs(l-r);
            auto it = lower_bound(vec.begin(),vec.end(),t);
            if(l-r < 0) {                
                ll num = (abs(t - *it) <= abs(t - *(it-1)) ? *it : *(it-1));
                lv.push_back(num);
                l += num;
            }
            else {
                ll num = (abs(t - *it) <= abs(t - *(it-1)) ? *it : *(it-1));
                rv.push_back(num);
                r += num;
            }
        }

        cout << "left pan: "; print(lv);
        cout << '\n';
        cout << "right pan: "; print(rv);
        cout << '\n' << '\n';
    }
}