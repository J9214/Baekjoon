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

string plus_(string a, string b){
    
    for(int )
    if(a.size()<b.size()) swap(a,b);
    for(int i = 1 ; i <= b.size(); i++){
        a[a.size()-i] += b[b.size()-i] - '0';
        if(a[a.size()-i] > '9') {
            a[a.size()-i] - 10;
            if(i == a.size()) a = "1" + a;
            else a[a.size() - i -1]++;
        }
    }
    return a;
}
string minus_(string a, string b){
    if(a.size()<b.size()) swap(a,b);
    for(int i = 1 ; i <= b.size(); i++){
        a[a.size()-i] += b[b.size()-i];
        if(a[a.size()-i] > '9') {
            a[a.size()-i] - 10;
            if(i == a.size()) a = "1" + a;
            else a[a.size() - i -1]++;
        }
    }
    return a;
}
string mul_(string a, string b){
    
}
int main(){
    FASTIO

    string a,b;cin >> a >> b;
    cout << plus_(a,b);
}