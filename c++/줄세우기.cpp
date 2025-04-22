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

    int t;cin >> t;
    while(t--){
        int n; cin >> n; cout << n << ' ';
        vi vec;
        int res=0;
        for(int i = 0 ; i < 20 ; i++){
            int d; cin >> d;
            auto it = lower_bound(vec.begin(),vec.end(),d);
            if(it != vec.end()) res += vec.size() - (it - vec.begin());
            vec.push_back(d);
            sort(vec.begin(),vec.end());
        }
        cout << res << '\n';
    }
}