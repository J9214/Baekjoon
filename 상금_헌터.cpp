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

    vi v1 = {0,1,3,6,10,15,21,100}, v2={0,1,3,7,15,31,64};
    vi vec1= {0,500, 300, 200, 50, 30, 10,0};
    vi vec2= {0,512,256,128,64,32,0};

    int n; cin >> n;
    while(n--){
        int a,b;cin >> a >> b;
        cout << 10000 * (vec1[lower_bound(v1.begin(),v1.end(),a)-v1.begin()] + vec2[lower_bound(v2.begin(),v2.end(),b)-v2.begin()]) << '\n';
    }
}