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
point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    int n, m, k; cin >> n >> m >> k;
    vvi vec(n, vi(m,0));
    while(k--){
        int a,b,c,d; cin >> a>>b>>c>>d;
        for(int i=b; i < d; i++)
            for(int j = a; j < c; j++)
                vec[i][j]=1;
    }

    vi res;

    for(int i = 0 ; i< n; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vec[i][j]){
                queue<pi> q;
                int c=0;
                q.push({i,j});
                vec[i][j] = 1;
                while(!q.empty()){
                    int cx = q.front().first;
                    int cy = q.front().second;
                    c++;
                    q.pop();

                    for(int k = 0 ; k < 4; k++){
                        int nx = cx + dir[k].x;
                        int ny = cy + dir[k].y;
                        if(nx >=0 && nx < n && ny >= 0 && ny < m&&
                            !vec[nx][ny]){
                            q.push({nx,ny});
                            vec[nx][ny]=1;
                        }
                    }
                }
                res.push_back(c);
            }
        }
    } 
    sort(res.begin(),res.end());
    cout << res.size() << '\n'; 
    print(res);
}