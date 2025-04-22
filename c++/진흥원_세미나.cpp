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
    int n; cin >> n;
    while(n--){
        string str; cin >> str;
        if(str == "Algorithm") cout <<	204;
        else if(str == "DataAnalysis")	cout <<207;
        else if(str == "ArtificialIntelligence")	cout <<302;
        else if(str == "CyberSecurity")	cout <<"B101";
        else if(str == "Network")cout <<	303;
        else if(str == "Startup")	cout <<501;
        else if(str == "TestStrategy")	cout <<105;
        cout <<'\n';
    }
}