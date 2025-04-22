#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};
ll modulo = 1000000007;

int main(){
    FASTIO
    
    ll k, n, p; cin >> n >> k >> p;
    vvll pre(p + 1, vll(p+1));
    for(int i =0  ; i <=p ; i++){
        for(int j = 0 ; j<=i; j++){
            pre[i][j] = !i||!j ? 1 : (pre[i-1][j] + pre[i-1][j-1]) %p;
        }
    }
    ll res=1;
    while(n||k){
        res = (res*pre[n%p][k%p])%p;
        n/=p;
        k/=p;
    }
    cout << res;
    
    return 0;
}