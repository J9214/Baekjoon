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
void print(vpi vec){for(auto i : vec) cout << i.X << ' ' << i.Y << '\n';}
#define modulo 1000000007

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    vpi vec;
    for(int i = 0 ; i < n ; i++){
        int a=0,b=0;
        for(int j = 0 ; j < m ; j++){
            char c; cin >> c;
            if(c-'0' > 0 && c-'0' < 10){
                a = c-'0';
                b = m-j;
            }
        }
        if(a!=0) vec.push_back({b,a});
    }
    sort(vec.begin(), vec.end());
    vi rank(10,0);
    int r = 1;
    for(int i = 0; i < vec.size(); i++){
        if(i && vec[i-1].X != vec[i].X) r++;
        rank[vec[i].Y]=r;
    }
    for(int i = 1 ; i < rank.size(); i++) cout << rank[i] << '\n';
}