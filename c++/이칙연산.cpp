#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    double a,b,c;cin>>a>>b>>c;
    cout<<int(max(a*b/c,a/b*c));
}