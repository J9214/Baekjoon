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

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    vvi mat(n, vi(n,0));
    int t=1;
    priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>>> pq; // time,num,x,y
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) {
        int d; cin >> d;
        mat[i][j] = d;
        if(d) pq.push({t,d,i,j});
    }
    int s,x,y; cin >> s >> x >> y;
    x--;y--;

    while(!pq.empty() || get<0>(pq.top()) > s){
        auto [t,d,i,j] = pq.top();
        pq.pop();
        if(t > s) break;
        if(mat[i][j] != d) continue;
        for(auto dir : direction){
            int nx = i+dir.x;
            int ny = j+dir.y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(mat[nx][ny]!=0)continue;
            mat[nx][ny] = d;
            pq.push({t+1,d,nx,ny});
        }
    }

    cout << mat[x][y] << '\n';
}