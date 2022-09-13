#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
	    int K,Q;
	    cin>>K>>Q;
	    vector<ll>A(K,0);
	    vector<ll>B(K,0);
	    for(int i=0;i<K;i++) cin>>A[i];
	    for(int i=0;i<K;i++) cin>>B[i];
	    sort(A.begin(),A.end());
	    sort(B.begin(),B.end());
	    priority_queue<ll>pq;
	    for(int i=0;i< min(K,1000);i++){
	        for(int j=0;j<min(K,1000);j++){
	            ll sum = A[i] + B[j];
	            pq.push(sum);
	            if(pq.size() > 10000) pq.pop();
	        }
	    }
	    
	    vector<ll>gs(pq.size(),0);
	    int ind = pq.size()-1;
	    while(!pq.empty()){
	        gs[ind--] = pq.top();
	        pq.pop();
	    }
	    while(Q--){
	        int q;
	        cin>>q;
	        cout<<gs[q-1]<<endl;
	    }
	    
	}
	return 0;
}