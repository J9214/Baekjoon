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
#define modulo 1000000009

int main(){
    FASTIO

    int t; cin >> t;
    while(t--){ 
        ll n; cin >> n;
        ll res =1 ;
        
        if(n > 2){
            for(int i = 0; i < n/3; i++)
            res = (res * 3 + modulo) % modulo; 

            if(n%3 == 2) res + 1;
            else if(!(n%3)) res - 1;
        }
        
        cout << res << '\n';
    }
    // n-1하고 3으로 나눈 값만큼 3을 계속 곱하고,
}