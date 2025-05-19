#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

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