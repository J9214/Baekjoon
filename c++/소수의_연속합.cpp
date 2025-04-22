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

    ll n; cin >> n;
    vector<bool> vec(4000001,0);
    vector<ll> sosu;
    sosu.push_back(2);
    for(ll i = 3 ; i <= n ; i += 2){
        if(vec[i]) continue;
        ll j = i;
        sosu.push_back(i);
        while(j < 4000001){
            vec[j] = 1;
            j += i;
        }
    }

    ll s= sosu[0];
    ll c= 0;
    ll i=0, j =0;
    while(j < sosu.size()){
        if(s <= n) {
            if(s == n) c++;
            j++;
            s += sosu[j];
        }
        else if(s > n){
            s -= sosu[i];
            i++;
        }
    }
    cout << c;
}