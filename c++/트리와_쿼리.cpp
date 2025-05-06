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

vvi connect;
vvi tree;
vi treesize;
void makeTree(int curr, int parent){
    for(auto node : connect[curr]){
        if (node != parent){
            tree[curr].push_back(node);
            makeTree(node, curr);
        }
    }
}

void countsubtreeNodes(int curr){
    treesize[curr]=1;
    for(auto node : tree[curr]){
        countsubtreeNodes(node);
        treesize[curr] += treesize[node];
    }
}

int main(){
    FASTIO

    int n, r, q; cin >> n >> r >> q;
    connect.resize(n+1);
    tree.resize(n+1);
    treesize.resize(n+1, 0);

    for(int i = 0 ; i < n-1; i++){
        int a,b; cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    makeTree(r, -1);
    countsubtreeNodes(r);
    while(q--){
        int a; cin >> a;
        cout << treesize[a] << '\n';
    }
}