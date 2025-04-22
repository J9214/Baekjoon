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

    ll n, m; cin >> n >> m;
    vi vec1(n), vec2(m);
    for(ll i = 0 ; i < n ; i++)
        cin >> vec1[i];
    for(ll i = 0 ; i < m ; i++)
        cin >> vec2[i];        
    vi res(n+m);

    ll i=0,j=0,k=0;
    while(i<vec1.size() || j<vec2.size()){
        if(j>=vec2.size()) while(i<vec1.size()) res[k++] = vec1[i++];
        else if(i>=vec1.size()) while(j<vec2.size()) res[k++] = vec2[j++];
        else if(vec1[i]<=vec2[j]) res[k++] = vec1[i++];
        else res[k++] = vec2[j++];
    }

    print(res);
}