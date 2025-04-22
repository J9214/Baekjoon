#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int n , b, a; cin >> n >> b >> a;
    
    vector<int> vec(n);
    
    for(int i = 0; i < n ; i++)
        cin >> vec[i];
    
    sort(vec.begin(),vec.end());
    
    int c=0;
    
    for(int i = 0;  i < n; i++){
        if(b >= vec[i]) {
            b-= vec[i];
            c++;
        }
        else if (b >= vec[i]/2 && a){
            b-=vec[i]/2;
            a--;
            c++;
        }
    }
    cout << c;
}