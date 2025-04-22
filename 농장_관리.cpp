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
point direction[8] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

bool chk(vvi &vec, int nx, int ny){
    if(nx>=0&&ny>=0&&nx<vec.size()&&ny<vec[0].size()) return 1;
    return 0;
}
int main(){
    FASTIO

    int n,m; cin >> n >> m;
    vvi vec(n,vi(m)), visit(n,vi(m));
    priority_queue<tuple<int,int,int>> pq;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m; j++){
            int d; cin >> d;
            if(d>0) pq.push(make_tuple(d,i,j));
            vec[i][j] = visit[i][j] = d;
        }
    }

    queue<pi> q;
    int res = 0;

    while(!pq.empty()){
        int pqcx = get<1>(pq.top());
        int pqcy = get<2>(pq.top());
        pq.pop();    
        if(visit[pqcx][pqcy] == 0) continue;
        visit[pqcx][pqcy] = 0;

        q.push({pqcx,pqcy});

        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            visit[cx][cy]=0;
            
            for(auto k:direction){
                int nx = cx+k.x;
                int ny = cy+k.y;
                if(chk(vec,nx,ny)){
                    if(visit[nx][ny] != 0 && vec[nx][ny] <= vec[cx][cy]){
                        visit[nx][ny]=0;
                        q.push({nx,ny});
                    }
                }
            }
        }
        res++;
    }
    cout << res;
}