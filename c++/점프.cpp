#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef struct Point {int x, y;} point;
point direction[2] = {{1,0},{0,1}};

int main(){
    FASTIO

    int n; cin >> n;
    vvll mat(n+1, vll(n+1,0));
    vvll dp(n+1, vll(n+1,0));
    dp[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == n && j == n) break;
            cin >> mat[i][j];
            for(int k = 0; k < 2; k++){
                int ni = i + direction[k].x * mat[i][j];
                int nj = j + direction[k].y * mat[i][j];
                if(ni > n || nj > n) continue;
                dp[ni][nj] += dp[i][j];
            }
        }
    }
    
    cout << dp[n][n];
}