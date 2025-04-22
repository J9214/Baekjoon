#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};

int main(){
    FASTIO
    
    long long n ; cin >> n;
    vi sugar = {3, 5};
    vll vec(n + 1, 0);
    
    for(int i = 0 ; i < 2; i++){
        for(int j = sugar[i] ; j <= n; j++){
            if(j == sugar[i]) vec[sugar[i]] = 1;
            else if(vec[j - sugar[i]]) {
                if(vec[j]) vec[j] = min(vec[j], vec[j - sugar[i]] + 1);
                else vec[j] = vec[j - sugar[i]] + 1;
            }
        }
    }

    if(vec[n]) cout << vec[n];
    else cout << -1;
    
    return 0;
}