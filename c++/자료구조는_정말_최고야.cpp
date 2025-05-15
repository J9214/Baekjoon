#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    while(m--){
        int t; cin >> t;
        int prev = INT_MAX;
        while(t--){
            int a; cin >> a;
            if(a > prev) {cout << "No"; return 0;}
            prev = a;
        }
    }
    cout << "Yes";

}