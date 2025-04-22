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
void print(string vec){for(auto i : vec) cout << i;}
#define modulo 1000000007

int main(){
    FASTIO

    string str; cin >> str;
    int n=0,b;
    for(char c : str)
        n += c-'0';
    if(str.find('0') < str.size() && !(n%3)){
        sort(str.rbegin(),str.rend());
        print(str);
    }
    else cout << -1; 
}