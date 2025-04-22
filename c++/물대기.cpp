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
typedef vector<vector<pi>> vvpi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define modulo 1000000007

int main(){
    FASTIO

    int n; cin >> n;
    vector<bool> visit(n + 1);
    vvpi graph(n + 1);
    priority_queue<pi, vpi, greater<pi>> pq;
    vi non(n + 1);

    for(int i = 1; i <= n ; i++){
        int c; cin >> c;
        pq.
    }
    
        
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int c; cin >> c;
            if(c) graph[i].push_back({c,j});
        }
    }

   int s = 0, res = 0;
    for(int i = 0 ; i < n ; i++){
        visit[s] = 1;
        for(pi x : graph[s]) pq.push(x);
        while(visit[pq.top().second]) pq.pop();
        res += pq.top().first;
        s = pq.top().second;
        pq.pop();
    }   
    cout << res;
}