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
point direction[4] = {{-1,0},{0,1},{1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int res = 0;
void op1(vvi &m, int x, int y){
    if(!m[x][y]) {
        m[x][y] = 2;
        res++;
    }
}
bool op2(vvi &m, int x, int y, int d){
    int dx = x-direction[d].x;
    int dy = y-direction[d].y;
    
    return (dx>=0 && dy >=0 && dx<m.size()&&dy<m[0].size()&&m[dx][dy]!=1);
}
bool op3(vvi &m, int &x, int &y, int d){
    int dx = x+direction[d].x;
    int dy = y+direction[d].y;

    return (dx >= 0 && dy >= 0 && dx < m.size() && dy < m[0].size() && m[dx][dy] == 0);
}
int main(){
    FASTIO

    int n,m;cin >> n >> m;
    vvi vec(n,vi(m));
    int x,y,d; cin >> x>>y>>d;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j <m ; j++)
            cin >> vec[i][j];

    while(1){
        op1(vec,x,y);
        bool f=0;
        for(int i = 0 ; i < 4 ; i++){
            d=(d+3)%4;
            if(op3(vec,x,y,d)){
                x += direction[d].x;
                y += direction[d].y;
                f=1;
                break;
            }
        }
        if(!f)
            if(op2(vec,x,y,d)) {
                x -= direction[d].x;
                y -= direction[d].y;   
            }
            else {
                cout <<res;
                return 0;
            }
    }
}