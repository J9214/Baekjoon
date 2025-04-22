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

    int n,m ; cin >> n >> m;
    vvi mat(n, vi(m));   
    for(int i = 0 ; i < n ; i++){
        string s; cin >> s;
        for(int j = 0 ; j < m ; j++){
            mat[i][j] = s[j]-'0';
        }
    }
    
    queue<pi> q;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j] == 1){
                mat[i][j] = 0;
                q.push({0,0});
                while(q.empty()){
                    int cx = q.front().X;  
                    int cy = q.front().Y;
                    q.pop();

                    for(auto k : direction){
                        int nx = q.front().X;
                        int ny = q.front().Y;

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(mat[nx][ny]==0) q.push({nx,ny});
                    }
                    

                }
            }
        }
    }
    
}