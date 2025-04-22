#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;

point direction[3] = {{1,0},{0,1},{1,1}};

vi arr(3);
vvi vec(2188, vi(2188));
int n;
bool check(int x, int y, int d){
    int c = vec[x][y];

    for(int i = x ; i < x + d; i++)
        for(int j = y ; j < y + d; j++)
            if(vec[i][j] != vec[x][y]) return false;
            
    return true;
}

void paper(int x, int y, int d){
    if(check(x, y, d)) 
        arr[vec[x][y] + 1]++;
    else {
        for(int i = 0 ; i < 3; i++)
            for(int j = 0 ; j < 3; j++)
                paper(x + (d / 3) * i, y + (d / 3) * j, d / 3);
    }
}
int main(){
    FASTIO
    cin >> n;

    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < n; j++)
            cin >> vec[i][j];
        
    paper(0,0,n);

    for(int i = 0 ; i < 3; i++)
        cout << arr[i] << '\n';
    
    return 0;
}