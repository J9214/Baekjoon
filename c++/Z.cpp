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
point direction[4] = {{0,0},{0,1},{1,0},{1,1}};
#define modulo 1000000007

int p, q, c = 0;
bool flag = false;
void quad(int x, int y, int d){
    if(flag) return;
    if(d > 2) {
        int tmp = log2(d);
        int dxy = 2 << (tmp - 2);
        int cy = pow(4,tmp - 1);
        int cx = cy << 1;
        d >>= 1;
        if(p >= x + dxy && q >= y + dxy){
            c += cx + cy;
                quad(x + dxy, y + dxy, d);
        }
        else if(p >= x + dxy && q < y + dxy){
            c += cx;
            quad(x + dxy, y, d);    
        }
        else if(p < x + dxy && q >= y + dxy){
            c += cy;
            quad(x, y + dxy, d);
        }
        else quad(x, y, d);
     
    }
    else {
        for(int i = 0; i < 4; i++){
            int a, b;
            a = x + direction[i].x;
            b = y + direction[i].y;

            if(a == p && b == q) {
                cout << c;
                flag = true;
            }
            
            c++;
        }
    }
}

int main(){
    FASTIO
    
    int n; cin >> n >> p >> q;
    
    n = 2 << (n - 1);
    quad(0,0,n);
}