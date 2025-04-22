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
    #define MAX_ 1000000
    vi vec(100001,MAX_);
    int n, m; cin >> n >> m;

    queue<int> q;

    q.push(n);
    vec[n] = 0;

    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == m) break;

        int a = x - 1;
        if(a > -1  && (vec[a] == MAX_ || vec[a] < vec[x])) {q.push(a); vec[a] = min(vec[a], vec[x]+1);}
        int b = x + 1;
        if(b <= vec.size() && b <= m && (vec[b] == MAX_ || vec[b] < vec[x])) {q.push(b); vec[b] = min(vec[b],vec[x]+1);}
        int c = x * 2;
        if(c <= vec.size() && c <= m && (vec[c] == MAX_ || vec[c] < vec[x])) {q.push(c); vec[c] = min(vec[c],vec[x]+1);}
    }
    cout << vec[m];
}