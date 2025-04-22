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

    int n,m;cin>>n>>m;
    vvi vec(n, vi(n,0));
    int dir=0,x=0,y=0;
    int num=n*n;
    int resx,resy;
    while(1){
        vec[x][y] = num--;
        if(vec[x][y] == m) {
            resx=x+1;
            resy=y+1;
        }
        if(x+direction[dir].x >= n || x+direction[dir].x < 0 || y+direction[dir].y >= n || y+direction[dir].y < 0 || vec[x+direction[dir].x][y+direction[dir].y]) 
            dir = (dir+1)%4;
        if(vec[x+direction[dir].x][y+direction[dir].y]) break;
        x = x + direction[dir].x;
        y = y + direction[dir].y;            
    }
    print(vec);
    cout << resx << ' ' << resy;
}