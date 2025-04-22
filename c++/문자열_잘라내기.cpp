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

    int n, m ; cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> mat[i][j];
    
    vector<string> vec;
    for(int i = 0 ; i < m ; i++){
        string s="";
        for(int j = n-1;  j>=0 ; j --)
            s+=mat[j][i];
        vec.push_back(s);
    }

    sort(vec.begin(), vec.end());
    int res=0;
    for(int i = n ; i > 0; i--){
        for(int j = 0; j < vec.size()-1; j++){
            if(vec[j].substr(0,i) == vec[j+1].substr(0,i)){
                cout << res;
                return 0;
            }
        }
        if(i<n) res++;
    }
    cout << res;
}