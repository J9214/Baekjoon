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
#define modulo 1000000007

vvi dp(3, vi(1001,0));
vvi vec(3, vi(1001));

int find(int rgb, int n){
    if(dp[rgb][n] != 0) return dp[rgb][n];
    if(!n) {
        dp[rgb][n] = vec[rgb][n];
        return vec[rgb][n];
    }

    int minret = INT_MAX;
    int ret = INT_MAX;
    for(int i = 0 ; i< 3; i++){
        if(i == rgb) continue;
        ret = vec[rgb][n] + find(i, n - 1);
        minret = min(ret, minret);
    }

    dp[rgb][n] = minret;
    
    return minret;
}
int main(){
    FASTIO

    int n; cin >> n;

    vvi vec(3, vi(n));

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < 3; j++)
            cin >> vec[j][i];
    
    find(0, n - 1);
    find(1, n - 1);
    find(2, n - 1);
    
    cout << min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1]));
}