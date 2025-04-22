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

int button(vi &vec, int n, int p){
    int t=n;
    bool f=0;
    while(n>=0 && n <= 1000000){
        string s = to_string(n);
        f=0;
        for(int i=0; i < s.size(); i++){
            for(int j = 0 ; j < vec.size() ; j++){
                if(vec[j]==s[i]-'0'){
                    f=1;
                    break;
                }
            }
        }
        if(!f) return abs(t-n)+to_string(n).size();
        n+=p;
    }
    return INT_MAX;
}
int main(){
    FASTIO

    int n,m ; cin >> n >> m;
    vi vec(m);
    for(int i = 0 ; i < m; i++) cin >> vec[i];
    int a,b;
    a = button(vec, n, 1);
    b = button(vec, n, -1);

    cout << min(a,min(b,abs(100-n)));
}