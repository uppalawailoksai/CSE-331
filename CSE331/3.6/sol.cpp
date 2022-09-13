#include <bits/stdc++.h>
using namespace std;

    int node,limit;
    
    vector<vector<pair<int,int>>> grap;
    vector<int> cnt;
    priority_queue< int > maxHeap;
int helper(int ind,vector<int> &cnt,int parent) {
    int j = 0;
    for(auto &val : grap[ind]) {
        if(val.first != parent) {
            j += helper(val.first,cnt,ind);
            
        }
        
    }
    return cnt[ind] = j+1;
}
void helper1(int node,int par){
    for(auto val : grap[node] ){
        if( val.first!=par ){
            if( val.second )
                maxHeap.push(cnt[val.first]);
            else
                helper1(val.first,node);
        }
    }
}
int main() {
    int t;
    cin>>t;
    
    
    while(t--) {
        while(!maxHeap.empty()) maxHeap.pop();
        cin>>node>>limit;
        grap = vector<vector<pair<int,int>>> (node+1);
        
        for(int i=1;i<node;i++) {
            int u,v,wt;
            cin>>u>>v>>wt;
            
            grap[u].push_back({v,wt});
            grap[v].push_back({u,wt});
        }
        cnt = vector<int> (node+1);
        
        helper(1,cnt,0);
        helper1(1,0);
        int ans = node,t=0;
        while( ans>limit && !maxHeap.empty() ){
            ans -= maxHeap.top();maxHeap.pop();t+=1;
        }
        if( ans>limit ){
            cout<<-1<<"\n";
        }else{
            cout<<t<<"\n";
        }
    }
    
	return 0;
}
