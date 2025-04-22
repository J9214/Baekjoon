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
#define modulo 1000000009

int main(){
    FASTIO

    int t;cin >> t;
    vll vec(1000001,0);
    for(int i = 0 ; i < vec.size() ; i++){
        if(i<=2)vec[i] = i;
        else if(i==3)vec[i]=4;
        else vec[i] = (vec[i-1]+vec[i-2]+vec[i-3])%modulo;
    }

    while(t--){
        int d; cin >> d;
        cout << vec[d] << '\n';
    }
}