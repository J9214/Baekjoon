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
    int i=0,j=0;
    int _min=INT_MAX,_max=0;
    int res = 0;
    for(int k = 0 ; k < n ; k++){
        int d; cin >> d;
        if(d < _min){
            i = k;
            if(i>j) {
                j = i;
                _max = d;
            }
            _min = d;
        }
        if(d > _max){
            j = k;
            _max = d;
        }

        res = max(_max - _min,res);

        cout << res << ' ';
    }
}