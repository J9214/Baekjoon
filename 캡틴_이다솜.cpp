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

    vvi vec(2, vi(121,0));
    for(int i = 0 ; i< 2; i++)
        for(int j = 1 ; j< 121 ; j++)
            if(!i) vec[i][j] = vec[i][j-1] + j;
            else vec[i][j] = vec[i-1][j] + vec[i][j-1];
    
    vi vec2(n+1,100000000);
    for(int i = 0 ; i < 121; i++){
        for(int j = vec[1][i] ; j <= n ; j++){
            if(j == vec[1][i]) vec2[j] = 1;
            else vec2[j] = min(vec2[j - vec[1][i]] + 1, vec2[j]);
        }
    }
    cout << vec2[n];;
}