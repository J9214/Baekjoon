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

vvi vec(51, vi(51));
bool e=0;
vector<bool> visited(51,0);
void dfs(int depth, int c, int f){
    if(e) return;
    visited[c] =1;

    for(int i = 0 ; i < vec[c].size(); i++){
        if(e) return;
        if(vec[c][i]==f) {
            cout << depth;
            e=1;
            return;
        }
        if(!visited[vec[c][i]])
            dfs(depth+1, vec[c][i], f);
    }
    visited[c]=0;
}   

int main(){
    FASTIO

    int n,a,b,t;cin >> n >> a >> b >> t;
    while(t--){
        int c,d; cin >> c >> d;
        vec[c].push_back(d);
        vec[d].push_back(c);
    }

    dfs(1,a, b);
    if(!e) cout << -1;

}