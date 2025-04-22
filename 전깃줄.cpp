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

    int n;cin>>n;
    vpi vec(n);
    for(int i = 0 ; i < n ; i++){
        int a,b;cin>>a>>b;
        vec[i] = {a,b};
    }
    sort(vec.begin(),vec.end(),[](pi a, pi b){   
        return a.first < b.first;
    });
    vi res;
    for(int i = 0 ; i < n ; i ++){
        auto it = lower_bound(res.begin(), res.end(), vec[i].second);
        if(it == res.end()) res.push_back(vec[i].second);
        else *it = vec[i].second;
    }
    cout << n-res.size();

}