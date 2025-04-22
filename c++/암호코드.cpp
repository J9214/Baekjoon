#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    string str; cin >> str;
    vi vec(str.size()+1, 0);
    vec[0] = 1;
    for(int i = 0 ; i < str.size(); i++){
        if(str[i]-'0') vec[i+1] = vec[i];
        if(i && str[i-1]-'0'&& stoi(str.substr(i-1,2))<27) vec[i+1] = (vec[i+1]+vec[i-1])%1000000;
    }
    cout << vec[str.size()];
}