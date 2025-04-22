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

    vi vec(100001,0);

    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        int res = INT_MAX;
        if(!(i % 3)) res = min(res, vec[i / 3] + 1);
        if(!(i % 2)) res = min(res, vec[i / 2] + 1);
        res = min(res, vec[i - 1] + 1);

        vec[i] = res;
    }

    cout << vec[n];
}