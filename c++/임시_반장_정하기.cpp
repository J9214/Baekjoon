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

    vector<vector<vector<int>>> vec(5,vvi(10));
    int n ; cin >> n;
    vi student(n+1);

    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < 5 ; j++){
            int d; cin >> d;
            vec[j][d].push_back(i+1);
        }

    vvi cnt(n+1);
    for(int i = 0 ; i < 5 ; i ++)
        for(int j = 0 ; j < 10 ; j++){
            if(vec[i][j].size()<=0)continue;
            for(int k = 0 ; k < vec[i][j].size(); k++){
                for(int l= 0 ; l < vec[i][j].size(); l++){
                    if(k==l) continue;
                    cnt[vec[i][j][k]].push_back(vec[i][j][l]);
                }
            }
        }    
    int res=1;
    
    for(int i = 1 ; i < n+1; i++) {
        sort(cnt[i].begin(),cnt[i].end());
        cnt[i].erase(unique(cnt[i].begin(), cnt[i].end()), cnt[i].end());
        if(cnt[res].size() < cnt[i].size()) res = i;
    }

    cout << res;
}
