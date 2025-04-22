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
#define modulo 1000000007

int main(){
    FASTIO
    
    int t; cin >> t;
    while(t--){
        int n, w; cin >> n >> w;
        vvi vec(n, vi(n));
        for(int i = 0 ; i < 2 ; i++)
            for(int j =0 ; j < n ; j++)
                cin >> vec[i][j];
        for(int i = 0 ; i < 2 ; i++){
            for(int j =0 ; j < n ; j++){
                int r = vec[i][j], d = 0;
                if(j == n - 1) r += vec[i][0];
                else r = vec[i][j] + vec[i][j + 1];

            }
        }

    }
}