#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> pi;

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