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

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i = 0 ; i < m; i++){
        int a,b,c;cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }

    int start = 1;
    int costs = 0, m_cost=0;
    vi visited(n+1,0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i = 0 ; i < n-1; i++){
        visited[start] = 1;
        for(auto [c, next] : graph[start])  pq.push({c, next});
        while(visited[pq.top().second]) pq.pop();
        auto [cost, node] = pq.top(); pq.pop();
        m_cost = max(m_cost,cost);
        costs += cost;
        start = node;
    }
    
    cout << costs - m_cost;
}