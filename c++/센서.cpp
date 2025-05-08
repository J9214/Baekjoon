#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    int n, k, res = 0; cin >> n >> k; // 센서, 집중국
    vi sensors(n), distance; // 센서 위치, 센서 간 거리
    
    for(int i = 0 ; i < n; i++) cin >> sensors[i];
    sort(sensors.begin(), sensors.end());
    
    for(int i = 1; i < n ; i++) 
        distance.push_back(sensors[i] - sensors[i-1]); // 센서 간 거리 계산
    sort(distance.begin(), distance.end());

    for(int i = 0 ; i < n - k; i++) res += distance[i]; // k개의 집중국을 세워야 하니 집중국 간 빈공간은 k-1개
                                                        // 센서간 거리의 개수는 n-1개
                                                        // 즉 (n-1) - (k-1)개의 센서간 거리의 합의 최솟값을 구함
    cout << res;
}