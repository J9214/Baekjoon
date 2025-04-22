#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
#define modulo 1000000007

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];

int lis(int start){
    int& ret = cacheLen[start + 1];
    if(ret != -1) return ret;

    ret = 1;
    for(int next = start + 1; next< n; ++next)
        if(start == -1 || S[start] < S[next])
            ret = max(ret, lis(next) + 1);

    return ret;
}

int count(int start){
    if(lis(start) == 1) return 1;
    int &ret = cacheCnt[start + 1];
    if(ret != -1)return ret;
    ret = 0;
    for(int next = start + 1; next< n; ++next)
        if((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
            ret = min<ll>(MAX, (ll)ret + count(next));
    
    return ret;
}

void reconstruct(int start, int skip, vector<int>& lis){
    if(start != -1) lis.push_back(S[start]);
    vpi followers;
    for(int next = start + 1; next < n; ++next)
        if((start == -1 || S[start] < S[nexst]) && lis3(start) == lis3(next) + 1)
            follower.push_back(make_pair(S[next]. next));
    sort(followers.begin(), followers.end());
    for(int i = 0 ; i < followers.size(); ++i){
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt <= skip) skip -= cnt;
        else{
            reconstuct(idx, skip, lis);
            break;
        }
    }
}

int main(){
    FASTIO


}