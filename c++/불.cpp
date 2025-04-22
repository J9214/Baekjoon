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
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}cout << '\n';}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int n, m;
bool f=false; 
vvi mat(7,vi(7));
void bfs(queue<point> &q, int c, bool b){
    while(c--){
        print(mat);
        cout << '\n';
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();
        if(b && mat[cx][cy] == -1) continue;

        for(int i = 0 ; i < 4; i++){
            int dx = cx + direction[i].x;
            int dy = cy + direction[i].y;
            if(b){
                if(dx<0 || dy<0 || dx >= m|| dy >= n){
                    cout << mat[cx][cy];
                    f=1;
                    return;
                }
                if(mat[dx][dy] == -1 || mat[dx][dy] > 0) continue;
                if(mat[dx][dy] == 0) {
                    mat[dx][dy] = mat[cx][cy]+1;
                    q.push({dx,dy});
                }
            }
            else {
                if(dx<0 || dy<0 || dx >= m || dy >= n || mat[dx][dy] == -1) continue;
                
                mat[dx][dy] = -1;
                q.push({dx,dy});
            }
        }
    }
}

int main(){
    FASTIO
    
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        f=0;
        queue<point> h;
        queue<point> q;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                char c; cin >> c;
                if(c=='*') q.push({j,i});
                if(c=='@') {
                    mat[j][i] = 1;
                    h.push({j,i});
                }
                else if(c=='.') mat[j][i] = 0;
                else mat[j][i] = -1;
            }
        }
        
        while(!f && (!q.empty() || !h.empty())){
            bfs(h,h.size(),1);
            bfs(q,q.size(),0);
        }

        if(!f) cout << "IMPOSSIBLE";
        cout << '\n';
    }
}