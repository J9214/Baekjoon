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
        for(int j =1 ; j < n ; j++){
            int d; cin >> d;
            map[i][j] = d;
            if(d) continue;

            vec[i][j][0] += vec[i][j-1][0] + vec[i][j-1][1] + (i?vec[i-1][j][1]:0); // 가로
            vec[i][j][2] += (i?vec[i-1][j][1]:0) + (i?vec[i-1][j][2]:0);//세로
            if(i && map[i-1][j]==0 && map[i][j-1]==0)
                vec[i][j][1] += vec[i-1][j-1][0] + vec[i-1][j-1][1] + vec[i-1][j-1][2];

        }
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cout << vec[i][j][0] + vec[i][j][1] +vec[i][j][2] << ' ';
        }
        cout << '\n';
    }
    cout << vec[n-1][n-1][0] + vec[n-1][n-1][1] +vec[n-1][n-1][2];
}

// 0 1 1 1 1 1 
// 0 0 0 1 2 3 
// 0 0 0 1 2 4 
// 0 0 0 1 3 6 
// 0 0 0 1 4 9 
// 0 0 0 1 5 13 
// 13

// 1 1 1 1 1 1 
// 0 0 0 1 2 3 
// 0 0 0 1 2 5 
// 0 0 0 1 3 7 
// 0 0 0 1 3 10 
// 0 0 0 1 4 12 
// 12

// 0 1 1 1 1 1 1 
// 0 0 1 2 3 4 5 
// 0 0 1 2 4 0 1 
// 0 0 1 3 6 3 4 
// 0 0 1 4 0 0 1 
// 0 0 1 5 1 1 2 
// 0 0 1 6 6 7 9 
// 9

// 1 1 1 1 1 1 0 
// 0 0 1 2 3 4 5 
// 0 0 1 2 5 0 1 
// 0 0 1 3 7 3 3 
// 0 0 1 3 0 0 1 
// 0 0 1 4 2 1 2 
// 0 0 1 4 6 6 8 
// 8