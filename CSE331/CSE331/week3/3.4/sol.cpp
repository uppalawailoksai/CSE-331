#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin>>tt;
	while(tt--){
	    int r;
	    cin>>r;
	    vector<vector<int>> v(r+1);
	    priority_queue<pair<int,int>>pq;
	    int arr[r+1];
	    for(int x=1; x<=r; x++){
	        cin>>arr[x];
	        pq.push({arr[x],x});
	    }
	    for(int x=0; x<r-1; x++){
	        int p,q;
	        cin>>p>>q;
	        v[p].push_back(q);
	        v[q].push_back(p);
	    }
	    for(int x=1; x<=r; x++){
	        map<int,int> m;
	        for(auto it:v[x]){
	            m[it]++;
	        }
	        m[x]++;
	        vector<pair<int,int>> temp;
	        
	        while(!pq.empty() && m[pq.top().second]){
	            temp.push_back(pq.top());
	            pq.pop();
	        }
	        if(pq.empty()){
	            cout<<"0 ";
	        }else{
	            cout<<pq.top().second<<" ";
	        }
	        for(auto it:temp){
	            pq.push(it);
	        }
	    }
	    
	}
}
