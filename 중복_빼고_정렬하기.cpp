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

    int n; cin >> n;
    vi vec(n);
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i];
        
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()),vec.end());
    
    for(int i = 0; i < vec.size() ; i++)
        cout << vec[i] << ' ';
}