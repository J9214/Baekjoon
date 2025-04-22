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
    
    int n,m ; cin >> n >> m;
    vvi vec(n + 1, vi(n + 1,10000000));
    
    for(int i = 0; i <= n; i++)
        vec[i][i] = 0;
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        vec[a][b] = min(vec[a][b],c);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            for(int k = 1; k <= n; k++){
                vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            if(vec[i][j] >= 10000000) cout << 0 << ' ';
            else cout << vec[i][j] << ' ';
        }
        cout << '\n';
    }
}