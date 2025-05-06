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

ll n, res_min=1e23, res_max=-1e23;
vll vec, op(4);
void dfs(ll cnt, ll ret){
    if(cnt == n){
        res_max = max(res_max, ret);
        res_min = min(res_min, ret);
        return;
    }
    for(int i = 0 ; i < 4; i++){
        if(op[i]){
            op[i]--;
            if(i==0) dfs(cnt+1, ret + vec[cnt]);
            else if(i==1) dfs(cnt+1, ret - vec[cnt]);
            else if(i==2) dfs(cnt+1, ret * vec[cnt]);
            else if(i==3) dfs(cnt+1, ret / vec[cnt]);
            op[i]++;
        }
    }
}
int main(){
    FASTIO

    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    for(int i = 0; i < 4; i++) cin >> op[i];

    dfs(1,vec[0]);

    cout << res_max << '\n' << res_min;
}