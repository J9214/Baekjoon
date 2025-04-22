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
typedef struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
void print(vector<point> vec){for(auto i : vec) cout << i.x << ' ' << i.y << '\n';}
#define modulo 1000000007
vector<point> vec;
int n, m;
void bfs(vvi &mat, int x, int y){
    queue<point> q;
    q.push({x,y});
    mat[x][y] = 1;
    priority_queue<pair<int, point>> pq;
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        pq.push({mat[cx][cy], {cx,cy}});
        q.pop();
        for(int i = 0 ;  i < 4; i++){
            int dx = direction[i].x + cx;
            int dy = direction[i].y + cy;
            if(dx<0 || dy < 0 || dx >= n || dy >= m || mat[dx][dy] == -1) continue;
            if(mat[dx][dy] == 0) {
                mat[dx][dy] = mat[cx][cy] + 1;
                q.push({dx,dy});
            }
        }
    }
    int m_ = pq.top().first;
    while(!pq.empty()){
        if(pq.top().first == m_) vec.push_back(pq.top().second);
        else break;
        pq.pop();
    }
}
int find(vvi mat, vvi len, int x, int y){
    queue<point> q;
    q.push({x,y});
    int ret = 0;
    mat[x][y] =-1;
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();
        for(int i = 0 ;  i < 4; i++){
            int dx = direction[i].x + cx;
            int dy = direction[i].y + cy;
            if(dx<0 || dy < 0 || dx >= n || dy >= m || mat[dx][dy] == -1) continue;
            len[dx][dy] = len[cx][cy] + 1;
            ret = max(ret,len[dx][dy]);
            mat[dx][dy] = -1;
            q.push({dx,dy});
        }
    }
    return ret;
}
int main(){
    FASTIO
    cin >> n >> m;
    vvi mat(n,vi(m));
    vvi len(n,vi(m,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c=='W') mat[i][j] = -1;
            else mat[i][j] = 0;
        }
    }
    vvi mmat = mat;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j]==0) bfs(mat,i,j);
        }
    }
    int res = 0;
    for(int i = 0 ; i< vec.size(); i++){
        int t = find(mmat, len, vec[i].x,vec[i].y);
        res = max(res, t);
    }
    cout << res;
}