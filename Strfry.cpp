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

    while(n--){
        vi vec1(26,0), vec2(26,0);
        string a, b; cin >> a >> b;
        bool f = true;
        for(int i = 0 ; i< a.size(); i++) vec1[a[i] - 'a']++;
        for(int i = 0 ; i< b.size(); i++) vec2[b[i] - 'a']++;
        for(int i = 0 ; i< vec1.size(); i++) 
            if(vec1[i] != vec2[i]) f = false;
        if(f) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    
    
}