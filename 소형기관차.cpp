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
    vi vec(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> vec[i];
    int c; cin >> c;
    vi s_vec; 
    int s=0;
    for(int i = 0 ; i < n ; i ++){
        s += vec[i];
        if(i>=c-1) {
            s_vec.push_back(s);
            s-=vec[i-c+1];
        }
    }
    vvi dp(3,vi(s_vec.size(),0));
    for(int i = 0;  i < 3; i ++){
        for(int j = 0 ; j < dp[0].size(); j++){
            if(!i) {
                if(j) dp[i][j] = max(dp[i][j-1], s_vec[j]);
                else dp[i][j] = s_vec[j];
            }
            if(i && j >= c*i) dp[i][j] = max(dp[i-1][j-c] + s_vec[j], dp[i][j-1]);
        }
    }
    cout << dp[dp.size()-1][dp[0].size()-1];
}