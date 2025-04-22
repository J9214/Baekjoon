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

    int n ; cin >> n;
    if(n==1){
        cout << -1;
        return 0;
    }
    vi vec(n+1,0);
    vi coin = {2,5};
    vec[1] = 987654321;
    for(int i = 2 ; i <= n; i++){
        if(i>=5) vec[i] = min(vec[i-2], vec[i-5]) + 1;
        else vec[i] = vec[i-2] + 1;
    }
    if(!vec[n] || vec[n]>=987654321) cout << -1;
    else cout << vec[n];
}