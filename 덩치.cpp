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

    int n;cin >> n;
    vvi vec(n,vi(4, 0));
    for(int i= 0 ; i < n; i++){
        int a,b;cin>>a>>b; 
        vec[i][0] = a;
        vec[i][1] = b;
        vec[i][2] = i+1;
    }
    for(int i = 0 ; i < n ; i++){
        int c= 0;
        for(int j = 0 ; j < n ; j++){
            if(vec[j][1] >vec[i][1] && vec[j][0] >vec[i][0]) c++;
        }
        vec[i][3] = c+1;
    }
    for(int i = 0 ; i < n ; i++)
        cout << vec[i][3] << ' ';
}