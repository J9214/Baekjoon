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

    int n,m,k;cin >> n >> m >> k;
    vi v1,v2;
    v1.push_back(n);
    v1.push_back(0);
    v2.push_back(m);
    v2.push_back(0);
    while(k--){
        int a,b; cin >> a >> b;
        if(a) v1.push_back(b);
        else v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int w=0,h=0;
    for(int i = 1 ; i<v1.size();i++)
        w=max(w,v1[i]-v1[i-1]);
    for(int i = 1 ; i<v2.size();i++)
        h=max(h,v2[i]-v2[i-1]);
    cout << w*h;
}