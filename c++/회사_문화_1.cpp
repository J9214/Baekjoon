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

vvi under(100001);
vi praise(100001,0);
vi visited(100001,0);

void dfs(int node){
    if(visited[node]) return;
    visited[node]=1;
    for(auto idx : under[node]){        
        praise[idx] += praise[node];
        dfs(idx);
    }
}
int main(){
    FASTIO

    
    int n,q; cin >> n >> q;

    for(int i = 1 ; i <= n; i++) {
        int under_num; cin >> under_num;
        if(under_num>0) under[under_num].push_back(i);
    }
    for(int i = 1 ; i <= q; i++){
        int my_num, praise_amount; cin >> my_num >> praise_amount;
        praise[my_num]+=praise_amount;
    }
    dfs(1);
    for(int i = 1 ; i <= n; i++) cout << praise[i] << ' ' ;
}