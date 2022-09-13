#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    unordered_map<ll,ll> mp;
    priority_queue<pair<ll,pair<ll,ll>>> maxh;
    maxh.push({n,{n,n-1}});
    for(ll i=1;i<=k;i++){
    	ll size=maxh.top().first;
    	ll start=n-maxh.top().second.first;
    	ll end=maxh.top().second.second;
    	maxh.pop();
    	if(size%2==1){
    		ll temp=(start+end)/2;
    		mp[temp+1]=i;
    		if(size!=1){
    			maxh.push({size/2,{n-start,temp-1}});
    			maxh.push({size/2,{n-temp-1,end}});
    		}
    	}
    	else {
    		if(s[i-1]=='L'){
    			ll temp=(start+end)/2;
    			mp[temp+1]=i;
    			if(size!=1){
    				if(size==2){
    					maxh.push({1,{n-end,end}});
    				}
    				else {
    					maxh.push({size/2-1,{n-start,temp-1}});
    					maxh.push({size/2,{n-temp-1,end}});
    				}
    			}
    		}
    		else {
    			ll temp=(start+end+1)/2;
    			mp[temp+1]=i;
    			if(size!=1){
    				if(size==2){
    					maxh.push({1,{n-start,start}});
    				}
    				else {
    					maxh.push({size/2,{n-start,temp-1}});
    					maxh.push({size/2-1,{n-temp-1,end}});
    				}
    			}
    		}
    	}
    }
    ll q;
    cin>>q;
    while(q--){
    	ll q1;
    	cin>>q1;
    	if(mp.find(q1)!=mp.end())
    	cout<<mp[q1]<<"\n";
    	else cout<<"-1\n";
    }
}