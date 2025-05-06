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

vi vec(500001);
int find(int x){
    return (vec[x] == x) ? x : (vec[x] = find(vec[x]));
}
int main(){
    FASTIO

    int n, m; cin >> n >> m;
    
    for(int i = 0 ; i <=n; i++)
        vec[i] = i;
    
    for(int i = 1 ; i <= m; i++){
        int a,b;cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a==b) {
            cout << i;
            return 0;
        }
        else vec[a] = b;
    }
    cout << 0;
}