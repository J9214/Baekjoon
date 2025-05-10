#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n ; i++) cin >> s[i];
    int i=0,d=0;
    for(int j = 1 ; j < n ; j++){
        if(s[j-1] < s[j]) i++;
        else if(s[j-1] > s[j]) d++;
    }
    if(i == n-1) cout << "INCREASING";
    else if(d == n-1) cout << "DECREASING";
    else cout << "NEITHER";
}