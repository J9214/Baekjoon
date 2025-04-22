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

bool f=0;
void func(vvi &vec, vi &visited, int n, int d){
    if(f || d==4) {   
        f=1;
        return;
    }
    for(int i = 0; i < vec[n].size(); i++){
        if(visited[vec[n][i]]) continue;
        visited[vec[n][i]]=1;
        func(vec, visited, vec[n][i], d+1);    
        visited[vec[n][i]]=0;
    }
}

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    vvi vec(n);
    vi visited(n, 0);
    while(m--){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    visited[0]=1;
    for(int i = 0 ; i < n ; i++){
        if(f) break;
        visited[i]=1;
        func(vec, visited, i, 0);
        visited[i]=0;
    }

    if(f) cout << 1;
    else cout << 0;
}   