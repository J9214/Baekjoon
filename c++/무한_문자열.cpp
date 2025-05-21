#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    string a,b; cin >> a >> b;
    string c, d;
    for(int i = 0 ; i< a.size(); i++) c += b;
    for(int i = 0 ; i< b.size(); i++) d += a;
    if(c==d) cout << 1;
    else cout << 0;
}