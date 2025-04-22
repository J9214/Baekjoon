#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int s=0;
int res = 0;
void bfs(vvi mat, queue<point> q){
    int t=q.size();
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();

        for(int i = 0 ; i < 4; i++){
            int dx = cx + direction[i].x;
            int dy = cy + direction[i].y;

            if(dx < 0 || dy < 0 || dx >= mat.size() || dy >= mat[0].size() || mat[dx][dy] >= 1) continue;

            t++;
            mat[dx][dy] = 2;
            q.push({dx,dy});
        }
    }
    res = max(int(mat.size()*mat[0].size() - t - 3 - s), res);
}
void barrier(vvi &mat, int cnt, queue<point> &q, int x, int y){
    //if(y==mat[0].size()) x++;
    
    if(cnt==3) {
        bfs(mat, q);
        return;
    }
    for(int i = x ; i < mat.size() ; i++){
        for(int j = y ; j < mat[0].size();  j++){
            if(!mat[i][j]) {
                mat[i][j]=1;
                barrier(mat, cnt+1, q, i, j+1);
                mat[i][j]=0;
            }
        }
        y=0;
    }
}
int main(){
    FASTIO

    int n,m;cin >> n>>m;
    vvi mat(n,vi(m));
    queue<point> q;
    for(int i = 0 ;  i < n; i ++)
        for(int j = 0 ; j< m ; j++){
            cin >> mat[i][j];
            if(mat[i][j]==1)s++;
            if(mat[i][j]==2) q.push({i,j});
        }

    barrier(mat, 0, q, 0, 0);

    cout << res;
    
}