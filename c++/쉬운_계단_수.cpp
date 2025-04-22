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
#define modulo 1000000000

int main(){
    FASTIO

    vvll vec(100,vll(10, 0));
    int n; cin >> n;
    
    for(int i = 1; i < 10 ; i++)
        vec[0][i] = 1;
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < 10; j++){
            if(!j) vec[i][j] = vec[i-1][j+1];
            else if(j == 9) vec[i][j] = vec[i-1][j-1];
            else vec[i][j] = (vec[i-1][j-1] + vec[i-1][j+1])%modulo;
        }
    }

    ll res = 0;
    for(int j = 0 ; j < 10; j++)
        res += vec[n-1][j];
    cout << res%modulo;
}   