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

    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        while(n){
            if(n>=5){cout << "++++ "; n-=5;}
            else if(n==4){cout << "||||"; n-=4;}
            else if(n==3){cout << "|||"; n-=3;}
            else if(n==2){cout << "||"; n-=2;}
            else if(n==1){cout << "|"; n-=1;}
        }
        cout << '\n';
    }
}