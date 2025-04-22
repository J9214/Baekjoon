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

int main() {
    FASTIO;

    int n; cin >> n;
    vector<vector<vector<int>>> vec(n, vvi(n, vi(3,0)));
    vvi map(n,vi(n,0));
    // 0 : 가로, 1 : 대각, 2: 세로
    
    vec[0][1][0]=1;
    for(int i = 0 ; i< n ; i++){
        for(int j =0 ; j < n ; j++){
            int d; cin >> d;
            map[i][j] = d;
            if(!i&&j==1){
                vec[i][j][0]=1;
                continue;
            }
            if(d) continue;

            vec[i][j][0] += (j?vec[i][j-1][0]:0) + (j?vec[i][j-1][1]:0); // 가로
            vec[i][j][2] += (i?vec[i-1][j][1]:0) + (i?vec[i-1][j][2]:0);//세로
            if(i && j && !map[i-1][j] && !map[i][j-1])
                vec[i][j][1] += vec[i-1][j-1][0] + vec[i-1][j-1][1] + vec[i-1][j-1][2];

        }
    }

    cout << vec[n-1][n-1][0] + vec[n-1][n-1][1] +vec[n-1][n-1][2];
}