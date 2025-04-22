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

void male(vi &vec, int n){
    for(int i =n; i < vec.size() ; i+=n+1)
        vec[i] = !vec[i];
}
void female(vi &vec, int n){
    for(int i = 0; n+i < vec.size() && n-i >= 0; i++)
        if(vec[n+i]==vec[n-i]){
            if(!i) vec[n+i] = !vec[n+i];
            else vec[n+i]=vec[n-i] = !vec[n+i];
        }
        else return;
}
int main(){
    FASTIO

    int n; cin >> n;
    vi vec(n);
    for(int i = 0 ; i < n ; i++) cin >> vec[i];

    int m; cin >> m;
    while(m--){
        int d,t ; cin >> d>>t;
        if(d==1) male(vec, t-1);
        else female(vec, t-1);
    }
    for(int i = 0; i < n ; i++){
        if(i&&!(i%20)) cout << '\n';
        cout << vec[i] << ' ' ;
    }
}