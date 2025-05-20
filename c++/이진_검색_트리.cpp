#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void print(vi vec){for(auto i : vec) cout << i << ' ';}

void dfs(int pa, int node, int &child){
    if(cin >> child){
        if(child < node) // node보다 작으면 왼쪽 자식
            dfs(node,child,child);
        if(child > node && child < pa) // node보다 크고 parent보다 작으면 오른쪽 자식
            dfs(pa,child,child);
        // parent보다 크면 return;
    }
    cout << node << '\n';
}
int main(){
    FASTIO
    int n, m;
    cin >> n;
    dfs(1<<30,n, m);
}   