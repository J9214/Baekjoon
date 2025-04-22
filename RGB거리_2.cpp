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
typedef vector<vector<pair<int, int>>> vvpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
#define modulo 1000000007

vvi vec(3, vi(1001));

int main(){
    FASTIO

    int n; cin >> n;
    
    vvpi rgb(3, vpi(3, {987654321, 5}));

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < 3; j++)
            cin >> vec[j][i];
            
    rgb[0][0] = {vec[0][0], 0};
    rgb[1][0] = {vec[1][0], 1};
    rgb[2][0] = {vec[2][0], 2};

    for(int i = 1 ; i < n ; i++){
        if(i < n - 1){
            if(rgb[1][i-1].first < rgb[2][i-1].first)
                rgb[0][i] = {vec[0][i] + rgb[1][i - 1].first, 1};
            else rgb[0][i] = {vec[0][i] + rgb[2][i - 1].first, 2};

            if(rgb[0][i-1].first < rgb[2][i-1].first)
                rgb[1][i] = {vec[1][i] + rgb[0][i - 1].first, 0};
            else rgb[1][i] = {vec[1][i] + rgb[2][i - 1].first, 2};

            if(rgb[0][i-1].first < rgb[1][i-1].first)
                rgb[2][i] = {vec[2][i] + rgb[0][i - 1].first, 0};
            else rgb[2][i] = {vec[2][i] + rgb[1][i - 1].first, 1};
        }
        else {
            for(int j = 0 ; j < 3; j ++){
                pair<int,int> mv = {INT_MAX, INT_MAX};
                for(int k = 0 ; k < 3; k++){
                    if(rgb[k][n-2].second == j) continue;
                    if(mv.first < rgb[k][n-2].first)
                        mv = {vec[j][i] + mv.first, mv.second};
                    else mv  = {vec[j][i] + rgb[k][n-2].first, rgb[k][n-2].second};
                }
                rgb[j][n-1] = {mv.first, mv.second};
            }
        }
        
    }
    
    cout << min(rgb[0][n - 1].first, min(rgb[1][n - 1].first, rgb[2][n - 1].first));
}