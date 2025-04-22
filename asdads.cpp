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
    //FASTIO

    int n; cin >> n;
    vector<pair<char, int>> vec;
    vector<pair<char, int>> res;

    while(n--){
        string s; cin >> s;
        
        vec.push_back({s[0], stoi(s.substr(1,s.size()-1))});
    }
    res = vec;

    sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b){
        string order = "BSGPD";

        if(a.first == b.first) return a.second > b.second;
        else {
            return order.find(a.first) < order.find(b.first);
        }
    });

    bool b=false;
    for(int i = 0; i < res.size(); i++){
        if(!b) {
            cout << "KO\n";
            b=true;
        }
        if(vec[i].first != res[i].first || vec[i].second != res[i].second) vec[i].first << vec[i].second << ' ';
    }
    if(!b)cout << "OK";
}