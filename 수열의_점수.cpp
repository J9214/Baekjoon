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
    priority_queue<ll> pqP;
    priority_queue<ll,vll,greater<ll>> pqN;

    ll n; cin >> n;
    while(n--){
        ll d; cin >> d;
        if(d>0)pqP.push(d);
        else pqN.push(d);
    }
    ll s= 0;
    while(!pqP.empty()){
        ll a, b;
        a=pqP.top();
        pqP.pop();
        if(pqP.empty()) s+=a;
        else {
            b=pqP.top();
            pqP.pop();
            if(a * b > a + b) s+=a*b;
            else s+=a+b;
        }
    }
    while(!pqN.empty()){
        ll a, b;
        a=pqN.top();
        pqN.pop();
        if(pqN.empty()) s+=a;
        else {
            b=pqN.top();
            pqN.pop();
            if(a * b > a + b) s+=a*b;
            else s+=a+b;
        }
    }
    cout << s;
}