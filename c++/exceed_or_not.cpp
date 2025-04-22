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

string _mul(string a, string b) {
    int n = a.size(), m = b.size();
    vi vec(n+m,0);

    for(int i = n - 1; i >=0 ; i--){    
        for(int j = m - 1; j >=0; j--){
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + vec[i + j + 1];
            vec[i + j + 1] = sum % 10;
            vec[i + j] += sum / 10;
        }
    }
    string res;
    for(auto s : vec){
        if(!(res.size() && s == 0)){
            res.push_back(s + '0');
        }
    }

    return res.empty() ? "0" : res;
}

int main(){
    FASTIO

    string a,b,c;cin >> a >> b>>c;
    string m = _mul(a,b);
    if(m.size() > c.size()) cout << "overflow";
    else if(m.size() < c.size())cout << m;
    else {
        for(int i = 0 ; i < m.size(); i++){
            if(m[i] > c[i]){
                cout << "overflow";
                return 0;
            }
        }
        cout<<m;
    }
    
}