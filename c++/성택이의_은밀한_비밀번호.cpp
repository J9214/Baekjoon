#include<bits/stdc++.h>

using namespace std;

int main(){
    int t ;cin >>t;
    while(t--){
        string s; cin>>s;

        if(s.size()<6||s.size()>9) {cout << "no\n";continue;}
        bool f=0;
        for(auto i : s) if((i-'0') < 0 || (i-'0')>9) {
        
            f=1;
            }

        if(!f)cout << "yes\n";
        else cout << "no\n";
    }
}