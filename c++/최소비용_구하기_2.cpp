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

int n, m; 
vi res;
vvpi edge;
vi Dijkstra(int start) {
    vi dist(n + 1, -1);
    priority_queue<pi, vpi, greater<pi>> pq;
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if(currDist > dist[curr]) continue;
        for(int i = 0; i < edge[curr].size(); i++){
            int next = edge[curr][i].first;
            int nextDist = currDist + edge[curr][i].second;
            if(dist[next] == -1 || dist[next] > nextDist){
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    return dist;
}

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    edge.resize(n + 1);

    for(int i = 0 ; i < m ; i++){
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }
    
    int s, e; cin >> s >> e;

    vi dist = Dijkstra(s);
    
    cout << dist[e];
}