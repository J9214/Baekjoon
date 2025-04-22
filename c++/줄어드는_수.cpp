#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int c=1,n;
string s;
void func(int i, int l){
    if(c > n  || (l && !i)) return;
    if(n == c) s.push_back(i);
    if(!l){
        c++;
        return;
    }
    for(int j = 0 ; j < i; j++)
        func(j,l-1);
    
}

int main() {
    //FASTIO
    
    int i=0;cin >> n;
    // if(n < 10) {
    //     cout << n-1;
    //     return 0;
    // }

    while(1){
        if(c > n) break;

        for(int j = 0 ; j < 10; j++){
            //if(n == c) cout << j;
            func(j,i);
        }
        i++;
    }
    for(int i = s.size()-1; i >= 0; i--)
        cout << s[i];
    
}