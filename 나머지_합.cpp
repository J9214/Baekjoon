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

    ll n, m; cin >> n >> m;
    vll vec(n + 1, 0);
    vll res(n + 1, 0);
    for(int i = 1 ; i<= n; i++){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    
    ll c = 0;
    for(int i = 0 ; i <= n ; i++)
        for(int j = i + 1; j <= n; j++)
            if(!((vec[j] - vec[i]) % m)) c++;

    cout << c;
}