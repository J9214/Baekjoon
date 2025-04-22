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

    ll n, m; cin >> n >> m;
    vll vec(1000001, 0);

    while(n--){
        ll a, b; cin >> a >> b;

        for(ll i = a; i < b; i++)
            vec[i]++;
    }

    ll s = vec[0];
    ll i = 0, j = 0;
    bool c = false;
    while(j < vec.size()){
        if(s == m) {
            c = true;
            break;
        }
        if(i != j && s > m) {
            s -= vec[i];
            i++;
        }
        else {
            j++;
            s += vec[j];
        }
    }

    if(c) cout << i << ' ' << j + 1;
    else cout << 0 << ' ' << 0;
}