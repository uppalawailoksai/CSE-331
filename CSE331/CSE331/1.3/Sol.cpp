#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
int n,a=0,b=0,x,y,z;
	    int q;
	    int count=0;
	    bool wrong=false;
	    priority_queue<int>pq;
	    cin>>n>>a>>b>>x>>y>>z;
	    for(int i=0;i<n;i++)
	    {   cin>>q;
	        pq.push(q);
	    }
	    
	   int hooli=z-b;
	   int days=hooli/y;
	   int pep=(days*x)+a;
	   
	    while(pep<z)
	    {
	        int t=pq.top();
	        pq.pop();
	        count++;  
	        pep=pep+t;
	        t=t/2;
	        if(t/2<=0){
	         wrong=true;
	         break;
	        }
	        pq.push(t);
	    }
	    if(wrong)
	   { cout<<"RIP"<<"\n";}
	    else
	    {cout<<count<<"\n";}
	}
	
	
int32_t main(){
    int tc=1;cin>>tc;
    while(tc--){
      //cout<<"Case #"<<cse++ <<":"<<" ";        
        solve();
    }
}
