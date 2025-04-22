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

struct comp {
    bool operator()(pair<string, int> &a, pair<string,int> &b){
        if(a.second == b.second) return a>b;
        return a.second<b.second;
    }
};
int main(){
    FASTIO

    int n; cin >> n;
    priority_queue<pair<string, int>,vector<pair<string,int>>,comp> pq;
    map<string,int> m;
    while(n--){
        string str; cin >> str;
        m[str]++;
    }
    for(auto i = m.begin() ; i != m.end(); i++)
        pq.push({i->first, i->second});
    cout<<pq.top().first;
}