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
typedef vector<vector<pair<int, int>>> vvpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

vi vec(101);
vvpi road(101);
vector<bool> visited(101,0);

int func(int curr, int cost){
    int total = vec[curr];
    visited[curr] = 1;

    for(int i = 0 ; i < road[curr].size(); i++){
        if(!visited[road[curr][i].first] && road[curr][i].second <= cost) {
            //visited[road[curr][i].first] = 1;
            int t = func(road[curr][i].first, cost - road[curr][i].second);
            total += t;
            //visited[road[curr][i].first] = 0;
        }
    }

    visited[curr] = 0;
    return total;
}

int main(){
    FASTIO

    int n,m,r;cin >> n >> m >> r;
    
    for(int i = 1; i <=n  ;  i ++)
        cin >> vec[i];
    for(int i = 0; i <r  ;  i ++){
        int a,b,c;cin >> a >> b >> c;
        road[a].push_back({b,c});
        road[b].push_back({a,c});
    }

    int m_=0;
    for(int i = 1 ; i <= n ; i++){
        int tmp = func(i,m);
        m_ = max(tmp,m_);
    }

    cout << m_;
}