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

    int n, m; 
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vi v1, v2;
        for(int i = 0 ; i < n; i++){
            int a; cin >> a;
            v1.push_back(a);
        }
        for(int i = 0 ; i < m; i++){
            int a; cin >> a;
            v2.push_back(a);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int i = 0, j = 0;
        int res =0;
        while(i < n && j < m){
            if(v1[i] == v2[j]){
                res++;
                i++; j++;
            }
            else if(v1[i] < v2[j]) i++;
            else j++;
        }
        cout << res << '\n';
    }
}