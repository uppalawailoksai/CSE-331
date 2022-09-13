#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,z;
    cin>>n>>z;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    int count=0;
    while(!pq.empty() and z>0)
    {
        int a=pq.top();
        pq.pop();
        z-=a;
        a/=2;
        count++;
        if(a!=0)
            pq.push(a);
    }
    if(z>0)
    cout<<"Evacuate"<<endl;
    else
    cout<<count<<endl;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}