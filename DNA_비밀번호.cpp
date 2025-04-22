#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
    int n, m; cin >> n >> m;
    char str[1000001]; cin >> str;
    int a,b,c,d; cin >> a >> b >> c >> d;
    int arr[26] = {0,};
    int res=0;

    for(int i = 0 ; i < n ; i++){
        arr[str[i]-'A']++;
        if(i-m+1>=0) {
            arr[str[i-m]-'A']--;
            if(arr['A'-'A']>=a && arr['C'-'A']>=b && arr['G'-'A']>=c && arr['T'-'A']>=d) res++;
        }
    }
    cout << res;
}