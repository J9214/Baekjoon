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

    int n,m; cin >> n>>m;
    vvi vec(100,vi(100));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> vec[i][j];

    int res = 0;
    for(int i = 0 ; i < 100; i++){
        int x1_p =0, x1_c=0, x2_p=0, x2_c=0;
        int y1_p =0, y1_c=0, y2_p=0, y2_c=0;
        for(int j = 0 ; j < 100 ; j++){
            x1_c= vec[i][j];
            x2_c= vec[i][100-j-1];
            y1_c= vec[j][i];
            y2_c= vec[100-j-1][i]; 
            res += max(0, x1_c- x1_p) + max(0, x2_c- x2_p) + max(0, y1_c- y1_p) + max(0, y2_c- y2_p);;
            x1_p= vec[i][j];
            x2_p= vec[i][100-j-1];
            y1_p= vec[j][i];
            y2_p= vec[100-j-1][i];
        }
    }
    
    cout << res + n*m*2;
}