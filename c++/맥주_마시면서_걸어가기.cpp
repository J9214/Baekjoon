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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vvi vec(n+2,vi(2));

        for(int i = 0 ; i < n+2 ; i++)
            cin >> vec[i][0] >> vec[i][1];
        int s = vec[0][0], e = vec[0][1];
        int x = vec[n+1][0], y = vec[n+1][1];

        sort(vec.begin(),vec.end());

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 2; j++) {
                cout << vec[i][j] << ' ';
            }
            cout << abs(vec[i][0]-s) + abs(vec[i][0]-e);
            cout << '\n';
        }
        
    }
}