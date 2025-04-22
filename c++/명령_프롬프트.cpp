#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int t; cin >> t;
    t--;
    string str; cin >> str;
    while(t--){
        string str1; cin >> str1;
        for(int i =0 ; i < str1.size(); i++)
            if(str[i] != str1[i]) str[i] = '?';
    }
    cout << str;
        
    return 0;
}