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
    if((n-1)%8 == 0) cout << 1;
    if((n-1)%8 == 1 || (n-1)%8 == 7) cout << 2;
    if((n-1)%8 == 2 || (n-1)%8 == 6) cout << 3;
    if((n-1)%8 == 3 || (n-1)%8 == 5) cout << 4;
    if((n-1)%8 == 4) cout << 5;
}