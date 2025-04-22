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
void print(vector<vector<char>> mat){for(auto i : mat){for(auto j : i) cout << j;}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    string str; cin >> str;
    int n = str.size();
    int c = 0,r = 0;
    for(int i = 1; i <= str.size(); i++){
        if(!(str.size()%i)){
            if(i>str.size()/i)break;
            else {
                r=i;
                c=str.size()/i;
            }
        } 
    }  
    vector<vector<char>> vec(r,vector<char>(c));
    int k=0;
    for(int i = 0; i < c; i++)
        for(int j = 0 ; j < r; j++)
            vec[j][i] = str[k++];
    
    print(vec);
    

}