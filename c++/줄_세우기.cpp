#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    int n;cin>>n;
    vi res(n+1,0);
    int d,m=0;
    for(int i = 0 ; i < n ; i++){
        cin >> d;
        res[d] = res[d-1]+1;
        m=max(m,res[d]);
    }
    cout <<n- m;
}