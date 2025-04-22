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
        vvi vec(2, vi(n));

        for(int i = 0; i < 2; i++)
            for(int j = 0;  j< n; j++)
                cin >> vec[i][j];      

        for(int i = 1; i < n; i++){
            for(int j = 0;  j< 2; j++){
                int d;
                if(i == 1) d = vec[(j+1)%2][i-1];
                else d = max(vec[(j+1)%2][i-1], vec[(j+1)%2][i-2]);

                vec[j][i] += d;
            }
        }
        cout << max(vec[0][n-1], vec[1][n-1]) << '\n';
    }
}