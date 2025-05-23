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

    map<string,int> mp;
    int n; cin >> n;
    string s;
    while(cin >> s) mp[s]++;
    vector<pair<string,int>> vec;
    for(auto &i:mp) vec.push_back({i.X,i.Y});
    sort(vec.begin(),vec.end(),[](pair<string,int> &a, pair<string,int> &b){
        if(a.Y==b.Y) return a.X < b.X;
        return a.Y > b.Y;
    });
    for(auto &i:vec) cout << i.X << ' ' << i.Y-1 << '\n';    
}