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
point direction[8] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vvi mat(n,vi(n,0));

        int a,b,c,d; cin >> a >> b >> c >> d;
        
        queue<pi> q;
        q.push({a,b});
        mat[a][b] = 1;
        while(q.size()){
            auto [x,y] = q.front(); q.pop();
            if(x==c && y==d){
                cout << mat[x][y]-1 << '\n';
                
                break;
            }
            for(auto dir : direction){
                int nx = x + dir.x;
                int ny = y + dir.y;

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(mat[nx][ny]) continue;
                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
}