#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void print(vi vec){for(auto i : vec) cout << i << ' ';}

void dfs(int pa, int node, int &child){
    if(cin >> child){
        if(child < node)
            dfs(node,child,child);
        if(child > node && child < pa) 
            dfs(pa,child,child);
    }
    cout << node << '\n';
}
int main(){
    FASTIO
    int n, m;
    cin >> n;
    dfs(1<<30,n, m);
}   