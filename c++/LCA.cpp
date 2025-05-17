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

int parent[50001];
int depth[50001];
vvi tree(50001);
void make_tree(int p, int c){
    // int p, c; cin >> p >> c;
    // if(depth[p] == 0) swap(p,c);
    parent[c] = p;
    depth[c] = depth[p]+1;
    for(auto i : tree[c]){
        if(i != p) make_tree(c,i);
    }
}
int main(){
    FASTIO

    int n; cin >> n;
    n--;
    depth[1] = 1;
    for(int i = 0 ; i < n ; i++){
        int a,b;cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // while(n--){
    //     int p, c; cin >> p >> c;
    //     if(depth[p] == 0) swap(p,c);
    //     parent[c] = p;
    //     depth[c] = depth[p]+1;
    // }
    make_tree(0,1);
    int m; cin >> m;
    while(m--){
        int a,b; cin >> a >> b;
        if(depth[a] > depth[b]) swap(a,b);
        while(depth[a]!=depth[b])  b = parent[b];
        while(a != b)a = parent[a], b = parent[b];  
        
        cout << a << '\n';
    }
}   