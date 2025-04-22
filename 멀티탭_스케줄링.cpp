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

    int n, m; cin >> n >> m;
    vi vec(m);
    vi arr(m+1,0);
    int a = 0, c= 0, t=0;
    for(int i =0  ; i  < m ; i++) {
        cin >> vec[i];
        arr[vec[i]]++;
        if(arr[vec[i]]==1)t++;
    }
    for(int i = 0 ; i < m-n ; i++){
        arr[vec[i]]--;
        if(arr[vec[i]]==0){
            t--;
            if(t>=n) c++;
        }
    }
    // for(int i = 0 ; i < m; i++){
    //     arr[vec[i]]++;
    //     if(i>=n+1){
    //         arr[vec[i-n-1]]--;
    //         if(!arr[vec[i-n-1]]) c++;
    //     }
    // }
    // if(m-n >= 0 && arr[vec[m-n]]==1) c++;
    // for(int i =0  ; i  < m ; i++){
    //     arr[vec[i]]++;
    //     if(i-n-n-1>=0){
    //         int idx = vec[i-n-n-1];
    //         arr[idx]--;
    //         if(!arr[idx]) c++;
    //     }
    // }
    // for(int i = m-n-n; i < m-n; i ++){
    //     if(i >= 0){
    //         int idx = vec[i];
    //         arr[idx]--;
    //         if(!arr[idx]) c++;
    //     }
    // }

    cout << c;
    
}