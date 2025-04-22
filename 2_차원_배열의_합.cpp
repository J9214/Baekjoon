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
#define modulo 1000000007

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    vvi vec(n + 1, vi(m + 1,0));
    for(int i =1 ; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            cin >> vec[i][j];
            vec[i][j] += vec[i][j-1] + vec[i-1][j] - vec[i-1][j-1];
        }
    }
    
    int q; cin >> q;
    while(q--){
        int a, b, c, d; cin >> a >> b >> c>> d;
        cout << vec[c][d] - vec[a-1][d] - vec[c][b-1] + vec[a-1][b-1] << '\n';
    }
}