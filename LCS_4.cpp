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
    vector<int> vec1(n),vec2(n);
    vector<vector<int>> vec(n + 1, vi(n + 1, 0));

    for(int i = 0 ; i < n ; i++)
        cin >> vec1[i];
    for(int i = 0 ; i < n ; i++)
        cin >> vec2[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
                if(vec1[i - 1] == vec2[j - 1])
                    vec[i][j] = vec[i-1][j-1] + 1;
                else vec[i][j] = max(vec[i-1][j], vec[i][j- 1]);         
        }
    }

    cout << vec[n][n];
}