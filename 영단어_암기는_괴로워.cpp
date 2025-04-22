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

    map<string, int> map;

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        if(str.size() >= m) map[str]++;
    }

    vector<pair<string, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), [](pair<string, int> &a, pair<string, int> &b){
        if(a.second != b.second) return a.second > b.second;
        else if(a.first.size() != b.first.size()) return a.first.size() > b.first.size();
        else return a.first < b.first;
    });

    for(int i =0 ;  i < vec.size(); i++){
        cout << vec[i].first << '\n';
    }
}