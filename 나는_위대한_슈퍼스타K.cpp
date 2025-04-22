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
    int n,m,k; cin >> n >> m >> k;
    vector<double> vec(n+1,0);

    for(int i=0; i < m; i++){
        for(int j= 0 ; j < n; j++){
            double a,b;cin >> a >> b;
            vec[a] = max(vec[a],b);
        }
    }
    sort(vec.rbegin(),vec.rend());
    double res=0;
    for(int i = 0 ; i < k; i++)
        res+=vec[i];
    cout << fixed;
    cout.precision(1);
    res*=10;
    round(res);
    cout << res/10;
}