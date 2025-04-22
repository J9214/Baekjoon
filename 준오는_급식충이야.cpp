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

    double n, m; cin >> n >> m;
    vi vec1(n), vec2(n);
    for(int i = 0 ; i < n ; i++) cin >> vec1[i];
    for(int i = 0 ; i < n ; i++) cin >> vec2[i];
            
    double l=0,r=1e9;

    for(int i = 0 ; i< n; i ++){
        l = max(l,double(vec1[i] - double(vec2[i] * m)));
        r = min(r,double(vec1[i] + double(vec2[i] * m)));
    }
    cout << (l<=r+1e-8 ? 1:0);
}