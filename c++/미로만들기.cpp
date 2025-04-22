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

    int n ;cin >> n;
    vvi vec(n, vi(n, 0));

    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j < n ; j++){
            char c; cin >> c;
            vec[i][j] =c-'0';
        }
    }

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push({1,0,0});
    vvi visited(n, vi(n, 0));
    
    while(!pq.empty()){
        auto [c, x, y] = pq.top(); pq.pop();
        visited[x][y] = c;

        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y; 
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            visited[nx][ny] = (vec[nx][ny] ? c : c + 1);
            pq.push({visited[nx][ny], nx, ny});   
        }
    }
    cout << visited[n-1][n-1]-1;
}