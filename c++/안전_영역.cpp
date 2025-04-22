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

    
    int n; cin >> n;
    
    vvi vec(n, vi(n));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n; j++){
            cin >> vec[i][j];
        }
    }

    //print(vec);
    int res = 0;
    
    for(int h = 0 ; h <= 100; h++){
        vector<bool> visited(n*n,0);
        //h=5;
        int t=0;
        queue<point> q;

        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j ++){
                if(visited[i*n + j] || vec[i][j] <= h) {
                    visited[i*n + j] = 1;
                    continue;
                }
                t++;
                visited[i*n+j] = 1;
                q.push({i,j});
                while(!q.empty()){
                    int cx = q.front().x;
                    int cy = q.front().y;
                    q.pop();
                    
                    for(int j = 0 ; j < 4; j ++){
                        int dx = cx+direction[j].x;
                        int dy = cy+direction[j].y;

                        if(dx<0 || dy<0 || dx>=n || dy>=n || visited[dx*n+dy]) continue;
                        else if(vec[dx][dy] > h) {
                            visited[dx*n+dy] = 1;
                            q.push({dx,dy});
                        }
                    }
                }
            }
        }
        res = max(t, res);
    }
    cout << res;
    
}