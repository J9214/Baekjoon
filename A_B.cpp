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
void print(string str){for(int i = str.size()-1; i>=0; i--) cout << str[i];}
#define modulo 1000000007

int main() {
    FASTIO
    
    string str1, str2, res; cin >> str1 >> str2;
    int i=str1.size()-1, j=str2.size()-1;
    int u=0;
    while(i >= 0 || j >= 0){
        int d = 0;
        if(i>=0) d += str1[i--]-'0';
        if(j>=0) d += str2[j--]-'0';
        if(u){
            d+=u;
            u=0;
        }
        if(d>=10) u = d/10;
        if(i==-1&&j==-1) {
            string t =to_string(d);
            for(int k = t.size()- 1; k>=0 ; k--) res+=t[k];
        }
        else{
            d%=10;
            res+=to_string(d);
        }
    }
    print(res);
}