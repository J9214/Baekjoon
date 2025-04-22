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
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

ll digit(ll n){
    ll res=0;
    while(n){
        n/=10;
        res++;
    }
    return res;
}
ll zero(ll n){
    string s;
    for(int i = n-1; i >= 1; i--)
        s.append(to_string(i));
    return stoll(s) * 9;
}
int main(){
    FASTIO

    ll n; cin >> n;

    vi vec(10,0);
    for(ll i = 1; i <= n; i++){
        ll t = i;
        while(t){
            vec[t % 10]++;
            t /= 10;
        }
    }
    cout << zero(4) << '\n';
    print(vec);
}