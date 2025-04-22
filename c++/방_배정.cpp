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

    int n, m; cin >> n >> m;
    vvi vec(7, vi(2, 0));

    while(n--){
        int a, b; cin >> a >> b;
        vec[b][a]++;
    }

    int s= 0;
    for(int i = 1; i < 7; i++){
        for(int j = 0; j < 2; j++){
            s += int(ceil(double(vec[i][j]) / m));
        }
    }
    cout << s;
}