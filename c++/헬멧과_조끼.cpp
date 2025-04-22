#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int n,m;cin>>n>>m;
    int a=0,b=0;
    while(n--){
        int d; cin >> d;
        a = max(d,a);
    }
    while(m--){
        int d; cin >> d;
        b = max(d,b);
    }
    cout << a+b;
}