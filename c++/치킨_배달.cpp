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

int n, m;
int res=INT_MAX;
vpi choose;
vpi house;
vpi chicken;
void distance(){
    int ret=0;
    for(auto i : house){
        int t=INT_MAX;
        for(auto j : choose){
            t = min(t,abs(i.X-j.X) + abs(i.Y-j.Y));
        }
        ret+=t; 
    }
    res = min(ret,res);
}
void func(vpi &chicken, int idx, int c){
    if(c==m) {distance(); return;}
    for(int i = idx; i < chicken.size(); i++){
        choose[c] = chicken[i];
        func(chicken, i+1, c+1);
    }
}
int main(){
    FASTIO

    cin >> n >> m;
    vvi vec(n,vi(n));
    choose.resize(m);

    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n; j++) {
        int d; cin >>d;
        if(d==1) house.push_back({i,j});
        if(d==2) chicken.push_back({i,j});
    }

    func(chicken,0,0);

    cout << res;
}