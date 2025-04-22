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

    int t; cin >> t;
    vi vec(10001);
    for(int i = 0 ; i < vec.size(); i++) vec[i] = i;
    for(int i = 2 ; i < 10001; i++)
        for(int j = i * 2; j<10001; j+=i) vec[j] = 0;
    
    while(t--){
        int n; cin >> n;
        int a=0,b=10000;
        for(int i = 2 ; i <= n / 2; i++){
            if(vec[i] && vec[n-i])
                if(b-a > (n-2*i)){
                    a=i;
                    b=n-i;
                }
        }
        cout << a << ' ' << b << '\n';
    }
}