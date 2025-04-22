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
    string s,res;cin >>s;
    int d = s.size()%3;
    int i =0;
    while(i<s.size()){
        string str = s.substr(i,d);
        int n=0;
        for(int j=d-1;j>=0;j--)
            if(str[d-1-j]-'0') n+=pow(2,j);
        res+=to_string(n);
        i+=d;
        d=3;
    } 
    if(res.size()>1&&res[0] == '0')res=res.substr(1,res.size()-1);
    cout <<  res;
}