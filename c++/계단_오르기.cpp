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

    vpi vec(n);

    for(int i =0 ; i < n ; i++){
        int d; cin >> d;
        vec[i] = {d, 0};
    }
        
    for(int i =0 ; i < n; i++){
        if(i + 1 < n && vec[i].second < 2) {
            if(vec[i + 1].first < vec[i + 1].first + vec[i].first) 
                vec[i + 1] = {vec[i + 1].first + vec[i].first, vec[i].second + 1};
        }
        if(i + 2 < n && vec[i + 2].first < vec[i + 2].first + vec[i].first) {
            vec[i + 2] = {vec[i + 2].first + vec[i].first, 0};
        }
    }

    cout << vec[n - 1].first;
}   