#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<vector<int>> vvi;
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
int main(){
    FASTIO

    int n, m; cin >> n >> m;
    // n : edge // m : vertices

    vector<int> vec(m,1);
    vector<vector<int>> edge(m);
    for(int  i = 0 ; i < n ; i++){
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
    }

    int res = 1;

    for(int i = 0 ;i < edge.size(); i++){
        if(vec[i] != 1) continue;
        queue<pair<int, int>> next;
        vector<bool> visited(m,0);
        visited[i] = 1;
        
        if(vec[i] == 1){
            for(int j = 0 ; j < edge[i].size(); j++)
                next.push({i, edge[i][j]});
        }

        while(!next.empty()){
            int cp = next.front().first;
            int np = next.front().second;
            
            next.pop();
            if(vec[np] < vec[cp] + 1){
                vec[np] = vec[cp] + 1;
                res = max(res,vec[np]);
                for(int k = 0 ; k < edge[np].size(); k++)
                    if(!visited[edge[np][k]] && edge[np][k] != i) {
                        next.push({np,edge[np][k]});
                        visited[np] = 1;
                    }
            }
        }
    }

    cout << res;
}