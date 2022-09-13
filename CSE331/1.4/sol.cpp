
#include<bits/stdc++.h>
using namespace std;
#ifdef KritikPC
#include "debug.h"
#else
#define deb(...)
#endif

/*

*/

void solve(){
    int n;cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    vector<vector<int>>temp(n);
    for(int i=0;i<n;i++){
        temp[a[i].second].push_back(a[i].first);
    }
    double ans=0;
    pair<long long,int>mx={0,0};
    multiset<int,greater<int>>can;
    for(int k=0;k<n;k++){
        for(int i=0;i<(int)temp[k].size();i++){
            can.insert(temp[k][i]);
        }
        if(can.empty()){
            break;
        }
        mx.first+=*can.begin();
        mx.second++;
        can.erase(can.begin());
        ans=max(ans,(mx.first*1.0)/mx.second);
    }
    while(!can.empty()){
        mx.first+=*can.begin();
        mx.second++;
        can.erase(can.begin());
        ans=max(ans,(mx.first*1.0)/mx.second);
    }
    cout << fixed << setprecision(9) << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ttc=1;
    cin>>ttc;
    while(ttc--){
        solve();
    }
}