#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int n;
vi vec(200001,0);
void insert(){
    while(cin >> n){
        int idx = 1;
        while(vec[idx] != 0){
            if (vec[idx] > n) idx <<= 1;
            else idx  = (idx << 1) + 1;
        }
        vec[idx] = n;
    }
}
void dfs(int node){
    if((node<<1)>100000) return;
    if(vec[(node<<1)]!=0) dfs((node<<1));
    if(vec[(node<<1) + 1]!=0) dfs((node<<1) + 1);
    cout << vec[node] << '\n';
}
int main(){
    FASTIO
    insert();
    dfs(1);
}