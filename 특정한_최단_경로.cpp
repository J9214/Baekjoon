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
#define INF INT_MAX
int n, m; 
vvpi edge;
vi Dijkstra(int start) {
    vi dist(n + 1, INF);
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
            if(dist[next] == INF || dist[next] > nextDist){
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    return dist;
}

int main(){
    FASTIO

    cin >> n >> m;
    edge.resize(n + 1);

    int a, b, c;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    
    int s1, s2; cin >> s1 >> s2;
    vi dist1 = Dijkstra(1);
    vi dist2 = Dijkstra(s1);
    vi dist3 = Dijkstra(s2);
    // s, s1, s2, d
    // 1. s, s1, s2, d
    // 1. s, s2, s1, d
    // 1. s, s1, s2, s1, d
    // 1. s, s2, s1, s2, d
    // 1. s, s1, s, s2, s1, d
    // 1. s, s2, s, s1, s2, d
    
    if(dist1[s1] == INF || dist2[s2] == INF || dist3[n] == INF) cout << -1;
    else {
        int a,b,c,d,e,f;
        a = dist1[s1] + dist2[s2] + dist3[n];
        b = dist1[s2] + dist2[n] + dist3[s1];
        c = dist1[s1] + dist2[s2] + dist3[s1] + dist2[n];
        d = dist1[s2] + dist2[s2] + dist3[s1] + dist3[n];
        e = dist1[s1] + dist1[s2] + dist2[1] + dist3[s1] + dist2[n];
        f = dist1[s1] + dist1[s1] + dist2[s2] + dist3[1] + dist3[n];
        cout << min(a,min(b,min(c,min(d,min(e,f)))));
    }
    
}