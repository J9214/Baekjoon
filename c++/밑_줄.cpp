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
void print(vector<string> vec){for(auto i : vec) cout << i;}
#define modulo 1000000007

int main(){
    FASTIO

    int n,m ; cin >> n >> m;
    vector<string> vec(n);
    int total=m;
    for(int i = 0 ; i < n; i ++) {
        cin >> vec[i];
        total-=vec[i].size();
    }
    int l = total-total/(n-1)*(n-1);
    for(int i = 1; i < vec.size(); i++)
        if(l && vec[i][0]>'_') vec[i] = "_"+vec[i],l--;
    for(int i = vec.size()-1; i>0;i--)
        if(l && vec[i][0]<'_') vec[i] = "_"+vec[i],l--;
    for(int i = 1; i < vec.size(); i++)
        for(int j = 0 ; j < total/(n-1) ; j++) vec[i]="_"+vec[i];
    print(vec);
}