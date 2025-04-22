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

int main(){
    FASTIO

    string s; cin >> s;
    int n; cin >> n;
    list<char> lt;
    for(char c : s) lt.push_back(c);
    auto idx = lt.end();

    while(n--){
        char c; cin >> c;
        if(c == 'L') {
            if(idx != lt.begin()) idx--;
        }
        else if(c == 'D'){
            if(idx != lt.end()) idx++;
        }
        else if(c == 'B'){
            if(idx != lt.begin()){
                idx--;
                idx = lt.erase(idx);
            }
        }
        else {
            char t; cin >> t;
            lt.insert(idx, t);
        }
    }
    for(char c : lt) cout << c;
}