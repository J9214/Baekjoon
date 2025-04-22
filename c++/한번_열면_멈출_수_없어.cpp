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
typedef vector<ll> vll;

int main(){
    FASTIO

    int n; cin >> n;
    int ps = 0, pe = 0, s = 0, e = 0, v = 0, pv = 0, total = 0;
    vi vec;
    for(int i = 0 ; i< n ; i++){
            cin >> s >> e;
        
        if(i == 1){
            if(pe <= s) vec.push_back(pe);
            else if (e <= ps) vec.push_back(ps); 
            else {
                if(s <= pe) vec.push_back(pe);
                else vec.push_back(ps);
            }
            
            v = (int)vec.back();
            pv = v;
        }
        if(i){
            if(v <= s) vec.push_back(s);
            else if (v <= ps) vec.push_back(e);
            else vec.push_back(v);    

            v = (int)vec.back();
            total += abs(v - pv);
        }    

        pv = v;
        ps = s;
        pe = e;
    }

    cout << total << '\n';
    for(int i =0  ; i < n ; i++)
        cout << vec[i] << '\n';
    return 0;
}
