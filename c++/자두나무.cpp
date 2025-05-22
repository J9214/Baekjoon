#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vi> vvi;
void print(vi vec){for(auto i : vec) cout << i << ' ';}
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}

int main(){
    FASTIO

    int t,w;cin >> t >> w;
    vi plums;
    int prev, a, c=1; cin >> prev;
    if(prev==2) plums.push_back(0);
    
    for(int i = 0 ; i < t-1 ; i++){
        cin >> a;
        if(prev != a){
            plums.push_back(c);
            c = 1;
        }
        else c++;
        prev = a;
    }
    plums.push_back(c);

    int n = plums.size(), res = plums[0];
    
    vvi dp(w+1,vi(n,0));
    dp[0][0] = plums[0];

    for(int i = 0 ; i <= w ; i++){
        for(int j = i ; j < n; j++){
            int a = 0, b = 0;
            if(j > 1) a = dp[i][j-2];
            if(i) b = dp[i-1][j-1];
            else if(j%2) continue;
            dp[i][j] = max(a,b) + plums[j];
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
}