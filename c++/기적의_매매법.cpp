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
    int b=n,t=n;
    int b_c=0,t_c=0;
    int d_l=0,d_u=0,prev;
    int d; 

    for(int i = 0; i < 14 ; i++){
        cin >> d;
        b_c+=b/d;
        b%=d;

        if(i){
            if(d>prev) {d_u++;d_l=0;}
            if(d<prev) {d_l++;d_u=0;}
        }
        if(d_l>=3){
            t_c+=t/d;
            t%=d;
        }
        if(d_u>=3) {
            t+=d*t_c;
            t_c=0;
        }
        
        prev=d;
    }
    t += d*t_c;
    b += d*b_c;

    if(t>b) cout <<"TIMING";
    else if(t<b) cout << "BNP";
    else cout << "SAMESAME";
}