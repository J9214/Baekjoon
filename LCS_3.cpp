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
    
    string str1,str2,str3; cin >> str1 >> str2 >> str3;   
    vector<vector<vector<int>>> vec(str1.size() + 1, vector<vector<int>>(str2.size() + 1, vector<int>(str3.size() + 1, 0)));

    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            for(int k = 1; k <= str3.size(); k++){
                if(str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
                    vec[i][j][k] = vec[i-1][j-1][k-1] + 1;
                else vec[i][j][k] = max(vec[i-1][j][k], max(vec[i][j-1][k], vec[i][j][k-1]));
                
            }
        }
    }
    cout << vec[str1.size()][str2.size()][str3.size()];
}