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
    vi vec(n);
    vi fr, ba;
    vvi res(2,vi(n));
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i];
    
    for(int i = 0; i < n ; i++){
        // fr
        auto fr_d = lower_bound(fr.begin(), fr.end(), vec[i]);
        if(fr_d==fr.end())fr.push_back(vec[i]);
        else *fr_d = vec[i];

        // ba
        auto ba_d = lower_bound(ba.begin(), ba.end(), vec[n-i-1]);
        if(ba_d==ba.end()) ba.push_back(vec[n-i-1]);
        else *ba_d = vec[n-i-1];

        res[0][i] = fr.size();
        res[1][n-i-1] = ba.size();
    }
    int m_=0;
    for(int i = 0; i  < n ; i++) m_ = max(m_,res[0][i]+res[1][i]-1);
    cout << m_;
}