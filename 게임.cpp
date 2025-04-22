#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
int main(){
    FASTIO

    ll n,m;cin >> n >> m;
    ll z = (m*100)/n;
    if(z>=99) cout << -1;
    else {
        if((n*z+n-100*m)%(99-z))cout << (n*z+n-100*m)/(99-z)+1; 
        else cout << (n*z+n-100*m)/(99-z);
    }
}