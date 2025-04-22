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
    vpi vec(n+1);
    vi res(n+1,0);
    for(int i = n; i > 0; i--){
        int a,b;cin >> a >> b;
        vec[i] = {a,b};
    }

    int m_=0;

    for(int i = 1 ; i <= n ; i++){
        if(vec[i].first <= i) res[i] = max(res[i-1],res[i-vec[i].first]+vec[i].second);
        else res[i] = res[i-1];
    }

    cout << res[n];
    
}