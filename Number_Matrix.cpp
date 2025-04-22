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
point direction[4] = {{1,0},{0,1},{0,-1},{-1,0}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int n,m;
bool visited[101][101];

bool func(vvi &mat, int a, int b, int c){
    queue<pi> q;

    for(int i = 0 ; i < mat[0].size() ; i++){
        int s = mat[0][i];
        if(s != a && s != b && s != c) continue;   
        
        q.push({0,i});
        visited[0][i] = 1;
    }
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        
        if(x==n-1) return 1;

        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if(mat[nx][ny] != a && mat[nx][ny] != b && mat[nx][ny] != c) continue;
            
            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return 0;
}

int main(){
    FASTIO

    cin >> m >> n;
    vvi mat(n, vi(m,0));

    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) cin >> mat[i][j];

    for(int i = 0 ; i < 1000;i++){
        int a = i/100, b = i/10%10, c = i%10;
        memset(visited, 0, sizeof(visited));
        if(func(mat,a,b,c)) {
            cout << a << ' ' << b << ' ' << c;
            return 0;
        }
    }
    cout << "-1 -1 -1";
}