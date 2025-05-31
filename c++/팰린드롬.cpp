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

int palindrome(string s){
    for(int i = 0 ; i<s.size()/2;i++)
        if(s[i] != s[s.size()-1-i]) return 0;
    return 1;
}

string func(int n, vector<string> &vec){
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0; j < n ; j++){
            if(i==j) continue;
            if(palindrome(vec[i]+vec[j])) return vec[i]+vec[j];
        }
    }
    return "";
}
int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        vector<string> vec(n);
        for(int i = 0 ; i < n ; i++) cin >> vec[i];
        
        string res = func(n,vec);
        if(res=="") cout <<0 << '\n';
        else cout << res << '\n';
    }
}