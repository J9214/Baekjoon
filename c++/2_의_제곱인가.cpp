#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
    double n; cin >> n;
    if(log2(n) == floor(log2(n))) cout << 1;
    else cout << 0;
}