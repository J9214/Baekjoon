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
#define modulo 1000000000

int main(){
    FASTIO

    vvi vec(201,vi(201,0));
    for(int i = 0 ; i < 201; i++){
        for(int j =0 ; j < 201; j++){
            if(i<=1) vec[i][j]=j;
            else if(j<=1) vec[i][j]=1;
            else vec[i][j] = (vec[i-1][j]+vec[i][j-1])%modulo;
        }
    }
    int a,b;cin >> a >> b;
    cout <<vec[a][b];
}