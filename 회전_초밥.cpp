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

    int n, m, k, l; cin >> n >> m >> k >> l;
    vi vec(n); 
    vi type(m+1,0);
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i];
    for(int i = 0 ; i < k-1 ; i++)
        vec.push_back(vec[i]);
    type[l]++;
    int c = 0, t = 1, res = 0;
    for(int i = 0 ; i< vec.size() ; i++){
        type[vec[i]]++;
        if(type[vec[i]]==1) t++;
        c++;
        if(c>k){
            type[vec[i-k]]--;
            if(type[vec[i-k]]==0) t--;
            c--;
        }
        res = max(res,t); 
    }
    if(n<k) cout <<res-1;
    else cout << res;
}