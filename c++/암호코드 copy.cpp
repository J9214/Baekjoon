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

bool failed(string &str, int i){
    if(str[i-1]-'0'>2 && str[i]=='0' || str[0] == '0') return 1;
    if(str[i-1] == '0' && str[i] =='0') return 1;
    return 0;
}
bool check(string &str, int i){
    if(str[i-1]=='0')return 0;
    if(str[i-1]-'0'>2) return 0;
    if(str[i-1]-'0'>=2 && str[i]-'0' >6) return 0;
    return 1;
}
int main(){
    FASTIO

    string str; cin >> str;
    vi vec(str.size()+1, 0);
    if(str == "0") {
        cout << 0;
        return 0;
    }
    vec[0] =vec[1]= 1;
    for(int i = 1 ; i< str.size() ; i++){
        
        if(failed(str,i)) {
            cout << 0;
            return 0;
        }
        if(str[i] == '0') vec[i+1] = vec[i-1];
        else {
            vec[i+1] = vec[i];
            if(check(str,i)) vec[i+1] += vec[i-1];
            vec[i+1] = (vec[i+1] + 1000000)%1000000;
        }
        
    }
    cout << vec[str.size()];
}