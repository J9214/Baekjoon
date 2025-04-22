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

    vector<bool> vec(500001,0);
    vector<int> sosu;
    for(int i=2;i<=500000;i++) {
        if(vec[i]) continue;
        sosu.push_back(i);
        for(int j=2*i;j<=500000; j+=i) vec[j] = 1;    
    }
    // cout << sosu[9999];
    // print(sosu);
    // cout << sosu.size();
    int t; cin >> t;
    while(t--){
        int m; cin >> m;
        vvi mat(3, vi(m,0));
        for(int i = 0 ; i < m ; i++) cin >> mat[0][i]; // n_i, index, value

        for(int l=m-1; i>=0; i--))
    }
}