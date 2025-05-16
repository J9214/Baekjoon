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

vector<vector<pi>> tree;
int res=0;
void insert(){
    int n; cin >> n;
    tree.resize(n+1);
    int a,b,c;
    while(cin >> a >> b >> c){
        tree[a].push_back({b,c});
    }
}
int dfs(int node, int weight){
    int l=0, r=0;
    for(auto i : tree[node]){
        int a = dfs(i.first, i.second);
        if(a > l){
            r = l;
            l = a;
        }
        else if(a > r) r = a;
    }
    res = max(res, l+r);
    return max(l,r)+weight;

}
int main(){
    FASTIO
    insert();
    dfs(1,0);
    cout << res;
}