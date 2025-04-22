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
    string str1, str2; cin >> str1 >> str2;
    
    vvi vec(str1.size() + 1, vi(str2.size() + 1 , 0));
    for(int i = 3 ; i <= str1.size(); i+=3){
        for(int j = 3 ; j <= str2.size() ; j+=3){
            if(str1[i-3] == str2[j-3] && str1[i-2] == str2[j-2] && str1[i-1] == str2[j-1]) vec[i][j] = vec[i-3][j-3] + 1;
            else vec[i][j] = max(vec[i-3][j], vec[i][j-3]);
        }
    }
    cout << vec[str1.size()][str2.size()];
}