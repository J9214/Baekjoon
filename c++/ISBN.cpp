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
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO

    string str;cin >> str;
    int s = 0, f;
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == '*') f = i;
        else s += (str[i]-'0') * ((i % 2) ? 3 : 1);
    }
    for(int i = 0 ; i < 10; i++){
        if(!(s % 10) || !((s + i * (f % 2 ? 3 : 1)) % 10)){
            cout << i;
            break;
        }    
    }
}