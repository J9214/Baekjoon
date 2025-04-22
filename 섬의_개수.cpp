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
point direction[8] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    while(1){
        int n, m; cin >> n >> m;
        if(!n&&!m) break;
        vvi mat(m, vi(n));
        
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n; j++)
                cin >> mat[i][j];

        int res=0;
        queue<point> q;

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(!mat[i][j]) continue;
                res++;
                mat[i][j] = 0;
                q.push({i,j});
                while(!q.empty()){
                    int cx = q.front().x;
                    int cy = q.front().y;
                    q.pop();
                    
                    for(int j = 0 ; j < 8; j ++){
                        int dx = cx+direction[j].x;
                        int dy = cy+direction[j].y;

                        if(dx<0 || dy<0 || dx>=m || dy>=n) continue;
                        else if(mat[dx][dy]) {
                            mat[dx][dy] = 0;
                            q.push({dx,dy});
                        }
                    }
                }
            }
        }
        cout << res << '\n';
    }
}